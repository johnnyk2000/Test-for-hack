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
    readPos = char(SerialBT.read()); //read in one and store it in readIn
        //SerialBT.write(Serial.read());
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





// PROCESSING CODE
import processing.serial.*;  //imports library used for wireless comm with the HC-05
Serial myPort;               // declares Serial Port object from library
String Text = "Welcome";

void setup()
{
 size(900,1000);                         // create window of this size
 myPort=new Serial(this, "COM14", 115200);  //COM port will likely be different, try different ones until it works (usually one of COM3-COM7)
 myPort.bufferUntil('\n');               //delays calling serialEvent unitl reaching '\n'
}



void serialEvent(Serial myPort){        //serialEvent is called whenever data is available
  Text = myPort.readStringUntil('\n');   //reads Serial.println() from Arduino
}


int state = 0;
int x = 0;


void draw()
{

  background(237,240,241);        // sets background to a color, parameters correspond to an RGB code
  fill(20,160,133);               // sets color we will use to fill shapes
  stroke(33);                     // sets color used for border around shapes
  strokeWeight(1);                // sets width of stroke when drawing shapes
  
 
  fill(0);
  textSize(32);
  text(Text, 400, 700);           //draws text at x,y
    
  if (state == 1) {
    myPort.write('o');            //writes to the Bluetooth Serial port
    state = 0;
  }
  else if (state == 2) { //MAY HAVE TO CHANGE STATE NUMBERS IN COMBINED PROGRAM
    myPort.write('p');
    state = 0;
  }
}
  
  void keyPressed() {               //called whenever a key is pressed, key is automatically set to the key that is pressed
  
  if(key == 'o')
  {
    //move forward
    state = 1;
  }
  else if (key == 'p')
  {
    //move backward
    state = 2;
  }
}
  
  
