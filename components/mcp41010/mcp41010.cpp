#include "mcp41010.h"
#include "mcp41010_component.h"

namespace esphome {
namespace mcp41010 {

MCP41010::MCP41010(MCP41010Component *parent) : parent_(parent) {
  parent->register_mcp(this);
}

void MCP41010::set_value(uint8_t value) {
  uint8_t command = (value & 0xFF);  // Commande SPI
  this->enable();
  this->transfer_byte(command);
  this->disable();
}

void MCP41010::setup() {
  ESP_LOGCONFIG("MCP41010", "Setting up MCP41010...");
}

void MCP41010::dump_config() {
  ESP_LOGCONFIG("MCP41010", "MCP41010 ready.");
}

}  // namespace mcp41010
}  // namespace esphome
