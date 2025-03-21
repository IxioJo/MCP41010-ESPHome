#include "mcp41010.h"
#include "esphome/core/log.h"

namespace esphome {
namespace mcp41010 {

static const char *TAG = "mcp41010";

void MCP41010::setup() {
  ESP_LOGCONFIG(TAG, "Setting up MCP41010...");
  this->spi_setup();
}

void MCP41010::dump_config() {
  ESP_LOGCONFIG(TAG, "MCP41010:");
  LOG_PIN("  CS Pin: ", this->cs_);
}

void MCP41010::set_value(uint8_t value) {
  this->write_data(value);
}

void MCP41010::write_data(uint8_t data) {
  this->enable();
  this->transfer_byte(0x11);  // Commande pour définir la résistance
  this->transfer_byte(data);  // Valeur de la résistance
  this->disable();
}

}  // namespace mcp41010
}  // namespace esphome
