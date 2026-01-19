#include "sgp30_sensor.h"
#include <Wire.h>
#include "Adafruit_SGP30.h"

Adafruit_SGP30 sgp;

static uint16_t co2eq = 0;
static uint16_t tvoc = 0;

void sgp30SensorSetup() {
  if (!sgp.begin()) {
    Serial.println("SGP30 sensor not found :(");
    while (1) { delay(10); }
  }
  Serial.println("SGP30 sensor initialized");
  sgp.IAQinit();
  sgp.setIAQBaseline(0x8973, 0x8AAE); // Optional: set baseline values
}

void sgp30SensorLoop() {
  if (sgp.IAQmeasure()) {
    co2eq = sgp.eCO2;  // Corrected member name
    tvoc = sgp.TVOC;
    Serial.print("CO2eq: "); Serial.print(co2eq);
    Serial.print(" ppm, TVOC: "); Serial.print(tvoc);
    Serial.println(" ppb");
  } else {
    Serial.println("SGP30 measurement failed");
  }
}

uint16_t getCO2eq() {
  return co2eq;
}

uint16_t getTVOC() {
  return tvoc;
}