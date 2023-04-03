#include <Arduino.h>
#include <motorHandler.h>
#include <settings.h>

uint8_t pinOpen = D0;
uint8_t pinClose = D4;
uint tolerance = 200;
ulong totalTime = 20000;

ulong startTime = 0;
ulong endTime = 0;
uint8_t startPosition = 0;
uint8_t goalPosition = 0;

void setupMotorHandler() {
    pinOpen = getOpenPort();
    pinClose = getClosePort();
    totalTime = getTotalTime();
    tolerance = getTolerance();
    // currentPosition = 0;
    
    pinMode(pinOpen, OUTPUT);
    pinMode(pinClose, OUTPUT);
    digitalWrite(pinOpen, HIGH);
    digitalWrite(pinClose, HIGH);

    Serial.println("MotorHandler setup complete");
}

void setRelativePosition(uint8_t value) {
    if (value > 1 && startTime == 0) {
        startTime = millis();
        endTime = startTime + totalTime;
        goalPosition = value;
    }
}

void loopMotorHandler(){
    if (startTime != 0) {
        if (millis() >= endTime || goalPosition == 0) {
            digitalWrite(pinOpen, HIGH);
            digitalWrite(pinClose, HIGH);
            startTime = 0;
            endTime = 0;
            startPosition = goalPosition;
        } else if (goalPosition > startPosition) {
            digitalWrite(pinOpen, HIGH);
            digitalWrite(pinClose, LOW);
        } else {
            digitalWrite(pinOpen, LOW);
            digitalWrite(pinClose, HIGH);
        }
    }
}