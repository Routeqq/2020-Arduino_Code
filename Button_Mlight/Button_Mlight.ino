#define BLYNK_PRINT Serial
#include <Bridge.h>
#include<SoftwareSerial.h>
#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

char auth[]="673a3330bbf04ed18cea9c806128cc85";


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Blynk.begin(auth);

}

void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
}
