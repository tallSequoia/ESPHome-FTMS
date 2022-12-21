#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"
#include "esphome/core/preferences.h"
#include "esphome/core/defines.h"

#include "esphome/components/esp32_ble_server/ble_server.h"
#include "esphome/components/esp32_ble_server/ble_characteristic.h"

#include "esphome/components/binary_sensor/binary_sensor.h"
#include "esphome/components/output/binary_output.h"

#ifdef USE_ESP32

using namespace esphome;
using namespace esp32_ble_server;

namespace esp32_ftms_bike {

class FTMSBike : public BLEServiceComponent {
  public:
    void setup();
    void loop();
    void dump_config();
    void teardown();
    void update(){};    // esp-idf needs this, whereas arduino does not

    bool can_proceed();

    void setup_characteristics();
    void on_client_disconnect();

    // JM: I needed to provide the method definition here as it did not inherit from the base, possibly due to being in the header, not the "main" class? Yuck!
//    void set_manufacturer(const std::string &manufacturer) { this->manufacturer_ = manufacturer; }
//    void set_model(const std::string &model) { this->model_ = model; }

    std::shared_ptr<FTMSBike> create_service(const uint8_t *uuid, bool advertise = false);
    std::shared_ptr<FTMSBike> create_service(uint16_t uuid, bool advertise = false);
    std::shared_ptr<FTMSBike> create_service(const std::string &uuid, bool advertise = false);
    std::shared_ptr<FTMSBike> create_service(ESPBTUUID uuid, bool advertise = false, uint16_t num_handles = 15, uint8_t inst_id = 0);

    // JM: I needed to provide the method definition here as it did not inherit from the base, possibly due to being in the header, not the "main" class? Yuck!
//    esp_gatt_if_t get_gatts_if() { return this->gatts_if_; }
    uint32_t get_connected_client_count() { return this->connected_clients_; }
    const std::map<uint16_t, void *> &get_clients() { return this->clients_; }

    void register_service_component(BLEServiceComponent *component);
};

}  // namespace esp32_ftms_bike
//}  // namespace esphome

#endif
