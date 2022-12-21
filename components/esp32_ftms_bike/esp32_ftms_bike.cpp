#include "esp32_ftms_bike.h"

#ifdef USE_ESP32

#include "esphome/core/log.h"
#include "esphome/core/application.h"
#include "esphome/core/version.h"

#include "esphome/components/esp32_ble/ble.h"
#include "esphome/components/esp32_ble_server/ble_server.h"
#include "esphome/components/esp32_ble_server/ble_characteristic.h"

#include "esphome/components/binary_sensor/binary_sensor.h"
#include "esphome/components/output/binary_output.h"

#include <nvs_flash.h>
#include <freertos/FreeRTOSConfig.h>
#include <esp_bt_main.h>
#include <esp_bt.h>
#include <freertos/task.h>
#include <esp_gap_ble_api.h>


namespace esphome {
namespace esp32_ftms_bike {

static const char *const TAG = "esp32_ftms_bike";


class FTMSBike {

    void setup() {
    //  this->service_ = global_ble_server->create_service(improv::SERVICE_UUID, true);
        setup_characteristics();
    }

    void loop() {}

    void dump_config() {}

    void teardown() {}

    void start() {}

    void stop() {}

    void setup_characteristics() {}

    void on_client_disconnect() {}

};


}  // namespace esp32_ftms_bike
}  // namespace esphome

#endif
