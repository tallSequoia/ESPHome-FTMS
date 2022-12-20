#include "esp32_ftms_bike.h"

#include "esphome/core/log.h"
#include "esphome/core/component.h"
#include "esphome/core/helpers.h"
#include "esphome/core/preferences.h"

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>
#include <math.h>


// See the following for generating UUIDs: https://www.uuidgenerator.net/
#define FTMS_SERVICE_UUID "1826" //"00001826-0000-1000-8000-00805f9b34fe"
#define FTMS_FEATURES_CHARACTERISTIC_UUID "2ACC"  //"00002acc-0000-1000-8000-00805f9b34fe"
#define INDOOR_BIKE_DATA_CHARACTERISTIC_UUID "2AD2" // "00002ad2-0000-1000-8000-00805f9b34fe"

#define WHEEL_RADIUS 0.22000    // m

#define RIDER_WEIGHT 72.6       // kg
#define BIKE_WEIGHT 11.1        // kg

#define TEMPERATURE_EV 15.6     // oC
#define ELEVATION 100           // m above sea level

#define JOULE_TO_KCAL 0.238902957619



namespace esphome {
  namespace esp32_ftms_bike {

    static const char *TAG = "esp32_ftms_bike.component";
    
    
    

    void FTMSBike::setup() {
      ESP_LOGD(TAG, "FTMS component");
    }

    void FTMSBike::loop() {

    }

    void FTMSBike::dump_config(){
      ESP_LOGCONFIG(TAG, "FTMS component");
    }

  }  // namespace esp32_ftms_bike
}  // namespace esphome
