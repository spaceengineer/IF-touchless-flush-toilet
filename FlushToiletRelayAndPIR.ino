#include <Servo.h>

Servo myservo;
const int relayPin = 11;
const int trig = 7;
const int servoPin = 8;
int sensorVal = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(trig, INPUT);
  pinMode(relayPin, OUTPUT);
  
  myservo.attach(servoPin);
  myservo.write(180);   // Set servo to initial position
  delay(1000);
}

void loop() {
  sensorVal = digitalRead(trig);

  if (sensorVal == HIGH) {
    digitalWrite(relayPin, HIGH);
    Serial.println("Sensor active - Moving servo");

    myservo.attach(servoPin); // Ensure servo is connected
    delay(10);

    // Move servo to 140 degrees twice to ensure it moves
    myservo.write(140);
    delay(500);
    myservo.write(140);
    delay(500);

    delay(2000); // Ensure enough time for movement

    // Move back to 180 degrees twice to confirm position
    myservo.write(180);
    delay(500);
    myservo.write(180);
    delay(500);

    delay(2000); // Allow servo to stabilize
    myservo.detach(); // Free up the servo
  } else {
    digitalWrite(relayPin, LOW);
  }
}

