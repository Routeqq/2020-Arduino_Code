#include <Servo.h>
Servo sev;

#include <SoftwareSerial.h>
SoftwareSerial btSerial(2, 3);//TX , RX 순서

byte buffer[1024];//데이터 수심 버퍼
int bufferPo;// buffer 저장할 위치

void setup() {
  Serial.begin(9600);//시리얼 불러오기
  btSerial.begin(9600); //bt시리얼 불러오기
  sev.attach(5);//5번핀에 서보모터 연결
  pinMode(13, OUTPUT);
  pinMode(6, INPUT);

  bufferPo = 0;//버퍼초기화
 
}

void loop() {
  if(btSerial.available()) { //그냥 무조건 써
    
  byte data = btSerial.read();
  buffer[bufferPo++] = data;
    
    if(data == '1'){
      sev.write(180);
      digitalWrite(13, HIGH);
       btSerial.print("[M-Light] 불을 켰습니다!");

    }else if( data == '0'){
      sev.write(0);     
      digitalWrite(13, LOW);
      btSerial.print("[M-Light] 불을 껐습니다!");
    }
  }
}
