#pragma once

#include "esphome/core/component.h"

namespace esphome {
namespace esp32_ftms_bike {

class FTMSBike : public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
};

}  // namespace esp32_ftms_bike
}  // namespace esphome

#endif
