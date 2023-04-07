#include <motorHandler.h>

uint8_t pinOpen = D0;   
uint8_t pinClose = D4;
uint tolerance = 200;   // not used for now
ulong totalTime = 20000;

ulong startTime = 0;
ulong endTime = 0;
uint8_t startPosition = 0;
uint8_t goalPosition = 0;

/*
* This function is called once at the start of the program.
* It sets up the pins and the variables by getting information from the settings.
*/
void setupMotorHandler() {
    pinOpen = getOpenPort();
    pinClose = getClosePort();
    totalTime = getTotalTime();
    tolerance = getTolerance();
    
    pinMode(pinOpen, OUTPUT);
    pinMode(pinClose, OUTPUT);
    digitalWrite(pinOpen, HIGH);
    digitalWrite(pinClose, HIGH);

    Serial.println("MotorHandler setup complete");
}

/*
* This function is called when the curtain should move to a new position.
* It sets the values which are checked in the motor loop later on.
* TODO: Make movements incremental to DMX value
*/
void setRelativePosition(uint8_t value) {
    if (value > 1 && startTime == 0) {
        startTime = millis();
        endTime = startTime + totalTime;
        goalPosition = value;
    }
}

/*
* This function is called in the main loop to handle the motor.
* It makes sure the motor is only moving when it should and stops it when it should.
*/
void loopMotorHandler(){
    if (startTime != 0) { // if startTime is 0, the motor is not moving
        if (millis() >= endTime || goalPosition == 0) { // check if the motor should stop
            digitalWrite(pinOpen, LOW);
            digitalWrite(pinClose, LOW);
            startTime = 0; // indicate that the motor is not moving
            endTime = 0; // indicate that the motor is not moving
            startPosition = goalPosition; // prepare for next movement
        } else if (goalPosition > startPosition) { // check if the motor is going in the right direction
            digitalWrite(pinOpen, HIGH);
            digitalWrite(pinClose, LOW);
        } else {    // check if the motor is going in the right direction
            digitalWrite(pinOpen, LOW);
            digitalWrite(pinClose, HIGH);
        }
    }
}