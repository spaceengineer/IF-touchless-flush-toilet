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
    Serial.println("Sensor active");

    myservo.write(140);  // Move servo
    delay(3000);         // Allow servo to move

    myservo.write(180);  // Move servo back
    delay(3000);
  } else {
    digitalWrite(relayPin, LOW);
  }
}
