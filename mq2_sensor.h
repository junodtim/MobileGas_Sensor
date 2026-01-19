#ifndef MQ2_SENSOR_H
#define MQ2_SENSOR_H

#include <Arduino.h>

void mq2SensorSetup();
void mq2SensorLoop();
float getMQ2GasLevel();

#endif // MQ2_SENSOR_H