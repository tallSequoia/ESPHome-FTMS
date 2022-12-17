import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID, CONF_MODEL
from esphome.components import esp32_ble
from esphome.components import esp32_ble_server
from esphome.core import CORE
from esphome.components.esp32 import add_idf_sdkconfig_option

AUTO_LOAD = ["esp32_ble_server","esp32_ble"] 
CONFLICTS_WITH = ["esp32_ble_tracker", "esp32_ble_beacon"]
DEPENDENCIES = ["esp32"]
CODEOWNERS = ["@tallsequoia"]

CONF_MANUFACTURER = "manufacturer"
CONF_BLE_ID = "ble_id"

esp32_ftms_bike_ns = cg.global_ns.namespace("esp32_ftms_bike")
FTMSBike = esp32_ftms_bike_ns.class_("FTMSBike", cg.Component)

esp32_ble_server_ns = cg.esphome_ns.namespace("esp32_ble_server")
BLEServiceComponent = esp32_ble_server_ns.class_("BLEServiceComponent")


CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(FTMSBike),
        cv.GenerateID(CONF_BLE_ID): cv.declare_id(esp32_ble.ESP32BLE),  # cv.use_id(esp32_ftms_bike_ns.FTMSBike), # cv.use_id(esp32_ble_server.BLEServer), # cv.use_id(esp32_ble.ESP32BLE),
        cv.Optional(CONF_MANUFACTURER, default="TallSequoia"): cv.string,
        cv.Optional(CONF_MODEL): cv.string,
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    parent = await cg.get_variable(config[CONF_BLE_ID])
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    cg.add(var.set_manufacturer(config[CONF_MANUFACTURER]))
    if CONF_MODEL in config:
        cg.add(var.set_model(config[CONF_MODEL]))
    cg.add_define("USE_ESP32_BLE_SERVER")

#    cg.add(parent.set_server(var))
    cg.add(var.set_parent(parent))  # JM add (based on MQTT Subscribe Sensor example setting parent of MQTT Client Component)

    if CORE.using_esp_idf:
        add_idf_sdkconfig_option("CONFIG_BT_ENABLED", True)
