#include "config.h"
#include "display.h"

#include <AiEsp32RotaryEncoder.h>

#define ROTARY_ENCODER_A_PIN 21
#define ROTARY_ENCODER_B_PIN 19
#define ROTARY_ENCODER_BUTTON_PIN 22
#define ROTARY_ENCODER_VCC_PIN -1
#define ROTARY_ENCODER_STEPS 4

AiEsp32RotaryEncoder rotaryEncoder(
  ROTARY_ENCODER_A_PIN,
  ROTARY_ENCODER_B_PIN,
  ROTARY_ENCODER_BUTTON_PIN,
  ROTARY_ENCODER_VCC_PIN,
  ROTARY_ENCODER_STEPS
);

unsigned long lastEncoderCheck = 0;
int menuIndex = 0;
const int totalGames = 3;
bool inGame = false;

void IRAM_ATTR readEncoderISR() {
  rotaryEncoder.readEncoder_ISR();
}

// games
void playDialDodge();
void playCodeBreaker();
void playQuickDraw();

void setup() {
  Serial.begin(115200);

  displayInit();
  displayFillScreen(0);

  rotaryEncoder.begin();
  rotaryEncoder.setup(readEncoderISR);
  rotaryEncoder.setBoundaries(0, totalGames - 1, false);
  rotaryEncoder.setAcceleration(0);

  showLogo();
}

void loop() {
  if (inGame) return;

  if (millis() - lastEncoderCheck > 5) {
    int newIndex = rotaryEncoder.readEncoder();

    if (newIndex != menuIndex) {
      menuIndex = newIndex;
      showMenu();
    }

    if (rotaryEncoder.isEncoderButtonClicked()) {
      launchGame(menuIndex);
    }

    lastEncoderCheck = millis();
  }
}
