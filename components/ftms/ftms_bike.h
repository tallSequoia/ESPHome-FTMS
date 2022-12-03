#pragma once

#include "esphome/core/component.h"

namespace esphome {
namespace ftms_bike {

class FTMSBike : public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
};


}  // namespace ftms_bike
}  // namespace esphome
