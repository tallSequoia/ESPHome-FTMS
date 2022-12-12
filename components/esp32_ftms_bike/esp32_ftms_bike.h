#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"
#include "esphome/core/preferences.h"

#ifdef USE_ESP32

namespace esphome {
namespace esp32_ftms_bike {

//using namespace esp32_ble;

class FTMSBike : public BLEServer {
 
  protected:
   std::vector<sensor::Sensor *> sensors_;
 };
}

}  // namespace esp32_ftms_bike
}  // namespace esphome

#endif