#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "Array.h"

constexpr uint8_t RED    = 11;
constexpr uint8_t GREEN  = 10;
constexpr uint8_t BLUE   = 9;
constexpr uint8_t YELLOW = 6;

constexpr uint8_t BUTTON = 5;

constexpr int NUMBER_BLINKS {5};

constexpr uint8_t NUM_LEDs = 4;
constexpr Array<uint8_t, NUM_LEDs> LEDs(RED, GREEN, BLUE, YELLOW);

constexpr unsigned long ONE_SECOND {1000};
constexpr unsigned long QUARTER_SECOND {ONE_SECOND / 4};

#endif