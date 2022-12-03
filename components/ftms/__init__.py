import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

ftms_bike_ns = cg.esphome_ns.namespace('ftms_bike')
FTMSBike = ftms_bike_ns.class_('FTMSBike', cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(FTMSBike)
}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
