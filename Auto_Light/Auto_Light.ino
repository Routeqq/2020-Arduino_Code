#include <Servo.h>
Servo sev;

int ehco = 7;
int tri = 8;

void setup() {
 pinMode(ehco, INPUT);
 pinMode(tri, OUTPUT);
 Serial.begin(9600);
 sev.attach(9);
}

void loop() {
  digitalWrite(tri, LOW);
  digitalWrite(ehco, LOW);
  delayMicroseconds(2);
  digitalWrite(tri, LOW);
  delayMicroseconds(10);
  digitalWrite(tri, HIGH);
  
  unsigned long di = pulseIn(ehco, HIGH);
  float distance = ((float)(340*di)/1000)/2;
  Serial.print(distance);
  Serial.println("cm");
  
  if(distance <= 300){
    sev.write(180);
    delay(1000);
    sev.write(0);
    delay(1000);

  }

  
}
