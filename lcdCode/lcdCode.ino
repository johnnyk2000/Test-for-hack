#include "LCDFunctions.h"
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
    
turningRightSequence(): Robot face will be looking to the right and it will
            shift to the right until it reaches the edge, in which
                        the face will reapear from the left edge. 
                        One loop will be until face returns to original pos
  - Used when Block-E is turing to the right
    
turningLeftSequence(): Robot face will be looking to the left and it will
            shift to the left until it reaches the edge, in which
                        the face will reapear from the right edge. 
                        One loop will be until face returns to original pos
  - Used when Block-E is turing to the left
    
danceFaceSequence(): Robot face will shift from middle to edge to edge to middle while switching eyes,
           expressing Block-E's excitement while he dances.
  - Used when Block-E is dancing


Different actions for uart_recieve message char receieved:

'm' : Moving; Call smileBlinkSequence()
'r' : Stop; Call restSequence()
'f' : Turning left; Call turningLeftSequence()
'g' : Turning right; Call turningRightSequence()
'v' : Picking up: Call sweatingFaceSequence()
'b' : Dance: Call danceFaceSequence()


*/

void setup() {
  lcd.begin(16, 2);
  lcd.home();
  Serial.begin(115200);
  while(!Serial){
    ;//wait for serial part to connect. Needed for native USB port only
  }
}

char uart_receive; //Define char variable that will store char from ESP32

void loop() {
  if(Serial.available()) {
    uart_receive = char(Serial.read()); //Read the char recieved from ESP32
  }

  if(uart_receive == 'm')
  {
    smileBlinkSequence();
  }
  else if (uart_receive == 'b')
  {
    danceFaceSequence();
  }
  else if (uart_receive == 'f')
  {
    turningLeftSequence();
  }
  else if (uart_receive == 'g')
  {
    turningRightSequence();
  }
  else if (uart_receive == 'v')
  {
    sweatingFaceSequence();
  }
  else
  {
    restSequence();
  }  

  delay(2000);  //delay needed because there's only one Serial(Slow transmission of data)
                //Or else next data will start uploading before previous one is finished

}
