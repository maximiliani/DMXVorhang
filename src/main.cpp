#include <Arduino.h>
#include <ArduinoOTA.h>
#include <espnowhandler.h>
#include <artnetHandler.h>
#include <motorHandler.h>
#include <settings.h>
#include <webserver.h>

void setup() {
    Serial.begin(115200);
    setupSettings();
    if (getMode() == ESPNOW) {
        setupESPNOWRecv();
    } else if (getMode() == MQTT) {
        // setupMQTT();
    } else if (getMode() == ARTNET) {
        setupArtnetHandler();
    }
    
    // setupESPNOWRecv();
    setupWebserver();
    setupMotorHandler();

    String OTA_id = "DMXVorhang - " + String(WiFi.macAddress());
    ArduinoOTA.setHostname(OTA_id.c_str());
    ArduinoOTA.begin();
}

void loop() {
    ArduinoOTA.handle();
    loopMotorHandler();

    if (getMode() == ARTNET) {
        loopArtnetHandler();
    }    
}
