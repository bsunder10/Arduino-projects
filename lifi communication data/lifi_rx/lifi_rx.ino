#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);//RS,EN,D4,D5,D6,D7

int pin = 2; 
volatile unsigned int pulse; 
char ch;
 
void setup() 
{ 
  Serial.begin(9600); 
  pinMode(pin, INPUT);                  //D2
  attachInterrupt(0, count_pulse, RISING); 

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
  if(pulse != 0)
  {    
    interrupts(); 
    delay(300); 
    //noInterrupts(); 
     
    Serial.print("Pulses per second: "); 
    Serial.println(pulse);
    if(pulse==1){
      lcd.print('1');
     Serial.print('1');
    }
    else if(pulse==2){
      lcd.print('2');
     Serial.print('2');
    }
    else if(pulse==10){
      lcd.print('A');
     Serial.print('A');
    }
    else if(pulse==11)
      lcd.print('B');
      //Serial.print('B');
    else if(pulse==12)
      lcd.print('C');
     // Serial.print('C');
    else if(pulse==13)
      lcd.print('D');
      //Serial.print('D');
    else if(pulse==14)
      lcd.print('*');
    else if(pulse==15)
      lcd.print('0');
    else if(pulse==16)
      lcd.print('#');
    else if(pulse==17)
      lcd.print('#');
    else 
      lcd.print(pulse);
    
    lcd.print("  ");
    pulse=0;
  }
} 
 
void count_pulse() 
{ 
  pulse++; 
} 


