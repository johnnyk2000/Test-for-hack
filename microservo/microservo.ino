
#include <Servo.h>

Servo microServo;
int pos = 0; //servo position
int val;
int potpin = 0;

void setup() {
  microServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 250);
  Serial.println(val);
  microServo.write(val);
  delay(200);
}
