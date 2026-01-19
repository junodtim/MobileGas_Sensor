#ifndef SGP30_SENSOR_H
#define SGP30_SENSOR_H

#include <Arduino.h>

void sgp30SensorSetup();
void sgp30SensorLoop();
uint16_t getCO2eq();
uint16_t getTVOC();

#endif // SGP30_SENSOR_H