#pragma once

#include <Arduino.h>

// High-level UI screens

void uiShowBoot();
void uiShowGrid();
void uiShowSensorValues(int co2, int tvoc, int temp, int hum);
void uiShowAlarm(const char* msg);
void uiShowNormal();