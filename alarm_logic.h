#ifndef ALARM_LOGIC_H
#define ALARM_LOGIC_H

#include <Arduino.h>

void alarmLogicSetup();
void checkAlarmConditions();
bool isAlarmActive();

#endif // ALARM_LOGIC_H