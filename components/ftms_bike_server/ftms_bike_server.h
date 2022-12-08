#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"
#include "esphome/core/preferences.h"

#ifdef ARDUINO_ARCH_ESP32

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>

namespace ftms {
namespace bike_server {

class ESP32BLECharacteristicCallback : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *characteristic);
};

class ESP32BLEServerCallback: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer);
  void onDisconnect(BLEServer* pServer);
};

class FTMSBikeServer : public Component {
 public:
  FTMSBikeServer();
  void setup() override;
  void loop() override;
  void dump_config() override;
  float get_setup_priority() const override;

  BLEService* add_service(const char *uuid);

 protected:

  BLEServer *server_;
};

extern FTMSBikeServer *global_ble_server;

}  // namespace bike_server
}  // nameapsce ftms

#endif
