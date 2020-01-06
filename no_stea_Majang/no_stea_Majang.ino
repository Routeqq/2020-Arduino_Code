int TrigPin = 8;
int EchoPin = 9;
int distance;
int Piezo = 7;
int sdi = 30;//기준거리

void setup() {
  // put your setup code here, to run once:
pinMode(TrigPin, OUTPUT);
pinMode(EchoPin, INPUT);
pinMode(Piezo, OUTPUT);
Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(TrigPin, HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin, LOW);

distance = pulseIn(EchoPin, HIGH)/58;
Serial.println(distance);
delay(1000); 

if(distance >= sdi){

 tone(Piezo, 2000, 1000);
}
}
