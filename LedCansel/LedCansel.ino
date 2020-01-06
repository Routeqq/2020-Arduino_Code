int Led = 10;
int yLed = 11;
int bLed = 3;
    int n = 0; //Led M
    int m; //Led inc
    
    
void setup(){
  Serial.begin(9600);
    pinMode(Led, OUTPUT);
     pinMode(yLed, OUTPUT);
      pinMode(bLed, OUTPUT);
 
}

   void loop(){
   

   if(n==0){
  for(m = 0; m <= 255; m += 25){
        analogWrite(Led, m);
        delay(90);
         Serial.print(m);
        }

        for( m = 255; m >= 0; m -= 25){
          analogWrite(Led, m);
          delay(90);
        analogWrite(Led, 0);
        n = 1; 
        }
   }

      if(n==1){
  for(m = 0; m <= 255; m += 25){
        analogWrite(bLed, m);
         analogWrite(yLed, m);
        delay(90);
         Serial.print(m);
        }

        for( m = 255; m >= 0; m -= 25){
          analogWrite(bLed, m);
           analogWrite(yLed, m);
          delay(90);
          n = 2; 
        analogWrite(bLed, 0);
         analogWrite(yLed, 0);
        }
   }
    }
