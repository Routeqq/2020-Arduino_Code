#include <Stepper.h>
const int stepsPerRevolution = 2048;//2048한바퀴, 1024반바퀴
Stepper sep(stepsPerRevolution, 11, 10, 9, 8);// IN4, IN2, IN3, IN1

void setup() {
  pinMode(7, INPUT);
  sep.setSpeed(14);//모터속도
   Serial.begin(9600);
}

void loop() {  
  int ss = digitalRead(7);
  if(ss == LOW){
       sep.step(stepsPerRevolution);
  
}else{
  
}
}
