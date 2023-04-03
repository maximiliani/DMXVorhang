// Created by Maximilian Inckmann on 27.10.22

#include <settings.h>
// #include <FS.h>
#include <LittleFS.h>
#include <ESP8266WiFi.h>

const int capacity = 2*JSON_OBJECT_SIZE(16) + 16;
StaticJsonDocument <capacity> doc;
bool reloadFromDisk = true;

String toMacAddressString(uint8_t mac[6]) {
    String result = "";
    for (int i = 0; i < 6; i++) {
        result += String(mac[i], HEX);
        if (i < 5) result += ":";
    }
    return result;
}

uint8_t *fromMacAddressString(String mac) {
    uint8_t *result = new uint8_t[6];
    for (int i = 0; i < 6; i++) {
        result[i] = (uint8_t) strtol(&mac.substring(i * 3, i * 3 + 2)[0], NULL, 16);
    }
    return result;
}

String readFileFromSPIFFS(const char *name) {
    String result = "";
    // File file = SPIFFS.open(name, "r");
    File file = LittleFS.open(name, "r");
    if (!file) {
        Serial.println("Failed to open file for reading");
        return "";
    }
    while (file.available()) {
        result += (char) file.read();
    }
    file.close();
    return result;
}

void writeFileToSPIFFS(const char *name, String content) {
    // File file = SPIFFS.open(name, "w");
    File file = LittleFS.open(name, "w");
    if (!file) {
        Serial.println("Failed to open file for writing");
        return;
    }
    if (file.print(content)) {
        Serial.println("File written");
    } else {
        Serial.println("Write failed");
    }
    file.close();
}

void setJSON(String serializedJSON, bool reboot) {
    Serial.println("Changing settings to: " + serializedJSON);
    DeserializationError err = deserializeJson(doc, serializedJSON);
    if (err) {
        Serial.print(F("deserializeJson() failed with code "));
        Serial.println(err.f_str());
        Serial.println("Capacity: " + String(capacity));
        doc = StaticJsonDocument <capacity>();
        doc["mode"] = ESPNOW;
        doc["ssid"] = "DMXVorhang - " + String(WiFi.macAddress());
        doc["password"] = defaultPassword;
        doc["mqttServer"] = "none";
        doc["mqttPort"] = 1883;
        doc["mqttTopic"] = "none";
        doc["openPort"] = 2;
        doc["closePort"] = 16;
        doc["totalTime"] = 20000;
        doc["tolerance"] = 100;
        doc["dmxAddress"] = 1;
    }
    writeFileToSPIFFS("/settings.json", serializedJSON);
    if (reboot) ESP.restart();
}

StaticJsonDocument <capacity> getSettingsJSON() {
    if (reloadFromDisk) {
        String raw = readFileFromSPIFFS("/settings.json");
        setJSON(raw);
        reloadFromDisk = false;
    }
    StaticJsonDocument <capacity> tempDoc;
    tempDoc["mode"] = doc["mode"];
    tempDoc["ssid"] = doc["ssid"];
    tempDoc["password"] = doc["password"];
    tempDoc["mqttServer"] = doc["mqttServer"];
    tempDoc["mqttPort"] = doc["mqttPort"];
    tempDoc["mqttTopic"] = doc["mqttTopic"];
    tempDoc["openPort"] = doc["openPort"];
    tempDoc["closePort"] = doc["closePort"];
    tempDoc["totalTime"] = doc["totalTime"];
    tempDoc["tolerance"] = doc["tolerance"];
    tempDoc["dmxAddress"] = doc["dmxAddress"];

    return doc;
}

String getJSONString() {
    String result = "";
    serializeJson(getSettingsJSON(), result);
    return result;
}

const char *getSSID() {
    return doc["ssid"];
}

const char *getPassword() {
    return doc["password"];
}

MODES getMode() {
    uint mode = doc["mode"];
    return MODES(mode);
}

const char *getMQTTTopic() {
    return doc["mqttTopic"];
}

const char *getMQTTServer() {
    return doc["mqttServer"];
}

uint getMQTTPort() {
    return doc["mqttPort"];
}

uint8_t getOpenPort() {
    return doc["openPort"];
}

uint8_t getClosePort() {
    return doc["closePort"];
}

uint getTotalTime() {
    return doc["totalTime"];
}

uint getTolerance() {
    return doc["tolerance"];
}

uint8_t getDMXAddress() {
    return doc["dmxAddress"];
}

void setupSettings() {
    // if (!SPIFFS.begin()) {
    if (!LittleFS.begin()) {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }

    File root = LittleFS.open("/", "w");
    if (!root) {
        Serial.println("- failed to open directory");
        return;
    }
    if (!root.isDirectory()) {
        Serial.println(" - not a directory");
        return;
    }

    File file = root.openNextFile();
    while (file) {
        if (file.isDirectory()) {
            Serial.print("  DIR : ");
            Serial.println(file.name());
        } else {
            Serial.print("  FILE: ");
            Serial.print(file.name());
            Serial.print("\tSIZE: ");
            Serial.println(file.size());
        }
        file = root.openNextFile();
    }
    
    Serial.println("Settings setup complete - JSON: " + getJSONString());
}
