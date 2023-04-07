#include <Arduino.h>
#include <ArduinoOTA.h>
#include <espnowhandler.h>
#include <artnetHandler.h>
#include <motorHandler.h>
#include <settings.h>
#include <webserver.h>

/*
* This method is run on startup.
*/
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


/*
* This method is looped until poweroff.
*/
void loop() {
    ArduinoOTA.handle();  // Handles incoming OTA update requests
    loopMotorHandler();   // Handles the motor movement

    // If current mode is ArtNet, it will handle the ArtNet data
    if (getMode() == ARTNET) {
        loopArtnetHandler();
    }    
}
