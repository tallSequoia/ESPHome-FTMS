import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID
from esphome.core import coroutine_with_priority

CODEOWNERS = ['@tallSequoia']

ftms_bike_server_ns = cg.esphome_ns.namespace('ftms_bike_server')
FTMSBikeServer = ftms_bike_server_ns.class_('FTMSBikeServer', cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(FTMSBikeServer),
}).extend(cv.COMPONENT_SCHEMA)


def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    cg.add_define('USE_BLE_SERVER')
