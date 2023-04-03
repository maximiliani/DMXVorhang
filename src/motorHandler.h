#ifndef motorhandler_h
#define motorhandler_h
#include <Arduino.h>

// ulong timePassed = 0;
// ulong timeGoal = 0;
// ulong totalTime = 20000;
// ulong startTime = 0;
// uint tolerance = 200;
// uint8_t goalPosition = 0;
// uint8_t currentPosition = 0;
// uint8_t pinOpen = D0;
// uint8_t pinClose = D4;

void setupMotorHandler();

void setRelativePosition(uint8_t value);

void loopMotorHandler();

#endif