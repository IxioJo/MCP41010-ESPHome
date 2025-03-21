#include "mcp41010.h"
#include "esphome/core/log.h"

namespace esphome {
namespace mcp41010 {

static const char *TAG = "mcp41010";

void MCP41010::setup() {
  ESP_LOGCONFIG(TAG, "Setting up MCP41010 with CS pin %d...", this->cs_pin_);
  pinMode(this->cs_pin_, OUTPUT);
  digitalWrite(this->cs_pin_, HIGH);
}

void MCP41010::set_value(uint8_t value) {
  digitalWrite(this->cs_pin_, LOW);
  this->write_byte(value);
  digitalWrite(this->cs_pin_, HIGH);
}

}  // namespace mcp41010
}  // namespace esphome
