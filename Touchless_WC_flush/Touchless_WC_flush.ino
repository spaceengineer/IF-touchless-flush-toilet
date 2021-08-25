#include <Servo.h>
Servo myservo;
int trig = 4;
int pirState = LOW;
int servo = 9;
int val = 0;

#define TRIGGER_PIN 7
void setup() {

Serial.begin(9600);
pinMode(trig, INPUT);
myservo.attach(servo);

myservo.write(180);   // servo position 180 degree      
delay(1000);
myservo.detach();
}

void loop()
{

val = digitalRead(trig);

if ( val == HIGH ) // change this value to increase or decrease detection range.
{
myservo.attach(servo);
delay(1);
myservo.write(140); //servo position 90 degree if CW servo

delay(2000);
myservo.write(180); //servo position 180 degree
delay(2000);
myservo.detach();
}

}
