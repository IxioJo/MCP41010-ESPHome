from esphome import core
import esphome.codegen as cg

mcp41010_ns = cg.esphome_ns.namespace("mcp41010")
MCP41010 = mcp41010_ns.class_("MCP41010", cg.Component, cg.spi.SPIDevice)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.Required("cs_pin"): cv.int_,
    }
).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_CS_PIN])
    yield cg.register_component(var, config)
    yield cg.register_spi_device(var, config)
