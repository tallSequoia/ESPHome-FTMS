#pragma once

#include "esphome/core/component.h"

namespace esphome {
namespace ftms {

class FTMSBike : public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
};


}  // namespace ftms
}  // namespace esphome
