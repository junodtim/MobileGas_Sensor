#pragma once
#include <Arduino.h>

// Initializes the display subsystem.
// IMPORTANT: Bus::init() must be called BEFORE this.
bool displayInit();

// Buffer control
void displayClear();
void displaySend();

// Font selection
void displaySetFontSmall();
void displaySetFontMedium();

// Drawing primitives
void displayDrawText(int x, int y, const char* text);
void displayDrawLine(int x1, int y1, int x2, int y2);
void displayDrawRect(int x, int y, int w, int h);

// Diagnostics
void displayDrawGrid();
float displayMeasureFPS();