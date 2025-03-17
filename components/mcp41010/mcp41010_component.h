#pragma once

#include "mcp41010.h"
#include "esphome/core/component.h"

namespace esphome {
namespace mcp41010 {

class MCP41010Component : public Component {
 public:
  void setup() override;
  void loop() override {}
  void register_mcp(MCP41010 *mcp) { mcps_.push_back(mcp); }

 protected:
  std::vector<MCP41010 *> mcps_;
};

}  // namespace mcp41010
}  // namespace esphome
