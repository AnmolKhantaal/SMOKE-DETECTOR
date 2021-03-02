#include <LiquidCrystal.h>


int buzzer = 4;
int gassensor = A0;
int sensorThresh = 400;


void setup()
{

pinMode(buzzer,OUTPUT);

pinMode(gassensor,INPUT);
Serial.begin(9600);

}

void loop()
{
  
  int analogValue = analogRead(gassensor);
  Serial.println(analogValue); 
  
  if(analogValue>sensorThresh)
  {
    
    tone(buzzer,1000,1000);
    
  }
  else
  {
    
    noTone(buzzer);
   
  }
  
}



void setup()
{
  
}

void loop()
{
  
}
