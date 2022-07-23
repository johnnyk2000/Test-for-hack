
// motor code
int in1 = 2;
int in2 = 4; 
int enA = 3;

int in3 = 5; 
int in4 = 7;
int enB = 6;

void setup() {
  Serial.begin(115200);
  while (!Serial){
   ;
  }
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

char uart_receive;

void loop() {
  
  if (Serial.available()){
    uart_receive = char(Serial.read());
  }
  Serial.println("Msg received: ");
  Serial.println(uart_receive);
    
  delay(2000);

  if (Serial.available())
  {
    moveForward();
    stop();
    moveBackward();
    moveForward();
  }

  delay(2212);
}

void moveForward(){
  Serial.println("move forward");
  digitalWrite(in1, HIGH);  //move forwards for 1.5 secs
  digitalWrite(in2, LOW); 
  digitalWrite(in3, HIGH); 
  digitalWrite(in4, LOW); 
  digitalWrite(enA, 100); 
  digitalWrite(enB, 100); 
  delay(1500);
}

void moveBackward(){
  Serial.println("move backwards");
  digitalWrite(in1, LOW);  //moves backward for 1.5 sec
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, LOW); 
  digitalWrite(in4, HIGH); 
  digitalWrite(enA, 100); 
  digitalWrite(enB, 100); 
  delay(1500);
}

void stop(){
  Serial.println("Stops");
  digitalWrite(in1, LOW); //stops for 1.5 secs
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW); 
  digitalWrite(in4, LOW); 
  digitalWrite(enA, 0); 
  digitalWrite(enB, 0); 
  delay(1500);
}
