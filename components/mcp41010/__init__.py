import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import spi
from esphome.const import CONF_ID, CONF_CS_PIN

DEPENDENCIES = ["spi"]

CONF_MCP41010_ID = "mcp41010_id"

mcp41010_ns = cg.esphome_ns.namespace("mcp41010")
MCP41010 = mcp41010_ns.class_("MCP41010", cg.Component, spi.SPIDevice)

CONFIG_SCHEMA = cv.All(
    cv.ensure_list(
        {
            cv.GenerateID(): cv.declare_id(MCP41010),
            cv.Required(CONF_CS_PIN): cv.use_id(cg.GPIOPin),
        }
    )
)

async def to_code(config):
    for conf in config:
        var = cg.new_Pvariable(conf[CONF_ID])
        await cg.register_component(var, conf)
        await spi.register_spi_device(var, conf)
        cg.add(var.set_cs_pin(conf[CONF_CS_PIN]))
