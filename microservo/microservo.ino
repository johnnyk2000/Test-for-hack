#include "BluetoothSerial.h"
#include <Servo_ESP32.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)           //error catching
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT; //Bluetooth Connection

static const int leftArmPin = 14;
static const int rightArmPin = 32;

Servo_ESP32 leftArm;
Servo_ESP32 rightArm;

int leftServoAngle =90;
int leftServo1AngleMin =0;
int leftServo1AngleMax = 180;
//int righttServoAngle =90;
//int rightServo1AngleMin =0;
//int rightServo1AngleMax = 180;

char readPos;

void setup() {
  // put your setup code here, to run once:
  //pinMode(rightArm, OUTPUT);
  //pinMode(leftArm, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("Maniac arms");
  Serial.println("Started successfully.");

  //digitalWrite(rightArm, LOW);
 //digitalWrite(leftArm, LOW);

  leftArm.attach(leftArmPin);
  rightArm.attach(rightArmPin);
}


void loop() {
  // put your main code here, to run repeatedly:
   if (SerialBT.available()) { //if there are bytes available in the buffer
    //readIn = char(SerialBT.read()); //read in one and store it in readIn
        SerialBT.write(Serial.read());
  }
  if (readPos == 'o') {
    rightArm.write(leftServo1AngleMin);
    leftArm.write(leftServo1AngleMin);

    Serial.println("Neutral Position");
  }
  else if (readPos == 'p') {
        rightArm.write(leftServo1AngleMax);
        leftArm.write(leftServo1AngleMax);
    Serial.println("Lifted Position");

  }

  delay(100);
}
