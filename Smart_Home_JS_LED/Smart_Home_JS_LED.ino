int LED = 13;
int JS = A0;
void setup() {

  pinMode(JS,INPUT);
  pinMode(LED,OUTPUT);
}

void loop() {
 
  int JSR = analogRead(JS);
  if(JSR < 950)
  digitalWrite(LED,HIGH);
  else
  digitalWrite(LED,LOW);
  

}
