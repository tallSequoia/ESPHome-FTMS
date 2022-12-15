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

//using namespace esp32_ble;

class FTMSBike : public esp32_ble_server::BLEServer {
  public:
    void setup();
    void loop();
    void dump_config();
    void teardown();

    void set_manufacturer(const std::string &manufacturer);
    void set_model(const std::string &model);

    bool can_proceed();

    std::shared_ptr<FTMSBike> create_service(const uint8_t *uuid, bool advertise = false);
    std::shared_ptr<FTMSBike> create_service(uint16_t uuid, bool advertise = false);
    std::shared_ptr<FTMSBike> create_service(const std::string &uuid, bool advertise = false);
    std::shared_ptr<FTMSBike> create_service(esp32_ble::ESPBTUUID uuid, bool advertise = false, uint16_t num_handles = 15, uint8_t inst_id = 0);

    uint32_t get_connected_client_count();

    esp_gatt_if_t get_gatts_if();
    void gatts_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);

    void register_service_component(esp32_ble_server::BLEServiceComponent *component);
};


}  // namespace esp32_ftms_bike
}  // namespace esphome

#endif
