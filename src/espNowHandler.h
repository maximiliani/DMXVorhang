#ifndef espnowhandler_h
#define espnowhandler_h

#include <Arduino.h>
#include <espnow.h>
#include <ESP8266WiFi.h>
#include <motorHandler.h>
#include <settings.h>

extern uint8_t *ownMac;
extern uint8_t dmxRecvAddress;

void setupESPNOWSend();

void setupESPNOWRecv();

void sendESPNOW(uint16_t address, uint8_t value);

#endif