#pragma once

#include "ble_descriptor.h"

#ifdef USE_ESP32

namespace esphome {
namespace esp32_ble_erver {

class BLE2902 : public BLEDescriptor {
 public:
  BLE2902();
};

}  // namespace esp32_ble_erver
}  // namespace esphome

#endif
