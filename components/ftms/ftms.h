#pragma once

#include "esphome/core/component.h"

namespace esphome {
namespace ftms {

class FTMS : public sensor::Sensor, public PollingComponent {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
};

}  // namespace ftms
}  // namespace esphome
