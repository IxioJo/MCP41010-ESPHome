#include "mcp41010_component.h"
#include "esphome/core/log.h"

namespace esphome {
namespace mcp41010 {

static const char *const TAG = "mcp41010.component";

void MCP41010Component::setup() {
  ESP_LOGD(TAG, "Setting up MCP41010 devices...");
  for (auto *mcp : mcps_) {
    mcp->setup();
  }
}

}  // namespace mcp41010
}  // namespace esphome
