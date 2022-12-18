#include "esphome/core/log.h"
#include "esp32_ftms_bike.h"

namespace esphome {
namespace esp32_ftms_bike {

static const char *TAG = "esp32_ftms_bike.component";

void FTMSBike::setup() {
  ESP_LOGD(TAG, "FTMS component");
}

void FTMSBike::loop() {

}

void FTMSBike::dump_config(){
  ESP_LOGCONFIG(TAG, "FTMS component");
}

}  // namespace esp32_ftms_bike
}  // namespace esphome
