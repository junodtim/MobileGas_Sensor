#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include "DisplayModule.h"

// SH1106 128x64 I2C display instance using external Wire (no internal Wire.begin)
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(
    U8G2_R0,
    /* reset=*/ U8X8_PIN_NONE,
    /* clock=*/ 9,
    /* data=*/ 8
);

bool displayInit() {
    // IMPORTANT: Bus::init() must be called in main.ino BEFORE this
    u8g2.begin();
    u8g2.clearBuffer();
    u8g2.sendBuffer();
    return true;
}

void displayClear() {
    u8g2.clearBuffer();
}

void displaySend() {
    u8g2.sendBuffer();
}

void displaySetFontSmall() {
    u8g2.setFont(u8g2_font_6x12_tr);
}

void displaySetFontMedium() {
    u8g2.setFont(u8g2_font_ncenB08_tr);
}

void displayDrawText(int x, int y, const char* text) {
    u8g2.drawStr(x, y, text);
}

void displayDrawLine(int x1, int y1, int x2, int y2) {
    u8g2.drawLine(x1, y1, x2, y2);
}

void displayDrawRect(int x, int y, int w, int h) {
    u8g2.drawFrame(x, y, w, h);
}

void displayDrawGrid() {
    u8g2.clearBuffer();

    // Vertical lines every 8 pixels
    for (int x = 0; x < 128; x += 8) {
        u8g2.drawLine(x, 0, x, 63);
    }

    // Horizontal lines every 8 pixels
    for (int y = 0; y < 64; y += 8) {
        u8g2.drawLine(0, y, 127, y);
    }

    u8g2.sendBuffer();
}

float displayMeasureFPS() {
    unsigned long start = millis();

    for (int i = 0; i < 50; i++) {
        u8g2.clearBuffer();
        u8g2.setFont(u8g2_font_6x12_tr);
        u8g2.drawStr(0, 12, "FPS Test");

        char buf[20];
        snprintf(buf, sizeof(buf), "Frame: %d", i);
        u8g2.drawStr(0, 28, buf);

        u8g2.sendBuffer();
    }

    unsigned long elapsed = millis() - start;
    if (elapsed == 0) return 0.0;
    return 50.0 / (elapsed / 1000.0);
}