#include "ftms_bike_server.h"

#include "esphome/components/esp32_ble/ble.h"
#include "esphome/core/log.h"
#include "esphome/core/application.h"
#include "esphome/core/version.h"

#ifdef USE_ESP32

namespace ftms {
namespace bike_server {

static const char *TAG = "ftms_bike_server";

static const char *DEVICE_INFORMATION_SERVICE_UUID = "180A";
static const char *VERSION_UUID = "2A26";
static const char *MANUFACTURER_UUID = "2A29";


FTMSBikeServer::FTMSBikeServer() { global_ble_server = this; }

void FTMSBikeServer::setup() {
  ESP_LOGD(TAG, "FTMS component setup");

  BLEDevice::init(App.get_name());
  this->server_ = BLEDevice::createServer();
  this->server_->setCallbacks(new ESP32BLEServerCallback());

  BLEService *device_information_service = this->server_->createService(DEVICE_INFORMATION_SERVICE_UUID);
  BLECharacteristic *version = device_information_service->createCharacteristic(
      VERSION_UUID,
      BLECharacteristic::PROPERTY_READ
    );
  version->setValue(ESPHOME_VERSION);
  BLECharacteristic *manufacturer = device_information_service->createCharacteristic(
      MANUFACTURER_UUID,
      BLECharacteristic::PROPERTY_READ
    );
  manufacturer->setValue("Tall Sequoia");
  device_information_service->start();

  BLEAdvertising *advertising = BLEDevice::getAdvertising();
  advertising->setScanResponse(true);
  advertising->setMinPreferred(0x06);

  advertising->start();
}

void FTMSBikeServer::loop() {

}

BLEService* FTMSBikeServer::add_service(const char* uuid) {
  ESP_LOGD(TAG, "Adding new BLE service");

  BLEService *service = this->server_->createService(uuid);

  BLEAdvertising *advertising = BLEDevice::getAdvertising();
  advertising->addServiceUUID(uuid);

  return service;
}

float FTMSBikeServer::get_setup_priority() const { return setup_priority::HARDWARE; }

void FTMSBikeServer::dump_config() { ESP_LOGCONFIG(TAG, "FTMS Bike Server:"); }

void ESP32BLEServerCallback::onConnect(BLEServer* pServer) {
  ESP_LOGD(TAG, "BLE Client connected");
}

void ESP32BLEServerCallback::onDisconnect(BLEServer* pServer) {
  ESP_LOGD(TAG, "BLE Client disconnected");
}

FTMSBikeServer *global_ble_server = nullptr;

}  // namespace bike_server
}  // namespace ftms

#endif
