#pragma once

#include "esphome/core/component.h"
#include "esphome/components/spi/spi.h"
#include "mcp41010_component.h"

namespace esphome {
namespace mcp41010 {

class MCP41010 : public spi::SPIDevice<spi::BIT_ORDER_MSB_FIRST, spi::CLOCK_POLARITY_LOW, spi::CLOCK_PHASE_LEADING, spi::DATA_RATE_1MHZ> {
 public:
  MCP41010(MCP41010Component *parent) { parent->register_mcp(this); }
  void setup();
  void set_value(uint8_t value);
};

}  // namespace mcp41010
}  // namespace esphome
