#include <espnowhandler.h>

/*
* This struct defines the format of the data that is sent over ESP-NOW.
* It consists of a DMX address and a value.
*/
typedef struct dmxData {
    int address;
    int value;
} dmxData;

uint8_t *ownMac = fromMacAddressString(WiFi.macAddress());
uint8_t dmxRecvAddress = 1;

/*
* This function checks if the mac address of the sender is different from the mac address of the ESP we are running on.
* This is important because we use our own MAC address as an indicator for a non-existing device.
* Therefore we don't want to include our own MAC address in the list of devices.
*/
bool checkPeer(const uint8_t *mac_addr) {
    for (int i = 0; i < 6; i++) if (mac_addr[i] != ownMac[i]) return false;
    return true;
}

/*
* This function is called when data is received over ESP-NOW.
* It checks if the address of the data matches the address of the curtain.
* If so it will call the setRelativePosition function to move the curtain.
*/
void OnDataRecv(uint8_t *mac, uint8_t *incomingData, uint8_t len) {
    dmxData tmpData;
    memcpy(&tmpData, incomingData, sizeof(tmpData));
    Serial.print("Bytes received: ");
    Serial.println(len);

    if (tmpData.address == dmxRecvAddress) {
        Serial.println("Address: " + String(tmpData.address) + " " + String(tmpData.value));
        setRelativePosition(tmpData.value);
    }

    Serial.println();
}


/*
* This function is called on startup to setup the ESP-NOW handler.
* It creates a WiFi access point and initializes ESPNow.
*/
void setupESPNOWRecv() {
    Serial.println();
    Serial.print("MAC: ");
    Serial.println(WiFi.macAddress());

    WiFi.mode(WIFI_STA);

    if (esp_now_init() != 0) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    dmxRecvAddress = getDMXAddress();
    esp_now_register_recv_cb(OnDataRecv);
    Serial.println("ESPNOW initialized");
}