#include "UI.h"
#include "DisplayModule.h"

// Boot screen
void uiShowBoot() {
  displayClear();
  displaySetFontSmall();

  displayDrawText(0, 12, "MobileGas Monitor");
  displayDrawText(0, 26, "ESP32-S3 OK");
  displayDrawText(0, 40, "OLED SH1106 OK");
  displayDrawText(0, 54, "IP 192.168.1.62");

  displaySend();
}

// Grid overlay (layout helper)
void uiShowGrid() {
  displayDrawGrid();
}

// Sensor values screen
void uiShowSensorValues(int co2, int tvoc, int temp, int hum) {
  displayClear();
  displaySetFontSmall();

  char buf[24];

  snprintf(buf, sizeof(buf), "CO2: %d ppm", co2);
  displayDrawText(0, 12, buf);

  snprintf(buf, sizeof(buf), "TVOC: %d ppb", tvoc);
  displayDrawText(0, 24, buf);

  snprintf(buf, sizeof(buf), "Temp: %d F", temp);
  displayDrawText(0, 36, buf);

  snprintf(buf, sizeof(buf), "Hum: %d %%", hum);
  displayDrawText(0, 48, buf);

  displaySend();
}

// Alarm screen
void uiShowAlarm(const char* msg) {
  displayClear();
  displaySetFontSmall();

  displayDrawText(0, 16, "!!! ALARM !!!");
  displayDrawText(0, 32, msg);

  displaySend();
}

// Normal status screen
void uiShowNormal() {
  displayClear();
  displaySetFontSmall();
  displayDrawText(0, 24, "System Normal");
  displaySend();
}