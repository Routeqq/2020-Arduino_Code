#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial btSerial(2, 3);//TX , RX 순서
Servo sev;//왼쪽
Servo sevv;//오른쪽


byte buffer[1024];//데이터 수심 버퍼
int bufferPo;// buffer 저장할 위치

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
btSerial.begin(9600);

sev.attach(5);//왼쪽발
sevv.attach(6);//오른쪽발

bufferPo = 0;//버퍼초기화

}

void loop() {
  if(btSerial.available()) { //그냥 무조건 써 
  byte data = btSerial.read();
  buffer[bufferPo++] = data;

  if( data == '1' ){ //왼쪽 발
    sev.write(180);
    sevv.write(0);
   btSerial.print("[MBot-S] 좌회전!");
  }

  if( data == '2' ){ //오른쪽 발
    sevv.write(180);
    sev.write(0);
 btSerial.print("[MBot-S] 우회전!");
  }
  
}
}
