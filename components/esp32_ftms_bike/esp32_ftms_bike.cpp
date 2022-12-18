#include "esphome/core/log.h"
#include "empty_component.h"

namespace esphome {
namespace empty_component {

static const char *TAG = "ftms_component.component";

void EmptyComponent::setup() {
  ESP_LOGD(TAG, "FTMS component");
}

void EmptyComponent::loop() {

}

void EmptyComponent::dump_config(){
  ESP_LOGCONFIG(TAG, "FTMS component");
}


}  // namespace empty_component
}  // namespace esphome
