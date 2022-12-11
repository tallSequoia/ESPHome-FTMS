#pragma once

#include "ble_descriptor.h"

#ifdef USE_ESP32

namespace esphome {
namespace esp32_ftms_bike {

class BLE2902 : public BLEDescriptor {
 public:
  BLE2902();
};

}  // namespace esp32_ftms_bike
}  // namespace esphome

#endif
