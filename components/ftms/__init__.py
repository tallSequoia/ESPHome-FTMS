import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

ftms_ns = cg.esphome_ns.namespace('ftms')
FTMS = ftms_ns.class_('FTMS', cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(FTMS)
}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
