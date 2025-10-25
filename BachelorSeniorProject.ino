#include <NewPing.h>

// IR Sensor Pins
#define SensorLeft 10
#define SensorCenter 11 
#define SensorRight 12

// Right Motor Pins
#define MotorR1 7
#define MotorR2 6 
#define MotorRE 9

// Left Motor Pins
#define MotorL1 4
#define MotorL2 5
#define MotorLE 3

// Ultrasonic Sensor Pins
#define TRIGGER_PIN 8
#define ECHO_PIN 2

#define MAX_DISTANCE 400 // Maximum distance for ultrasonic sensor

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float duration, distance;

void setup() {
    Serial.begin(9600); // Fixed baud rate (was %600)

    // Set sensor pins as INPUT
    pinMode(SensorLeft, INPUT);
    pinMode(SensorCenter, INPUT);
    pinMode(SensorRight, INPUT);

    // Set motor pins as OUTPUT
    pinMode(MotorR1, OUTPUT);
    pinMode(MotorR2, OUTPUT);
    pinMode(MotorRE, OUTPUT);
    pinMode(MotorL1, OUTPUT);
    pinMode(MotorL2, OUTPUT);
    pinMode(MotorLE, OUTPUT);
}

void forward() {
    // Right motor forward
    digitalWrite(MotorR1, HIGH);
    digitalWrite(MotorR2, LOW);
    analogWrite(MotorRE, 250); // Right motor speed 250

    // Left motor forward
    digitalWrite(MotorL1, HIGH);
    digitalWrite(MotorL2, LOW);
    analogWrite(MotorLE, 250); // Left motor speed 250
}

void right() {
    // Right motor stopped
    digitalWrite(MotorR1, HIGH);
    digitalWrite(MotorR2, LOW);
    analogWrite(MotorRE, 0);

    // Left motor forward
    digitalWrite(MotorL1, HIGH);
    digitalWrite(MotorL2, LOW);
    analogWrite(MotorLE, 150); // Left motor speed 150
}

void left() {
    // Right motor forward
    digitalWrite(MotorR1, HIGH);
    digitalWrite(MotorR2, LOW);
    analogWrite(MotorRE, 150); // Right motor speed 150

    // Left motor stopped
    digitalWrite(MotorL1, HIGH);
    digitalWrite(MotorL2, LOW);
    analogWrite(MotorLE, 0);
}

void stop() {
    // Stop both motors
    digitalWrite(MotorR1, HIGH);
    digitalWrite(MotorR2, LOW);
    digitalWrite(MotorRE, LOW);

    digitalWrite(MotorL1, HIGH);
    digitalWrite(MotorL2, LOW);
    digitalWrite(MotorLE, LOW);
}

void loop() {
    distance = sonar.ping_cm(); // Get distance in cm
    
    Serial.print("Distance = ");
    
    if (distance > 30) { // If distance more than 30 cm proceed
        Serial.print(distance);
        Serial.println(" cm");
        
        // Line following logic
        if (digitalRead(SensorLeft) == 0 && digitalRead(SensorCenter) == 1 && digitalRead(SensorRight) == 0) {
            // Center sensor sees line - go forward
            forward();
        }
        else if (digitalRead(SensorLeft) == 0 && digitalRead(SensorCenter) == 0 && digitalRead(SensorRight) == 1) {
            // Right sensor sees line - turn right
            right();
        }
        else if (digitalRead(SensorLeft) == 1 && digitalRead(SensorCenter) == 0 && digitalRead(SensorRight) == 0) {
            // Left sensor sees line - turn left
            left();
        }
        // Optional: Add condition for all sensors seeing white or all seeing black
    }
    
    if (distance <= 30 && distance >= 2) { // If distance less than or equal to 30 cm, stop
        Serial.println("Stop - Obstacle detected!");
        stop();
    }
    
    delay(500);
}