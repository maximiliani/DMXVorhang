#include <artnetHandler.h>

Artnet artnet;

void setupArtnetHandler() {
    WiFi.begin(getSSID(), getPassword());

    while (WiFi.status() != WL_CONNECTED) {
        delay(250);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(getSSID());
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    artnet.begin();
}

void loopArtnetHandler() {
    if (artnet.read() == ART_DMX){
        if (artnet.getUniverse() == getArtnetUniverse()){
            uint8_t value = artnet.getDmxFrame()[getDMXAddress() - 1];
            Serial.println("Universe: " + String(artnet.getUniverse()) + " Address: " + String() + " Value: " + String(value));
            setRelativePosition(value);
        }
    }
}