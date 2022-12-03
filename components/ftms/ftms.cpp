#include "esphome/core/log.h"
#include "ftms.h"

namespace esphome {
namespace ftms {

static const char *TAG = "ftms_bike";

void FTMSBike::setup() {
    ESP_LOGD(TAG, "FTMS Bike component setup");
}

void FTMSBike::loop() {

}

void FTMSBike::dump_config(){
    ESP_LOGCONFIG(TAG, "FTMS Bike component dumped");
}


}  // namespace ftms
}  // namespace esphome
