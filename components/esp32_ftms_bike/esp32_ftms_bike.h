#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"
#include "esphome/core/preferences.h"

#include "esphome/components/esp32_ble_server/ble_server.h"
#include "esphome/components/esp32_ble/ble_advertising.h"
#include "esphome/components/esp32_ble/ble_uuid.h"
#include "esphome/components/esp32_ble/queue.h"

#ifdef USE_ESP32

namespace esphome {
namespace esp32_ftms_bike {

//using namespace esp32_ble_server;

class FTMSBike : public esp32_ble_server::BLEServer {
  public:
    void setup();
    void loop();
};


}  // namespace esp32_ftms_bike
}  // namespace esphome

#endif
