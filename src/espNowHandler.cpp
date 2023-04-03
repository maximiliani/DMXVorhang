#include <espnowhandler.h>

typedef struct dmxData {
    int address;
    int value;
} dmxData;

uint8_t *ownMac = fromMacAddressString(WiFi.macAddress());
uint8_t dmxRecvAddress = 1;

bool checkPeer(const uint8_t *mac_addr) {
    for (int i = 0; i < 6; i++) if (mac_addr[i] != ownMac[i]) return false;
    return true;
}

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