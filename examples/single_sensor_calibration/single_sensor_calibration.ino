#include <Calibrator.h>

Calibrator calibrator;

int sensorPin = A0; // The sensor we want to calibrate
int ledPin = 13;    // Will indicate when calibration is going on

void setup()
{
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH); // Turn LED on
    Serial.begin(9600);
    
    // Reset the calibrator. You only need to call reset() if you restart calibration again but
    // if calibration is only run once like in this example is not needed. It doesn't hurt to 
    // call it here though. 
    calibrator.reset();
    
    // Run calibration automatically during the first 
    // five seconds (or 5000 milliseconds) your code runs.
    // It is important that during calibration you "exercise" your sensors to measure both 
    // ends of their range.
    while (millis() < 5000) {
        calibrator.setValue(analogRead(sensorPin));
    }
    digitalWrite(ledPin, LOW); // Turn LED off
}

void loop()
{
    // In your code analogRead(sensorPin) will give you the uncalibrated value
    // and calibrator.getValue(analogRead(sensorPin)) will give you the calibrated value 
    
    Serial.print("Sensor value: ");
    Serial.print(analogRead(sensorPin));
    Serial.print(" , Calibrator value: ");
    Serial.println(calibrator.getValue(analogRead(sensorPin)));
}



