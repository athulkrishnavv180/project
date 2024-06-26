int trigpin = 8;
int echopin = 7;
long duration;
int distance;

const int buzzer = 10;

void setup() {
  pinMode (trigpin,OUTPUT);
  pinMode (echopin,INPUT);
  Serial.begin(9600);

  pinMode(buzzer, OUTPUT);
}

void loop() {
digitalWrite(trigpin,LOW);
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);

duration=pulseIn(echopin,HIGH);
distance=duration*0.034/2;

Serial.print("Distance:");
Serial.println(distance);
Serial.println("cm");

if(distance>=200){
   tone(buzzer, 500);
  delay(1000);        
  noTone(buzzer);     
  delay(1000);
  
  }
  else if(distance>100&&distance<200)
  { 
  tone(buzzer, 1000);
  delay(500);        
  noTone(buzzer);     
  delay(500);
      
    }
 else if(distance<100) { 
  tone(buzzer, 2000);
  delay(200);        
  noTone(buzzer);     
  //delay(200);
      
    }


delay(2000);

}