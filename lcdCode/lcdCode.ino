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

int count;
byte fillWhite[] = { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 };
byte openEye[] = { B11111, B10001, B01100, B01100, B00000, B10001, B11111, B11111 };
byte smile1[] = { B00111, B00011, B10001, B11000, B11100, B11110, B11111, B11111 };
byte smile2[] = { B11111, B11110, B11100, B11000, B00001, B00011, B00111, B11111 };
byte smile3[] = { B11111, B01111, B00111, B00011, B10000, B11000, B11100, B11111 };
byte smile4[] = { B11100, B11000, B10001, B00011, B00111, B01111, B11111, B11111 };

void setup() {
  lcd.begin(16, 2);
  lcd.home();
  Serial.begin(9600);
}

void loop() {
  
  //code for the eyes
  lcd.createChar(1, openEye);
  lcd.setCursor(5, 0);
  lcd.write(1);
  lcd.setCursor(10, 0);
  lcd.write(1);
  
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
}
