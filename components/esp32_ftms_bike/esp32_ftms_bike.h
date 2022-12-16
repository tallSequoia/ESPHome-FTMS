#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"
#include "esphome/core/preferences.h"
//#include "esphome/core/defines.h"

#include "esphome/components/esp32_ble_server/ble_server.h"
#include "esphome/components/esp32_ble/ble_advertising.h"
#include "esphome/components/esp32_ble/ble_uuid.h"
#include "esphome/components/esp32_ble/queue.h"

#include <map>
#include <memory>
#include <vector>


#ifdef USE_ESP32

#include <esp_gap_ble_api.h>
#include <esp_gatts_api.h>


#ifdef USE_ESP32

namespace esphome {
namespace esp32_ftms_bike {

using namespace esp32_ble;

class FTMSBike : public esp32_ble_server::BLEServer {
  public:
    void setup();
    void loop();
    void dump_config();
    void teardown();

    void set_manufacturer(const std::string &manufacturer) { this->manufacturer_ = manufacturer; }
    void set_model(const std::string &model) { this->model_ = model; }

    bool can_proceed();
/*
    std::shared_ptr<FTMSBike> create_service(const uint8_t *uuid, bool advertise = false);
    std::shared_ptr<FTMSBike> create_service(uint16_t uuid, bool advertise = false);
    std::shared_ptr<FTMSBike> create_service(const std::string &uuid, bool advertise = false);
    std::shared_ptr<FTMSBike> create_service(ESPBTUUID uuid, bool advertise = false, uint16_t num_handles = 15,
     uint8_t inst_id = 0);

    // JM: I needed to provide the method definition here as it did not inherit from the base, possibly due to being in the header, not the "main" class? Yuck!
    esp_gatt_if_t get_gatts_if() { return this->gatts_if_; }
    uint32_t get_connected_client_count() { return this->connected_clients_; }
    const std::map<uint16_t, void *> &get_clients() { return this->clients_; }

    void register_service_component(esp32_ble_server::BLEServiceComponent *component);
*/
};


}  // namespace esp32_ftms_bike
}  // namespace esphome

#endif
