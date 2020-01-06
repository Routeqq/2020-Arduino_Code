#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
#include <Servo.h>
Servo sev;
int evsoil = 1000;

void setup() {
  // put your setup code here, to run once:
sev.attach(5);
lcd.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int toValue = analogRead(A0);
Serial.println(toValue);
delay(2000);
  if( evsoil < toValue ){
    
  sev.write(180);
  delay(2000);
  sev.write(0);
  

  }

}
