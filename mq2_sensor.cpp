#include "mq2_sensor.h"

const int MQ2_PIN = A0;  // Analog input pin for MQ2 sensor

static float mq2GasLevel = 0.0;

void mq2SensorSetup() {
  pinMode(MQ2_PIN, INPUT);
  // Add any sensor warm-up or calibration here if needed
}

void mq2SensorLoop() {
  int rawValue = analogRead(MQ2_PIN);
  // Convert raw analog value to gas concentration (example conversion)
  mq2GasLevel = (float)rawValue;  // Replace with actual conversion formula if available

  Serial.print("MQ2 Gas Level: ");
  Serial.println(mq2GasLevel);
}

float getMQ2GasLevel() {
  return mq2GasLevel;
}