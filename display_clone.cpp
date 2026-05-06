#include <TFT_eSPI.h>
#include "display.h"

TFT_eSPI tft;

void displayInit() {
  tft.init();
  tft.setRotation(1);
}

void displayFillScreen(uint16_t color) { tft.fillScreen(color); }
void displaySetCursor(int x, int y) { tft.setCursor(x, y); }
void displaySetTextColor(uint16_t color) { tft.setTextColor(color); }
void displaySetTextSize(int size) { tft.setTextSize(size); }
void displayPrint(const char* text) { tft.print(text); }

void displayDrawCircle(int x,int y,int r,uint16_t c){ tft.drawCircle(x,y,r,c); }
void displayFillCircle(int x,int y,int r,uint16_t c){ tft.fillCircle(x,y,r,c); }
void displayDrawRect(int x,int y,int w,int h,uint16_t c){ tft.drawRect(x,y,w,h,c); }
void displayFillRect(int x,int y,int w,int h,uint16_t c){ tft.fillRect(x,y,w,h,c); }
