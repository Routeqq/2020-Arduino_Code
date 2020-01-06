#include <Servo.h>
Servo sev;

void setup() {
  // put your setup code here, to run once:
sev.attach(5);
Serial.begin(9600);
}

void loop() {
sev.write(180);
delay(1000);
sev.write(0);
delay(1000);
}
