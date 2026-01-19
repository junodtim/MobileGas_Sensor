#include "alarm_logic.h"

// Example alarm threshold
const int ALARM_THRESHOLD = 300;

static bool alarmActive = false;

void alarmLogicSetup() {
  // Initialize alarm hardware or variables here
  alarmActive = false;
}

void checkAlarmConditions() {
  // Placeholder for sensor reading, replace with actual sensor data
  int sensorValue = analogRead(A0);

  if (sensorValue > ALARM_THRESHOLD) {
    alarmActive = true;
    // Add code to trigger alarm output (e.g., buzzer, LED)
  } else {
    alarmActive = false;
    // Add code to reset alarm output
  }
}

bool isAlarmActive() {
  return alarmActive;
}