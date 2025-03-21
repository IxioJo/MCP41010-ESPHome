#pragma once

#include "esphome/core/component.h"
#include "esphome/components/spi/spi.h"
#include "mcp41010_component.h"  // Maintenant, on peut inclure ce fichier

namespace esphome {
namespace mcp41010 {

class MCP41010 {
 public:
  MCP41010(MCP41010Component *parent) { parent->register_mcp(this); }
  
  void set_value(uint8_t value);
};

}  // namespace mcp41010
}  // namespace esphome
