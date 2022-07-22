
#include <Servo.h>

Servo microServo1;
Servo microServo2;
int val1;
int potpin1 = 0;

int val2;
int potpin2 = 0;


void setup() {
  microServo1.attach(9);
  microServo2.attach(10);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val1 = analogRead(potpin1);
  val1 = map(val1, 0, 1023, 0, 250);
  Serial.println(val1);
  microServo1.write(val1);

  val2 = analogRead(potpin2);
  val2 = map(val2, 0, 1023, 0, 250);
  Serial.println(val2);
  microServo2.write(val2);
  
  delay(200);
  
}
