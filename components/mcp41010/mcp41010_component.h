#pragma once

#include "esphome/core/component.h"
#include "esphome/components/spi/spi.h"
#include <vector>

namespace esphome {
namespace mcp41010 {

class MCP41010;  // Déclaration anticipée

class MCP41010Component : public Component {
 public:
  void setup() override;
  void dump_config() override;

  void register_mcp(MCP41010 *mcp) { mcps_.push_back(mcp); }

 protected:
  std::vector<MCP41010 *> mcps_;  // Util
