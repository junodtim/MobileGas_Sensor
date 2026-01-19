#pragma once
#include <Arduino.h>

bool bme280SensorSetup();
void bme280SensorLoop();

float getTemperatureF();    // Fahrenheit only
float getHumidity();
float getPressure();        // hPa