#pragma once
#include <Arduino.h>

void displayInit();
void displayFillScreen(uint16_t color);
void displaySetCursor(int x, int y);
void displaySetTextColor(uint16_t color);
void displaySetTextSize(int size);
void displayPrint(const char* text);

void displayDrawCircle(int x, int y, int r, uint16_t color);
void displayFillCircle(int x, int y, int r, uint16_t color);
void displayDrawRect(int x, int y, int w, int h, uint16_t color);
void displayFillRect(int x, int y, int w, int h, uint16_t color);
