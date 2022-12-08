#include "esphome/core/log.h"
#include "ftms.h"

namespace esphome {
namespace ftms {

static const char *TAG = "ftms";

void FTMS::setup() {
    ESP_LOGD(TAG, "FTMS component setup");
}

void FTMS::loop() {

}

void FTMS::dump_config(){
    ESP_LOGCONFIG(TAG, "FTMS component dumped");
}

}  // namespace ftms
}  // namespace esphome
