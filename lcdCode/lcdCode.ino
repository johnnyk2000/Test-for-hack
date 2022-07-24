// C++ code
//
// include the library code:


/*
format for creating a custom character:
1. define and initialize array that indicates which pixels will be on/off
2. use the creatChar command and pass custom char # and array as parameters
3. use the setCursor command to indicate the box that you want to place the custom char
   pass the coordinates as parameters
   e.g.) top left will be (0, 0), buttom right will be (1, 15)
4. place the custom char by using the write command
   pass the custom char # as parameter
   - If we want to pass the same char but in a different box, you could 
     set the cursor to the desired box and use the write command again passing
     the same custom char #

Other stuff: The max amount of custom characters you can create and display is 8
*/

#include <LiquidCrystal.h>

const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Code that indicates the on/off of each pixel in a single box(a.k.a. designs of custom characters)
//------------------------------------------------------------------------------------
//fill white pixels to entire box
byte fillWhite[] = { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 };

//closed eyes left middle and right side (across three boxes)
byte eyeLeft[] = { B11111, B11111, B11111, B11100, B11100, B11111, B11111, B11111 };
byte eyeMiddle[] = { B11111, B11111, B11111, B00000, B00000, B11111, B11111, B11111 };
byte eyeRight[] = { B11111, B11111, B11111, B00111, B00111, B11111, B11111, B11111 };

//opened eyes (fits in one box)
byte openEye[] = { B11111, B10001, B01100, B01100, B00000, B10001, B11111, B11111 };
byte openEyeLow[] = { B11111, B11111, B10001, B01100, B01100, B00000, B10001, B11111 };

//crying eye left and right versions
byte cryEyeLeft[] = { B11111, B00111, B11001, B11110, B00000, B11110, B11001, B00111 };
byte cryEyeRight[] = { B11111, B11100, B10011, B01111, B00000, B01111, B10011, B11100 };

//broken x mark eye(takes one box)
byte xEyes[] = { B11111, B11111, B01110, B10101, B11011, B10101, B01110, B11111 };

//smiles from left to right (across four boxes)
byte smile1[] = { B00111, B00011, B10001, B11000, B11100, B11110, B11111, B11111 };
byte smile2[] = { B11111, B11110, B11100, B11000, B00001, B00011, B00111, B11111 };
byte smile3[] = { B11111, B01111, B00111, B00011, B10000, B11000, B11100, B11111 };
byte smile4[] = { B11100, B11000, B10001, B00011, B00111, B01111, B11111, B11111 };

//unhappy mouth from left to right (across four boxes)
byte cryMouth1[] = { B11111, B11110, B11100, B11000, B10001, B00011, B00111, B11111 };
byte cryMouth2[] = { B00111, B00011, B00001, B11000, B11100, B11110, B11111, B11111 };
byte cryMouth3[] = { B11100, B11000, B10000, B00011, B00111, B01111, B11111, B11111 };
byte cryMouth4[] = { B11111, B01111, B00111, B00011, B10001, B11000, B11100, B11111 };

//sweating mouth (same as cryMouth except middle 2 boxes)
byte sweatMouthMiddle[] = { B11111, B00000, B00000, B11111, B11111, B11111, B11111, B11111 };

//moving eyes
byte movingEyesTopLeft[] = { B11111, B10001, B01100, B01100, B00000, B10001, B11111, B11111 };
byte movingEyesTopRight[] = { B11111, B10001, B00110, B00110, B00000, B10001, B11111, B11111 };
byte movingEyesBottomRight[] = { B11111, B10001, B00000, B00110, B00110, B10001, B11111, B11111 };
byte movingEyesBottomLeft[] = { B11111, B10001, B00000, B01100, B01100, B10001, B11111, B11111 };

//resting sequence
//Realized you can't do under 8 char so scratched and doing somn diff
/*
//1st sequence
//Eyes
byte restEyeLeft1 = { B11111, B11111, B11111, B11100, B11100, B11111, B11111, B11111 };
byte restEyeMiddle1 = { B11111, B11111, B11111, B00000, B00000, B11111, B11111, B11111 };
byte restEyeRight1 = { B11111, B11111, B11111, B00111, B00111, B11111, B11111, B11111 };
//Mouth
byte restSmile1[] = { B00111, B00011, B10001, B11000, B11100, B11110, B11111, B11111 };
byte restSmile2[] = { B11111, B11110, B11100, B11000, B00001, B00011, B00111, B11111 };
byte restSmile3[] = { B11111, B01111, B00111, B00011, B10000, B11000, B11100, B11111 };
byte restSmile4[] = { B11100, B11000, B10001, B00011, B00111, B01111, B11111, B11111 };
//2nd sequence
//Eyes
byte restEyeLeft2[] = { B11111, B11111, B11100, B11100, B11111, B11111, B11111, B11111 };
byte restEyeMiddle2[] = { B11111, B11111, B00000, B00000, B11111, B11111, B11111, B11111 };
byte restEyeRight2[] = { B11111, B11111, B00111, B00111, B11111, B11111, B11111, B00111 };
*/

//sweating sequence
/*
byte sweat1[] = { B11011, B11111, B11111, B11111, B11111, B11111, B11111, B11111 };
byte sweat2[] = { B10001, B11011, B11111, B11111, B11111, B11111, B11111, B11111 };
byte sweat3[] = { B10001, B10001, B11011, B11111, B11111, B11111, B11111, B11111 };
byte sweat4[] = { B11011, B10001, B10001, B11011, B11111, B11111, B11111, B11111 };
byte sweat5[] = { B11011, B11011, B10001, B10001, B11011, B11111, B11111, B11111 };
byte sweat6[] = { B11111, B11011, B11011, B10001, B10001, B11011, B11111, B11111 };
byte sweat7[] = { B11111, B11111, B11011, B11011, B10001, B10001, B11011, B11111 };
byte sweat8[] = { B11111, B11111, B11111, B11011, B11011, B10001, B10001, B11011 };
byte sweat9[] = { B11111, B11111, B11111, B11111, B11011, B11011, B10001, B10001 };
byte sweat10[] = { B11111, B11111, B11111, B11111, B11111, B11011, B11011, B10001 };
byte sweat11[] = { B11111, B11111, B11111, B11111, B11111, B11111, B11011, B11011 };
byte sweat12[] = { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11011 };
*/

//sweating sequence ver2 for upper row box
byte sweat[24][8] = {
{ B11011, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B10001, B11011, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B10001, B10001, B11011, B11111, B11111, B11111, B11111, B11111 },
{ B11011, B10001, B10001, B11011, B11111, B11111, B11111, B11111 },
{ B11011, B11011, B10001, B10001, B11011, B11111, B11111, B11111 },
{ B11111, B11011, B11011, B10001, B10001, B11011, B11111, B11111 },
{ B11111, B11111, B11011, B11011, B10001, B10001, B11011, B11111 },
{ B11111, B11111, B11111, B11011, B11011, B10001, B10001, B11011 },
{ B11111, B11111, B11111, B11111, B11011, B11011, B10001, B10001 },
{ B11111, B11111, B11111, B11111, B11111, B11011, B11011, B10001 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11011, B11011 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11011 },

{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 }
};

//sweating sequence ver2 for lower row box
byte sweat2[24][8] = {
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
  
{ B11011, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B10001, B11011, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B10001, B10001, B11011, B11111, B11111, B11111, B11111, B11111 },
{ B11011, B10001, B10001, B11011, B11111, B11111, B11111, B11111 },
{ B11011, B11011, B10001, B10001, B11011, B11111, B11111, B11111 },
{ B11111, B11011, B11011, B10001, B10001, B11011, B11111, B11111 },
{ B11111, B11111, B11011, B11011, B10001, B10001, B11011, B11111 },
{ B11111, B11111, B11111, B11011, B11011, B10001, B10001, B11011 },
{ B11111, B11111, B11111, B11111, B11011, B11011, B10001, B10001 },
{ B11111, B11111, B11111, B11111, B11111, B11011, B11011, B10001 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11011, B11011 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11011 },
  
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },  
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
{ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
};
//-----------------------------------------------------------------------------------------
//void setup() part
void setup() {
  lcd.begin(16, 2);
  lcd.home();
  Serial.begin(9600);
}
//-----------------------------------------------------------------------------------------
//user-defined functions that regulates the static image of the faces 
//static face for opened eyes
void openEyes()
{
  //code for the eyes
  lcd.createChar(1, openEye);
  lcd.setCursor(5, 0);
  lcd.write(1);
  lcd.setCursor(10, 0);
  lcd.write(1);
  
  lcd.createChar(4, smile1);
  lcd.setCursor(6, 1);
  lcd.write(4);
  
  lcd.createChar(5, smile2);
  lcd.setCursor(7, 1);
  lcd.write(5);
  
  lcd.createChar(6, smile3);
  lcd.setCursor(8, 1);
  lcd.write(6);
  
  lcd.createChar(7, smile4);
  lcd.setCursor(9, 1);
  lcd.write(7);
  
  //holds the num of boxes that has to be filled with white
  int row1FillNum = 14;
  int row2FillNum = 12;
  
  //array of int that hold the position of boxes that has to be filled with white
  int row1Fill[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14, 15};
  int row2Fill[] = {0, 1, 2, 3, 4, 5, 10, 11, 12, 13, 14, 15};
  
  lcd.createChar(8, fillWhite);
  
  //for loop to simplfy process
  for(int i = 0; i < row1FillNum; i++)
  {
  	lcd.setCursor(row1Fill[i], 0);
    lcd.write(8);
  }
  
  for(int i = 0; i < row2FillNum; i++)
  {
  	lcd.setCursor(row2Fill[i], 1);
    lcd.write(8);
  }  
  
  /*
  //Code for filling in gaps with white
  lcd.createChar(8, fillWhite);
  lcd.setCursor(0, 0);
  lcd.write(8);
  lcd.setCursor(1, 0);
  lcd.write(8);
  lcd.setCursor(2, 0);
  lcd.write(8);
  lcd.setCursor(3, 0);
  lcd.write(8);
  lcd.setCursor(7, 0);
  lcd.write(8);
  lcd.setCursor(8, 0);
  lcd.write(8);
  lcd.setCursor(12, 0);
  lcd.write(8);
  lcd.setCursor(13, 0);
  lcd.write(8);
  lcd.setCursor(14, 0);
  lcd.write(8);
  lcd.setCursor(15, 0);
  lcd.write(8);
  lcd.setCursor(0, 1);
  lcd.write(8);
  lcd.setCursor(1, 1);
  lcd.write(8);
  lcd.setCursor(2, 1);
  lcd.write(8);
  lcd.setCursor(3, 1);
  lcd.write(8);
  lcd.setCursor(4, 1);
  lcd.write(8);
  lcd.setCursor(5, 1);
  lcd.write(8);
  lcd.setCursor(10, 1);
  lcd.write(8);
  lcd.setCursor(11, 1);
  lcd.write(8);
  lcd.setCursor(12, 1);
  lcd.write(8);
  lcd.setCursor(13, 1);
  lcd.write(8);
  lcd.setCursor(14, 1);
  lcd.write(8);
  lcd.setCursor(15, 1);
  lcd.write(8);
  
  //code for filling in gaps with white
  //the box for these will change when eyes
  //are closed
  
  lcd.createChar(8, fillWhite);
  lcd.setCursor(4, 0);
  lcd.write(8);
  lcd.setCursor(6, 0);
  lcd.write(8);
  lcd.setCursor(9, 0);
  lcd.write(8);
  lcd.setCursor(11, 0);
  lcd.write(8);
  */
}

//Static face for robot sweating, 
//used when robot is picking up parts
void sweatFace()
{
  //code for the eyes
  lcd.createChar(1, cryEyeLeft);
  lcd.setCursor(5, 0);
  lcd.write(1);
  
  lcd.createChar(2, cryEyeRight);
  lcd.setCursor(10, 0);
  lcd.write(2);
  
  lcd.createChar(3, cryMouth1);
  lcd.setCursor(6, 1);
  lcd.write(3);
  
  lcd.createChar(4, sweatMouthMiddle);
  lcd.setCursor(7, 1);
  lcd.write(4);
  lcd.setCursor(8, 1);
  lcd.write(4);
  
  lcd.createChar(5, cryMouth4);
  lcd.setCursor(9, 1);
  lcd.write(5);
  
  //holds the num of boxes that has to be filled with white
  int row1FillNum = 14;
  int row2FillNum = 12;
  
  //array of int that hold the position of boxes that has to be filled with white
  int row1Fill[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14, 15};
  int row2Fill[] = {0, 1, 2, 3, 4, 5, 10, 11, 12, 13, 14, 15};
  
  lcd.createChar(8, fillWhite);
  
  //for loop to simplfy process
  for(int i = 0; i < row1FillNum; i++)
  {
  	lcd.setCursor(row1Fill[i], 0);
    lcd.write(8);
  }
  
  for(int i = 0; i < row2FillNum; i++)
  {
  	lcd.setCursor(row2Fill[i], 1);
    lcd.write(8);
  }  
}

//static face for robot closed eyes
//used for resting sequence and blinking sequence
void closeEyesFace()
{
  lcd.createChar(1, eyeLeft);
  lcd.setCursor(4, 0);
  lcd.write(1);
  lcd.setCursor(9, 0);
  lcd.write(1);
  
  lcd.createChar(2, eyeMiddle);
  lcd.setCursor(5, 0);
  lcd.write(2);
  lcd.setCursor(10, 0);
  lcd.write(2);
  
  lcd.createChar(3, eyeRight);
  lcd.setCursor(6, 0);
  lcd.write(3);
  lcd.setCursor(11, 0);
  lcd.write(3);
  
  lcd.createChar(4, smile1);
  lcd.setCursor(6, 1);
  lcd.write(4);
  
  lcd.createChar(5, smile2);
  lcd.setCursor(7, 1);
  lcd.write(5);
  
  lcd.createChar(6, smile3);
  lcd.setCursor(8, 1);
  lcd.write(6);
  
  lcd.createChar(7, smile4);
  lcd.setCursor(9, 1);
  lcd.write(7);
  
  //holds the num of boxes that has to be filled with white
  int row1FillNum = 10;
  int row2FillNum = 12;
  
  //array of int that hold the position of boxes that has to be filled with white
  int row1Fill[] = {0, 1, 2, 3, 7, 8, 12, 13, 14, 15};
  int row2Fill[] = {0, 1, 2, 3, 4, 5, 10, 11, 12, 13, 14, 15};
  
  lcd.createChar(8, fillWhite);
  
  //for loop to simplfy process
  for(int i = 0; i < row1FillNum; i++)
  {
  	lcd.setCursor(row1Fill[i], 0);
    lcd.write(8);
  }
  
  for(int i = 0; i < row2FillNum; i++)
  {
  	lcd.setCursor(row2Fill[i], 1);
    lcd.write(8);
  }  
}

//static face for brokenFace
void brokenFace()
{
  //code for the eyes
  lcd.createChar(1, xEyes);
  lcd.setCursor(5, 0);
  lcd.write(1);
  
  lcd.createChar(2, openEyeLow);
  lcd.setCursor(10, 0);
  lcd.write(2);
  
  lcd.createChar(3, cryMouth1);
  lcd.setCursor(6, 1);
  lcd.write(3);
  
  lcd.createChar(4, cryMouth2);
  lcd.setCursor(7, 1);
  lcd.write(4);
  
  lcd.createChar(5, cryMouth3);
  lcd.setCursor(8, 1);
  lcd.write(5);
  
  lcd.createChar(6, cryMouth4);
  lcd.setCursor(9, 1);
  lcd.write(6);
  
  //holds the num of boxes that has to be filled with white
  int row1FillNum = 14;
  int row2FillNum = 12;
  
  //array of int that hold the position of boxes that has to be filled with white
  int row1Fill[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14, 15};
  int row2Fill[] = {0, 1, 2, 3, 4, 5, 10, 11, 12, 13, 14, 15};
  
  lcd.createChar(8, fillWhite);
  
  //for loop to simplfy process
  for(int i = 0; i < row1FillNum; i++)
  {
  	lcd.setCursor(row1Fill[i], 0);
    lcd.write(8);
  }
  
  for(int i = 0; i < row2FillNum; i++)
  {
  	lcd.setCursor(row2Fill[i], 1);
    lcd.write(8);
  }  
}

//user-defined functions of animated sequence of different faces for robot
//-----------------------------------------------------------------------------------------
//animated sequence for robot face while resting
void restSequence()
{
  int closedEyesDur = 5000;
  int openDelay = 250;
  closeEyesFace();
  delay(closedEyesDur);
  openEyes();
  movingEyes();
  closeEyesFace();
  delay(1000);
}

//animated sequence of robot face blinking & smiling while moving
void smileBlinkSequence()
{	
  int openEyesDur = 5000;
  int blinkDelay = 500;
  openEyes();
  delay(openEyesDur);
  closeEyesFace();
  delay(blinkDelay);
  openEyes();
  delay(blinkDelay);
  closeEyesFace();
  delay(blinkDelay);
  openEyes();
  delay(1000);
}

//animated sequence of sweating robot face
//a drip of sweat will appear on edges of face
void sweatingFaceSequence()
{
  sweatFace();
  sweatSequence(2);
  sweatFace();
  sweatSequence(13);
  delay(1000);
}

void movingRightSequence()
{
  
}

void movingLeftSequence()
{
  
}


                    
//animated sequence for sweat drip, used in 
//use custom char # 6 & 7 to avoid overlap
void sweatSequence(int pos)
{
  for (int i = 0; i < 24; i++)
  {
   	lcd.createChar(6, sweat[i]);
    lcd.setCursor(pos,0);
    lcd.write(6);
    lcd.createChar(7, sweat2[i]);
    lcd.setCursor(pos,1);
	lcd.write(7);
    delay(150);
  }
}

//moves the eyes, used in restSequence
void movingEyes()
{
  int dur = 500;
  
  lcd.createChar(2, movingEyesTopLeft);
  lcd.setCursor(5,0);
  lcd.write(2);
  lcd.setCursor(10, 0);
  lcd.write(2);
  delay(dur);
  lcd.createChar(2, movingEyesTopRight);
  lcd.setCursor(5,0);
  lcd.write(2);
  lcd.setCursor(10, 0);
  lcd.write(2);
  delay(dur);
  lcd.createChar(2, movingEyesBottomRight);
  lcd.setCursor(5,0);
  lcd.write(2);
  lcd.setCursor(10, 0);
  lcd.write(2);
  delay(dur*2);
  lcd.createChar(2, movingEyesTopRight);
  lcd.setCursor(5,0);
  lcd.write(2);
  lcd.setCursor(10, 0);
  lcd.write(2);
  delay(dur*2);
  /*
  lcd.createChar(2, movingEyesTopLeft);
  lcd.setCursor(5,0);
  lcd.write(2);
  lcd.setCursor(10, 0);
  lcd.write(2);
  delay(dur);
  */
}

/*
List of functions that will display animated face for different actions

smileBlinkSequence(): Robot face will blink while smiling
	- used when Block-E is moving
sweatingFaceSequence(): Robot face will be looking like he's putting in work
						and there will be sweat dripping 
    - Used when Block_E is picking up parts
restSequence(): Robot face will be closed and open once in a while. Eyes will
				will move around and check for surrounding before closing again
    - Used when Block-E is not doing anything

*/

void loop() {
  
  //smileBlinkSequence();
  //sweatingFaceSequence();
  //restSequence();
}
