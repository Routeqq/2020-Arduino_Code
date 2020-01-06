#include <Servo.h>
Servo sev;

#include <Stepper.h>
const int stepsPerRevolution = 2048;  //2048한바퀴, 1024반바퀴
Stepper sep(stepsPerRevolution, 11, 9, 10, 8);  // IN4, IN2, IN3, IN1

#include <SoftwareSerial.h>
SoftwareSerial btSerial(2, 3);//TX , RX 순서

byte buffer[1024];//데이터 수심 버퍼
int bufferPo;// buffer 저장할 위치

int led = 7;//led핀
int pdo = 6;//경보감지 적외선 센서 핀
int pei = 5;//피에조 부저 소리

void setup() {
  Serial.begin(9600);//시리얼 불러오기
  btSerial.begin(9600); //bt시리얼 불러오기
  sep.setSpeed(18);//스텝 모터속도

  sev.attach(13);//문열리게 서보모터!
  pinMode(led, OUTPUT);
  pinMode(pdo, INPUT);
  pinMode(pei, OUTPUT);
}

void loop() {
   long pdoR = digitalRead(pdo);
   
   if(btSerial.available()) { //그냥 무조건 써
    byte data = btSerial.read();
    buffer[bufferPo++] = data;
    int i = 0;
    int j = 0;
    if(data == '1'){//차고올리기
      i = 0;
      if( i == 0 ){
       sep.step(stepsPerRevolution);
         delay(100);
       sep.step(stepsPerRevolution);
         delay(100);
       sep.step(stepsPerRevolution);
         delay(100);
       sep.step(stepsPerRevolution);
      }   
    }
    
    if(data == '2'){ // 차고 내리기
      i = 1;
     if( i == 1 ){
       sep.step(-stepsPerRevolution);
         delay(100);
       sep.step(-stepsPerRevolution);
         delay(100);
       sep.step(-stepsPerRevolution);
         delay(100);
       sep.step(-stepsPerRevolution);
    }
    }

    if(data == '3'){//문열기
      j = 1; //보안풀림
      sev.write(0);
      digitalWrite(led, HIGH);
      delay(5000);//5초뒤
      sev.write(180);
      digitalWrite(led, LOW);
    }
   }
   if(pdoR == 0){
        digitalWrite(led, HIGH);
        btSerial.println("[도어락] 침입자 발생!!");
        tone(pei, 1000);
        delay(500);
        digitalWrite(led, LOW);
        btSerial.println("[도어락] 침입자 발생!!");
        tone(pei, 1000);
        delay(500);      
}else{
  noTone(pei);
}
}
