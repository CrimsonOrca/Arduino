#include "Utils.h"

int readValue;
int brightness;

void setup() {
  for (auto iterator = LEDs.begin(); iterator <= LEDs.end(); iterator += 1) {
    pinMode(*iterator, OUTPUT);
  }
  pinMode(BUTTON, INPUT); 
}

void loop() {
  readValue = analogRead(A0);
  brightness = readValue / 4;

  switchLights(Mode::ON, brightness);

  if (digitalRead(BUTTON) == HIGH) {
    switchLights(Mode::OFF);
    delay(ONE_SECOND);

    // begin light show...
    for (auto iterator = LEDs.begin(); iterator <= LEDs.end(); iterator += 1) {
        analogWrite(*iterator, brightness);
        delay(QUARTER_SECOND);
    }
    switchLights(Mode::OFF);
    delay(ONE_SECOND);
 
    for (auto iterator = LEDs.end(); iterator >= LEDs.begin(); iterator -= 1) {
      analogWrite(*iterator, brightness);
      delay(QUARTER_SECOND);
    }
    switchLights(Mode::OFF);
    delay(ONE_SECOND);

    for (int n = 0; n < NUMBER_BLINKS; n++) {
      switchLights(Mode::ON, brightness);
      delay(QUARTER_SECOND);
      switchLights(Mode::OFF);
      delay(QUARTER_SECOND);
    }
  }
}