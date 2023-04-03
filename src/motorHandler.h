#ifndef motorhandler_h
#define motorhandler_h

#include <Arduino.h>
#include <settings.h>

void setupMotorHandler();

void setRelativePosition(uint8_t value);

void loopMotorHandler();

#endif