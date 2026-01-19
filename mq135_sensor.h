#ifndef MQ135_SENSOR_H
#define MQ135_SENSOR_H

#include <Arduino.h>

void mq135SensorSetup();
void mq135SensorLoop();
float getMQ135GasLevel();

#endif // MQ135_SENSOR_H