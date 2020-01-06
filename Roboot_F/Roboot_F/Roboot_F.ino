#include <Servo.h>
Servo sev;
Servo sevv;
#include <SoftwareSerial.h>
SoftwareSerial btSerial(2, 3);//TX , RX 순서

#include <Stepper.h>
#define GSR 32*64
#define Steps_one_Revolution 32
Stepper sep(Steps_one_Revolution, 11, 10, 9, 8);// IN4, IN2, IN3, IN1

byte buffer[1024];//데이터 수심 버퍼
int bufferPo;// buffer 저장할 위치

void setup() {
  Serial.begin(9600);//시리얼 불러오기
  btSerial.begin(9600); //bt시리얼 불러오기
  sev.attach(5);//5번핀에 서보모터 연결 하체
  sevv.attach(6);//6번친에 서보모터 연결 상체

  bufferPo = 0;//버퍼초기화
 
}

void loop() {
  if(btSerial.available()) { //그냥 무조건 써
    
  byte data = btSerial.read();
  buffer[bufferPo++] = data;
    
    if(data == '0'){//몸회전
      sep.step(GSR/2);
       sep.setSpeed(700);
        sev.write(180);
       btSerial.print("[M-Robot] 몸을 왼쪽으로 돌렸습니다!");
     
    }
    if(data == '1'){//오른쪽 몸회전
       sep.step(-GSR/2);
       sep.setSpeed(700);
        sev.write(180);
       btSerial.print("[M-Robot] 몸을 오른쪽으로 돌렸습니다!");
       
    }

    if(data == '2'){//집게 닫기 
      sevv.write(180);
       btSerial.print("[M-Robot] 집게를 닫았습니다!");
    }
    
    if( data == '3'){//집게 열기
      sevv.write(0);     
      btSerial.print("[M-Robot] 집게 열었습니다!");
    }

    if(data == '4'){
      sev.write(180);
      btSerial.print("M-Robot] 팔을 올렸습니다!");
    }

       if(data == '5'){
      sev.write(0);
      btSerial.print("M-Robot] 팔을 내렸습니다!");
    }
  }
}
