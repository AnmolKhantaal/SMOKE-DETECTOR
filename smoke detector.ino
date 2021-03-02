#include <LiquidCrystal.h>
LiquidCrystal lcd(5,6,7,8,9,10);

int buzzer = 4;
int gassensor = A0;
int sensorThresh = 400;


void setup()
{

pinMode(buzzer,OUTPUT);

pinMode(gassensor,INPUT);
Serial.begin(9600);
lcd.begin(16,2);
}

void loop()
{
  
  int analogValue = analogRead(gassensor);
  Serial.println(analogValue); 
  
  
  if(analogValue>sensorThresh)
  {
    
    tone(buzzer,1000,1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Smoke Level:");
    lcd.print(analogValue);
    
    delay(1000);
    lcd.setCursor(0,1);
    lcd.print("  EVACUATE :(");
    delay(1000);
  }
  else
  {
    
    noTone(buzzer);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Smoke Level:");
    lcd.print(analogValue);
    delay(1000);
    
    lcd.setCursor(0,1);
    lcd.print("SAFE  :)");
    delay(1000);
  }
   
}
