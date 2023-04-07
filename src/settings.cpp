#include <settings.h>

const int capacity = 2*JSON_OBJECT_SIZE(16) + 16;
StaticJsonDocument <capacity> doc;
bool reloadFromDisk = true;

/*
* This method converts a MAC address consisting of 6 byte uint8_t array to a string.
*/
String toMacAddressString(uint8_t mac[6]) {
    String result = "";
    for (int i = 0; i < 6; i++) {
        result += String(mac[i], HEX);
        if (i < 5) result += ":";
    }
    return result;
}


/*
* This method converts a MAC address string to a 6 byte uint8_t array.
*/
uint8_t *fromMacAddressString(String mac) {
    uint8_t *result = new uint8_t[6];
    for (int i = 0; i < 6; i++) {
        result[i] = (uint8_t) strtol(&mac.substring(i * 3, i * 3 + 2)[0], NULL, 16);
    }
    return result;
}

/*
* This method reads the content of a file from the SPIFFS and returns it as a string.
*/
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

/*
* This method writes a string to a file on the SPIFFS.
*/
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

/*
* This method updates the current settings.
* If the reboot parameter is true, the ESP will restart after the settings have been updated.
* This is used for updates via the REST-API or the web interface.
*/
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

/*
* This method returns the current settings as a StaticJsonDocument.
* Therefore it is possible to easily access the settings.
*/
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

/*
* This method returns the current settings as a JSON string.
* It uses getSettingsJSON() to get the current settings.
*/
String getJSONString() {
    String result = "";
    serializeJson(getSettingsJSON(), result);
    return result;
}

/*
* This method returns the WiFi SSID (network name).
* It is usable for both AP and client mode.
*/
const char *getSSID() {
    return doc["ssid"];
}

/*
* This method returns the WiFi password.
* It is usable for both AP and client mode.
*/
const char *getPassword() {
    return doc["password"];
}

/*
* This method returns the current mode the ESP is in.
*/
MODES getMode() {
    uint mode = doc["mode"];
    return MODES(mode);
}

/*
* This method returns the MQTT topic to subscribe to.
*/
const char *getMQTTTopic() {
    return doc["mqttTopic"];
}

/*
* This method returns the MQTT server address.
*/
const char *getMQTTServer() {
    return doc["mqttServer"];
}

/*
* This method returns the MQTT server port.
*/
uint getMQTTPort() {
    return doc["mqttPort"];
}

/*
* This method returns the GPIO port to open the curtain.
* It has to be a port number (not something like D1, D4, ...)
*/
uint8_t getOpenPort() {
    return doc["openPort"];
}

/*
* This method returns the GPIO port to close the curtain.
* It has to be a port number (not something like D1, D4, ...)
*/
uint8_t getClosePort() {
    return doc["closePort"];
}

/*
* This method returns the total time the curtain needs to open or close.
*/
uint getTotalTime() {
    return doc["totalTime"];
}

/*
* This method returns the tolerance for the curtain.
* The tolerance is the maximum difference between the current position and the target position to consider the curtain as "at the target position".
* Currently the tolerance isn't used yet, but is considered for future versions.
*/
uint getTolerance() {
    return doc["tolerance"];
}

/*
* This method returns the DMX address of the curtain.
* It is used to determine on which address the curtain is listening for DMX commands.
*/
uint8_t getDMXAddress() {
    return doc["dmxAddress"];
}

/*
* This method returns the Art-Net universe of the curtain.
* It is used to determine on which universe the curtain is listening for Art-Net commands.
*/
uint16_t getArtnetUniverse() {
    return doc["artnetUniverse"];
}

/*
* This method is executed when the ESP starts.
* It loads the settings from the SPIFFS and sets the current settings.
*/
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
