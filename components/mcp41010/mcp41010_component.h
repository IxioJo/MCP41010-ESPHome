#pragma once

#include "esphome/core/component.h"
#include <vector>

namespace esphome {
namespace mcp41010 {

class MCP41010;  // Forward declaration

class MCP41010Component : public Component {
 public:
  void register_mcp(MCP41010 *mcp) { mcps_.push_back(mcp); }
  
 private:
  std::vector<MCP41010 *> mcps_;
};

}  // namespace mcp41010
}  // namespace esphome

#include "mcp41010.h"  // Inclusion après déclaration de MCP41010Component
