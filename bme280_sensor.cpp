// bme280_sensor.cpp
#include "bme280_sensor.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME280_CHIP_ID 0x60
#define BMP280_CHIP_ID 0x58

static Adafruit_BME280 bme;
static uint8_t bmeAddress = 0;

static float temperatureC = 0.0;   // internal storage
static float humidity    = 0.0;
static float pressure    = 0.0;    // hPa

uint8_t readChipID(uint8_t addr) {
    Wire.beginTransmission(addr);
    Wire.write(0xD0);  // chip ID register
    if (Wire.endTransmission() != 0) return 0;

    Wire.requestFrom(addr, (uint8_t)1);
    if (Wire.available()) return Wire.read();
    return 0;
}

bool bme280SensorSetup() {
    // Try 0x76
    uint8_t id76 = readChipID(0x76);
    if (id76 == BME280_CHIP_ID || id76 == BMP280_CHIP_ID) {
        bmeAddress = 0x76;
    }

    // Try 0x77 if needed
    if (bmeAddress == 0) {
        uint8_t id77 = readChipID(0x77);
        if (id77 == BME280_CHIP_ID || id77 == BMP280_CHIP_ID) {
            bmeAddress = 0x77;
        }
    }

    if (bmeAddress == 0) {
        Serial.println("BME/BMP280 not detected at 0x76 or 0x77");
        return false;
    }

    if (!bme.begin(bmeAddress, &Wire)) {
        Serial.println("BME/BMP280 init failed after detection");
        return false;
    }

    Serial.print("BME/BMP280 detected at 0x");
    Serial.println(bmeAddress, HEX);
    Serial.println("BME280 setup running...");

    return true;
}

void bme280SensorLoop() {
    temperatureC = bme.readTemperature();          // store internally as °C
    humidity     = bme.readHumidity();             // %
    pressure     = bme.readPressure() / 100.0F;    // hPa

    // Fahrenheit‑only serial output
    Serial.print("Temp: ");
    Serial.print(getTemperatureF());
    Serial.print(" °F  ");

    Serial.print("Hum: ");
    Serial.print(humidity);
    Serial.print(" %  ");

    Serial.print("Pres: ");
    Serial.print(pressure);
    Serial.println(" hPa");
}

float getTemperatureF() {
    return (temperatureC * 1.8f) + 32.0f;
}

float getHumidity() {
    return humidity;
}

float getPressure() {
    return pressure;
}