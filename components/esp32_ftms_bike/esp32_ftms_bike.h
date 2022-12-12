#pragma once

#include "esphome/components/esp32_ble/ble_advertising.h"
#include "esphome/components/esp32_ble/ble_uuid.h"
#include "esphome/components/esp32_ble/queue.h"
#include "esphome/core/component.h"
#include "esphome/core/helpers.h"
#include "esphome/core/preferences.h"

#include <map>
#include <memory>

#ifdef USE_ESP32

#include <esp_gap_ble_api.h>
#include <esp_gatts_api.h>

namespace esphome {
namespace esp32_ftms_bike {

using namespace esp32_ble;

class FTMSBike : public esp32_ble_server {}

}  // namespace esp32_ftms_bike
}  // namespace esphome

#endif