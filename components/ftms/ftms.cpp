#include "esphome/core/log.h"
#include "ftms.h"

namespace esphome {
namespace ftms {

static const char *TAG = "ftms.component";

void EmptyComponent::setup() {
    ESP_LOGD(TAG, "FTMS component setup");
}

void EmptyComponent::loop() {

}

void EmptyComponent::dump_config(){
    ESP_LOGCONFIG(TAG, "FTMS component dumped");
}


}  // namespace ftms
}  // namespace esphome
