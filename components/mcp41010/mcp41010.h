#pragma once

#include "esphome/core/component.h"
#include "esphome/components/spi/spi.h"

namespace esphome {
namespace mcp41010 {

class MCP41010 : public Component, public spi::SPIDevice {
 public:
  void setup() override;
  void dump_config() override;
  void set_value(uint8_t value);

 protected:
  void write_data(uint8_t data);
};

}  // namespace mcp41010
}  // namespace esphome
