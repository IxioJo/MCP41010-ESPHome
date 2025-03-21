#pragma once

#include "esphome/core/component.h"
#include "esphome/components/spi/spi.h"

namespace esphome {
namespace mcp41010 {

class MCP41010 : public Component, public spi::SPIDevice {
 public:
  MCP41010(uint8_t cs_pin) { 
    this->cs_pin_ = cs_pin;
  }

  void setup() override {
    pinMode(this->cs_pin_, OUTPUT);
    digitalWrite(this->cs_pin_, HIGH);
  }

  void set_value(uint8_t value) {
    digitalWrite(this->cs_pin_, LOW);
    this->write_byte(value);
    digitalWrite(this->cs_pin_, HIGH);
  }

 protected:
  uint8_t cs_pin_;
};

}  // namespace mcp41010
}  // namespace esphome
