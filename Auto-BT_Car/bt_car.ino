#include <SoftwareSerial.h>
SoftwareSerial bt(2, 3);//TX, RX
byte buffer[1024];
int bufferPo;

#include <Servo.h>
Servo sev;

//1번모터
int dc1 = 6;
int dc2 = 7;

//2번모터
int dc3 = 8;
int dc4 = 9;

//초음파센서
int echo = 12;
int tri = 13;

//소리센서
int sound = A0;
int SafeSound = 60;//큰소리감지

//mode
int i = 1;

//부저
int BackSound = 10;

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  bufferPo = 0;

  pinMode(BackSound, OUTPUT);

  pinMode(sound, INPUT);
  
  pinMode(dc1, OUTPUT);
  pinMode(dc2, OUTPUT);
  
  pinMode(dc3, OUTPUT);
  pinMode(dc4, OUTPUT);

  pinMode(echo, INPUT);
  pinMode(tri, OUTPUT);

  sev.attach(4);//앞바퀴 방향 조절
}




void loop() {
  digitalWrite(tri, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(tri, LOW);
  delayMicroseconds(10);
  digitalWrite(tri, HIGH);
  unsigned long di = pulseIn(echo, HIGH);
  float distance = ((float)(340*di)/1000)/2;//음속: 340
  
  int SoundRead = analogRead(sound);
  Serial.println(SoundRead);
  delay(100);
  if(SoundRead > SafeSound){
    Mstop();
    Mfront();
    i=0;
    bt.println("[MCar] 비명소리가 들려 차를 긴급정지 합니다.");
  }else{
    if( i == 1 ){
    Mstart();
    Mfront();
  if( distance < 200 ){
    Mstop();
    delayMicroseconds(10);
  }
  if( distance < 300 ){
    Mback();
    tone(BackSound, 2000, 200);
    delay(1000);
  if( distance < 300 ){
    Mleft();
    delay(1000);
   if( distance < 300 ){
     Mright();
     Mstart();
     delay(1000);
    }
   }
  }
 }     
}
  if (bt.available()) {   
    byte btRead = bt.read();
    buffer[bufferPo++] = btRead;
  
    if( btRead == '0'){//전진
      Mstart();
    }
    
    if( btRead == '1'){//후진
      Mback();
    }
    
    if( btRead == '2'){//왼쪽
      Mleft();
    }
    
    if( btRead == '3'){//오른쪽
      Mright();
    }

    if( btRead == '4'){//정지
      Mstop();
    }
    
    if( btRead == '5'){//전면
      Mfront();
    }
    if( btRead == '6'){//자율모드
      i=1;
      tone(BackSound, 3000, 1000);
      bt.println("[MCar]자율주행모드로 전환합니다.");
    }
    if( btRead == '7'){//조종모드
      i=0;
      tone(BackSound, 3000, 1000);
      Mstop();
      bt.println("[MCar]조종모드로 전환합니다.");
    }        
  }  
}

void Mstart(){
  digitalWrite(dc1, LOW);
  digitalWrite(dc2, HIGH);
  digitalWrite(dc3, HIGH);
  digitalWrite(dc4, LOW);
}

void Mback(){
  digitalWrite(dc1, HIGH);
  digitalWrite(dc2, LOW);
  digitalWrite(dc3, LOW);
  digitalWrite(dc4, HIGH);
}

void Mstop(){
  digitalWrite(dc1, LOW);
  digitalWrite(dc2, LOW);
  digitalWrite(dc3, LOW);
  digitalWrite(dc4, LOW);
}

void Mright(){
  sev.write(120);
  digitalWrite(dc1, HIGH);
  digitalWrite(dc2, LOW);
  digitalWrite(dc3, LOW);
  digitalWrite(dc4, LOW);
}

void Mleft(){
  sev.write(70);
  digitalWrite(dc3, LOW);
  digitalWrite(dc4, HIGH);
  digitalWrite(dc1, LOW);
  digitalWrite(dc2, LOW);
}

void Mfront(){
  sev.write(95);
}
