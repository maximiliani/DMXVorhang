#include <artnetHandler.h>

Artnet artnet;

/*
* This function is called on startup to setup the artnet handler
* It will connect to the WiFi and start the artnet handler
*/
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

/*
* This function is called in the main loop to handle the artnet data
* It checks if ArtNet data is available and if the universe and address matches the settings
* If so it will call the setRelativePosition function to move the curtain
*/
void loopArtnetHandler() {
    if (artnet.read() == ART_DMX){
        if (artnet.getUniverse() == getArtnetUniverse()){
            uint8_t value = artnet.getDmxFrame()[getDMXAddress() - 1];
            Serial.println("Universe: " + String(artnet.getUniverse()) + " Address: " + String() + " Value: " + String(value));
            setRelativePosition(value);
        }
    }
}