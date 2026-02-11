#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <SPIFFS.h>
#include <Wire.h>

#include "I2CDriver.h"
#include "mq2_sensor.h"
#include "mq135_sensor.h"
#include "sgp30_sensor.h"
#include "bme280_sensor.h"
#include "ring_buffer.h"
#include "alarm_logic.h"

#include "DisplayModule.h"
#include "UI.h"

// WiFi credentials
const char* ssid = "ssid";
const char* password = "password";

WebServer server(80);

void setup() {
  Serial.begin(115200);
  delay(200);

  // Initialize I2C ONCE, globally
  //Wire.begin(8, 9); old way
  Bus::init();

  // SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS mount failed");
  }

  // WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.println(WiFi.localIP());

  // Display
  if (!displayInit()) {
    Serial.println("Display init failed");
    while (true) delay(100);
  }
  uiShowBoot();
  delay(1500);

  // Alarm logic
  alarmLogicSetup();

  // Sensors
  mq2SensorSetup();
  mq135SensorSetup();
  sgp30SensorSetup();
  bme280SensorSetup();

  // Web server
  server.on("/", []() {
    File file = SPIFFS.open("/dashboard.html", "r");
    if (!file) {
      server.send(404, "text/plain", "File not found");
      return;
    }
    server.streamFile(file, "text/html");
    file.close();
  });

  server.begin();
}

void loop() {
  server.handleClient();

  // Sensor updates
  mq2SensorLoop();
  mq135SensorLoop();
  sgp30SensorLoop();
  bme280SensorLoop();

  // Get sensor values
  int co2  = getCO2eq();   // correct SGP30 function
  int tvoc = getTVOC();    // this one was already correct
  float temp = getTemperatureF();
  float hum  = getHumidity();

  // Alarm logic
  checkAlarmConditions();

  // Display update
  if (isAlarmActive()) {
    uiShowAlarm("Gas Levels High");
  } else {
    uiShowSensorValues(co2, tvoc, (int)temp, (int)hum);
  }

  delay(500);
}
