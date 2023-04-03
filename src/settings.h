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

enum MODES {
    ESPNOW = 0,
    MQTT = 1,
    ARTNET = 2,
};

void setupSettings();

void setJSON(String serializedJSON, bool reboot = false);

// StaticJsonDocument<256> getSettingsJSON();

String getJSONString();

const char *getSSID();

const char *getPassword();

MODES getMode();

// uint8_t **getBroadcastAddresses();

const char *getMQTTTopic();

const char *getMQTTServer();

uint getMQTTPort();

uint8_t getOpenPort();

uint8_t getClosePort();

uint getTotalTime();

uint getTolerance();

uint8_t getDMXAddress();

uint8_t getArtnetUniverse();

String toMacAddressString(uint8_t mac[6]);

uint8_t *fromMacAddressString(String mac);

#endif