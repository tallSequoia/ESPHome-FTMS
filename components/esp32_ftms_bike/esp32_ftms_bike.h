#pragma once

//#include <vector>

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"
#include "esphome/core/preferences.h"
#include "esphome/core/defines.h"

#include "esphome/components/esp32_ble_server/ble_server.h"
#include "esphome/components/esp32_ble_server/ble_characteristic.h"
//#include "esphome/components/esp32_ble/ble_advertising.h"
//#include "esphome/components/esp32_ble/ble_uuid.h"
//#include "esphome/components/esp32_ble/queue.h"
//#include <esp_gap_ble_api.h>
//#include <esp_gatts_api.h>

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

//    bool can_proceed();

    void start() override;
    void stop() override;

    void setup_characteristics();
    void on_client_disconnect();

    float get_setup_priority() const override;
    bool is_active() const { return this->state_ != improv::STATE_STOPPED; }

    // JM: I needed to provide the method definition here as it did not inherit from the base, possibly due to being in the header, not the "main" class? Yuck!
    void set_manufacturer(const std::string &manufacturer) { this->manufacturer_ = manufacturer; }
    void set_model(const std::string &model) { this->model_ = model; }
/*
    std::shared_ptr<FTMSBike> create_service(const uint8_t *uuid, bool advertise = false);
    std::shared_ptr<FTMSBike> create_service(uint16_t uuid, bool advertise = false);
    std::shared_ptr<FTMSBike> create_service(const std::string &uuid, bool advertise = false);
    std::shared_ptr<FTMSBike> create_service(ESPBTUUID uuid, bool advertise = false, uint16_t num_handles = 15, uint8_t inst_id = 0);

    // JM: I needed to provide the method definition here as it did not inherit from the base, possibly due to being in the header, not the "main" class? Yuck!
    esp_gatt_if_t get_gatts_if() { return this->gatts_if_; }
    uint32_t get_connected_client_count() { return this->connected_clients_; }
    const std::map<uint16_t, void *> &get_clients() { return this->clients_; }

    void register_service_component(BLEServiceComponent *component);
*/
  protected:
    bool create_device_characteristics_();

    void add_client_(uint16_t conn_id, void *client) {
      this->clients_.insert(std::pair<uint16_t, void *>(conn_id, client));
    }
    bool remove_client_(uint16_t conn_id) { return this->clients_.erase(conn_id) > 0; }

    bool can_proceed_{false};

    std::string manufacturer_;
    optional<std::string> model_;
    esp_gatt_if_t gatts_if_{0};
    bool registered_{false};

    uint32_t connected_clients_{0};
    std::map<uint16_t, void *> clients_;

    std::vector<std::shared_ptr<BLEService>> services_;
    std::shared_ptr<BLEService> device_information_service_;

    std::vector<BLEServiceComponent *> service_components_;

    enum State : uint8_t {
      INIT = 0x00,
      REGISTERING,
      STARTING_SERVICE,
      RUNNING,
    } state_{INIT};
};

}  // namespace esp32_ftms_bike
//}  // namespace esphome

#endif
