#include <SoftwareSerial.h>
SoftwareSerial btSerial(2, 3); // TX, RX

int i;
int Sound = A0; //소리센서 8번핀

byte buffer[1024];//데이터 수심 버퍼
int bufferPo;// buffer 저장할 위치

void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);
  pinMode(Sound, INPUT);
  bufferPo = 0; //버퍼 초기화
}
void loop() {
  long sss = analogRead(Sound);//아날로그로 읽은값 저장
  if(btSerial.available()) { // 만약 블루투스 신호가 정상적으로 된다면
  byte data = btSerial.read();//data를 btSerial에서 읽은값으로 저장
  buffer[bufferPo++] = data;

  if(data == '0'){//소리 감지 가능
    i = 0;
    btSerial.print("[ 버물리 ] 데시벨 측정 사용 가능합니다!");
  }
  if(data == '1'){
    i=1;
    btSerial.print("[ 버물리 ] 데시벨 측정 사용을 멈췄습니다!");
  }

   if( i == 0){
    btSerial.print("("); 
     btSerial.print(sss); 
     btSerial.print(")"); 
     btSerial.print(" : dB");
    }
   }
  }
