#pragma once

#include "esphome/core/component.h"
#include "esphome/components/spi/spi.h"

namespace esphome {
namespace mcp41010 {

// Forward declaration
class MCP41010Component;

class MCP41010 : public Component, public spi::SPIDevice {
 public:
  MCP41010(MCP41010Component *parent);  // Déplacement du constructeur vers le .cpp
  void set_value(uint8_t value);
  void setup() override;
  void dump_config() override;

 private:
  MCP41010Component *parent_;
};

}  // namespace mcp41010
}  // namespace esphome
