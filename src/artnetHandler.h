#ifndef artnethandler_h
#define artnethandler_h

#include <Arduino.h>
#include <Artnet.h>
#include <settings.h>
#include <motorHandler.h>

extern Artnet artnet;

void setupArtnetHandler();

void loopArtnetHandler();

#endif
