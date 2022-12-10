#pragma once

#include "esphome/components/binary_sensor/binary_sensor.h"
#include "esphome/components/esp32_ble_server/ble_characteristic.h"
#include "esphome/components/esp32_ble_server/ble_server.h"
#include "esphome/components/output/binary_output.h"
#include "esphome/components/wifi/wifi_component.h"
#include "esphome/core/component.h"
#include "esphome/core/helpers.h"
#include "esphome/core/preferences.h"

#ifdef USE_ESP32

namespace esphome {
namespace esp32_ftms_bike {

using namespace esp32_ble_server;

class ESP32FtmsBikeComponent : public Component, public BLEServiceComponent {
 public:
  ESP32FtmsBikeComponent();
  void dump_config() override;
  void loop() override;
  void setup() override;
  void setup_characteristics();
  void on_client_connect() override;
  void on_client_disconnect() override;

  float get_setup_priority() const override;

  void set_authorizer(binary_sensor::BinarySensor *authorizer) { this->authorizer_ = authorizer; }
  void set_status_indicator(output::BinaryOutput *status_indicator) { this->status_indicator_ = status_indicator; }

 protected:
  bool setup_complete_{false};

  uint32_t identify_start_{0};
  uint32_t identify_duration_;
  uint32_t authorized_start_{0};
  uint32_t authorized_duration_;

  std::vector<uint8_t> incoming_data_;
  wifi::WiFiAP connecting_sta_;

  std::shared_ptr<BLEService> service_;
  BLECharacteristic *featuresCharacteristic_;
  BLECharacteristic *bikeDataCharacteristic_;

  binary_sensor::BinarySensor *authorizer_{nullptr};
  output::BinaryOutput *status_indicator_{nullptr};
};

// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
extern ESP32FtmsBikeComponent *global_ftms_bike_component;

}  // namespace esp32_ftms_bike
}  // namespace esphome

#endif
