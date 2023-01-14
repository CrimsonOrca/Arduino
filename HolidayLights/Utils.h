#ifndef UTILS_H
#define UTILS_H

#include "Constants.h"

struct Mode {
  static const bool ON;
  static const bool OFF;
};

const bool Mode::ON  = true;
const bool Mode::OFF = false;

void switchLights(bool mode, const int& brightness=0) {
  if (mode) {
    analogWrite(RED, brightness);
    analogWrite(GREEN, brightness);
    analogWrite(BLUE, brightness);
    analogWrite(YELLOW, brightness);
  }
  else {
    analogWrite(RED, brightness);
    analogWrite(GREEN, brightness);
    analogWrite(BLUE, brightness);
    analogWrite(YELLOW, brightness);
  }
}

#endif