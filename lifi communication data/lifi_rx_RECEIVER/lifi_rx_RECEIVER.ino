#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);//RS,EN,D4,D5,D6,D7

int pin = A0; 
//volatile unsigned int pulse; 
char ch;
int i;
byte buffer;
void setup() 
{ 
  Serial.begin(9600); 
  pinMode(6,OUTPUT);
  analogWrite(6,20);
  pinMode(pin, INPUT);                  //D2
  //attachInterrupt(0, count_pulse, RISING); 

  lcd.begin(16, 2);//initializing LCD
} 
 
void loop() 
{
  lcd.setCursor(0, 0);
  lcd.print("....Li-Fi Rx....");
  lcd.setCursor(0, 1);
  lcd.print("KEY = ");
  delay(100);
  lcd.setCursor(6, 1);
  for(i=0;i<6;i++);
  {
    int sensorValue = analogRead(pin);;
    Serial.println(sensorValue);
    if(sensorValue>=215)
    {
      bitWrite(buffer,i,1);
    }
    else
    {
      bitWrite(buffer,i,0); 
    }
    delay(1000);
  }
  //Serial.print("    ");
  Serial.println(buffer,HEX);
  delay(1000);
} 
