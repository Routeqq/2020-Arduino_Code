#include <Servo.h>
#include <SoftwareSerial.h>
 
Servo sev;//5번
Servo sevv;//6번

SoftwareSerial btSerial(2, 3);//TX , RX 순서

byte buffer[1024];//데이터 수심 버퍼
int bufferPo;// buffer 저장할 
long bd;//아날로그
int cds = A0;


void setup() {
  // put your setup code here, to run once:
pinMode(cds, INPUT);
Serial.begin(9600);
btSerial.begin(9600);

sev.attach(9); // 5번핀에 서보모터 연결 
sevv.attach(10);//6번핀에 연결

bufferPo = 0;//버퍼초기화
}

void loop() {
   bd = analogRead(A0); //읽은값
   
   if(btSerial.available()){//그냥 무조건 써 
   
    byte data = btSerial.read();
    buffer[bufferPo++] = data;
      
   if(data == '9'){//전등확인 버튼 클릭시
    
   if( bd > 20 ){//cds읽은값이 20보다 클때..
    btSerial.print("[M-Helper] 주인님! 불이 켜져있습니다!^   ^\n");
    btSerial.print("주인님!! 전등을 끌건가요?\n");
    btSerial.print("전등켜기/전등끄기 버튼을 눌러주세요!");
   
   }else{
    btSerial.print("[M-Helper] 주인님! 전등이 꺼저있으니 안심하세요!");
   }
   }

   if(data == '1'){//전등끄
    btSerial.print("[M-Helper] 주인님! 전등을 켰습니다!^^");
    sev.write(180);
    delay(1000);
    sev.write(0);
   }
   if(data == '2'){//전등켜
    btSerial.print("[M-Helper] 주인님! 전등을 껏습니다!><");
    sevv.write(0);
    delay(1000);
    sevv.write(180);
   }
   
}
}
