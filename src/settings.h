#ifndef settings_h
#define settings_h

#include <Arduino.h>
#include <ArduinoJson.h>
#include <espnow.h>
#include <LittleFS.h>
#include <ESP8266WiFi.h>

#define defaultSSID "DMXAP"
#define defaultPassword "password"
#define maxAmountOfESPNowPeers 7
//#define amountOfESPNowPeers 20  // should be the maximum amount, but is only available with additional configuration

/*
* This enum is used to determine the mode of the device.
* ESPNOW: The device will receive DMX data via ESP-NOW
* MQTT: The device will receive DMX data via MQTT (not implemented yet)
* ARTNET: The device will receive DMX data via Art-Net
*/
enum MODES {
    ESPNOW = 0,
    MQTT = 1,
    ARTNET = 2,
};

void setupSettings();

void setJSON(String serializedJSON, bool reboot = false);

String getJSONString();

const char *getSSID();

const char *getPassword();

MODES getMode();

const char *getMQTTTopic();

const char *getMQTTServer();

uint getMQTTPort();

uint8_t getOpenPort();

uint8_t getClosePort();

uint getTotalTime();

uint getTolerance();

uint8_t getDMXAddress();

uint16_t getArtnetUniverse();

String toMacAddressString(uint8_t mac[6]);

uint8_t *fromMacAddressString(String mac);

#endif