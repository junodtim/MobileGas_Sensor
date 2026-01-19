#include "mq135_sensor.h"

const int MQ135_PIN = A1;  // Analog input pin for MQ135 sensor

static float mq135GasLevel = 0.0;

void mq135SensorSetup() {
  pinMode(MQ135_PIN, INPUT);
  // Add any sensor warm-up or calibration here if needed
}

void mq135SensorLoop() {
  int rawValue = analogRead(MQ135_PIN);
  // Convert raw analog value to gas concentration (example conversion)
  mq135GasLevel = (float)rawValue;  // Replace with actual conversion formula if available

  Serial.print("MQ135 Gas Level: ");
  Serial.println(mq135GasLevel);
}

float getMQ135GasLevel() {
  return mq135GasLevel;
}