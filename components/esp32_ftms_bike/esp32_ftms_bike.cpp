#include "esp32_ftms_bike.h"

#include "esphome/components/esp32_ble/ble.h"
#include "esphome/components/esp32_ble_server/ble_2902.h"
#include "esphome/core/application.h"
#include "esphome/core/log.h"

#ifdef USE_ESP32

namespace esphome {
namespace esp32_ftms_bike {

// Standard logging tag
static const char *const TAG = "esp32_ftms_bike";

// FTMS Service UUIDs (BLE spec)
static const char *const MANUFACTURER_NAME = "Bikey McBikeFace";
static const char *const FTMS_SERVICE_UUID = "1826";
static const char *const FTMS_FEATURES_CHARACTERISTIC_UUID = "2ACC";
static const char *const INDOOR_BIKE_DATA_CHARACTERISTIC_UUID = "2AD2";


// Constants that could be set from other sources

#define LED_PIN 2
#define WHEEL_PIN 27

#define JOULE_TO_KCAL 0.238902957619

#define WHEEL_RADIUS 0.0003682    // in km for a 29" wheel
#define RIDER_WEIGHT 72.6         // kg
#define BIKE_WEIGHT 11.1          // kg of the Cannondale road bike
#define TEMPERATURE_EV 15.6       // oC
#define ELEVATION 100             // m


ESP32FtmsBikeComponent::ESP32FtmsBikeComponent() { global_ftms_bike_component = this; }

float ESP32FtmsBikeComponent::get_setup_priority() const { return setup_priority::AFTER_BLUETOOTH; }

void ESP32FtmsBikeComponent::setup() {
  ESP_LOGD(TAG, "Setup starting");

  this->service_ = global_ble_server->create_service(FTMS_SERVICE_UUID, true);

//  this->service_->set_manufacturer(MANUFACTURER_NAME);

  this->featuresCharacteristic_ = this->service_->create_characteristic(
    FTMS_FEATURES_CHARACTERISTIC_UUID, 
    BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE | BLECharacteristic::PROPERTY_NOTIFY
  );
  BLEDescriptor *featuresCharacteristic_descriptor = new BLE2902();
  this->featuresCharacteristic_->add_descriptor(featuresCharacteristic_descriptor);

  this->bikeDataCharacteristic_ = this->service_->create_characteristic(
    INDOOR_BIKE_DATA_CHARACTERISTIC_UUID, 
    BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE | BLECharacteristic::PROPERTY_NOTIFY
  );
  BLEDescriptor *bikeDataCharacteristic_descriptor = new BLE2902();
  this->bikeDataCharacteristic_->add_descriptor(bikeDataCharacteristic_descriptor);

/*
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(FTMS_SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06); // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
*/

  ESP_LOGD(TAG, "Setup complete");
}

void ESP32FtmsBikeComponent::loop() {
}


void ESP32FtmsBikeComponent::start() {
  ESP_LOGD(TAG, "Start");
}

void ESP32FtmsBikeComponent::stop() {
  ESP_LOGD(TAG, "Stop");
}


void ESP32FtmsBikeComponent::dump_config() {
  ESP_LOGCONFIG(TAG, "ESP32 FTMS Bike:");
}

void ESP32FtmsBikeComponent::on_client_disconnect() {
  ESP_LOGD(TAG, "Client disconnect");
}

void ESP32FtmsBikeComponent::on_client_connect() {
  ESP_LOGD(TAG, "Client connect");
}


ESP32FtmsBikeComponent *global_ftms_bike_component = nullptr;  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

}  // namespace esp32_ftms_bike
}  // namespace esphome

#endif
