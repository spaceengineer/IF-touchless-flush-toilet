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
  myservo.write(180);   // Initial servo position (180 degrees)
  delay(1000);
  myservo.detach();
  digitalWrite(relayPin, LOW);
}

void loop() {
  sensorVal = digitalRead(trig);

  if (sensorVal == HIGH) {
    digitalWrite(relayPin, HIGH);
    Serial.println("Sensor active");
    
    myservo.attach(servoPin);
    myservo.write(140); // Servo position 140 degrees
    delay(2000);        // Wait for 2 seconds

    myservo.write(180); // Servo position back to 180 degrees
    delay(2000);        // Wait for 2 seconds

    myservo.detach();
  } else {
    digitalWrite(relayPin, LOW);
  }
}
