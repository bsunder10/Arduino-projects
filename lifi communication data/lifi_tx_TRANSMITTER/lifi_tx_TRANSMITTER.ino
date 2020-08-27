#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 
int ledPin = 13;
int i = 0;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 0, 1, 2, 3 };

// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 4, 5, 6, 7 };

//  Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  for(int k=8;k<14;k++)
  {
    pinMode(k,OUTPUT);//pins 8-14 are enabled as output
  }
}

void loop()
{
  char key = kpd.getKey(); //storing pressed key value in a char

  switch(key)
  {
    case '1'  :   for(i=0; i<1; i++)
                  {
                    digitalWrite(ledPin, HIGH);
                    delay(10);   
                    digitalWrite(ledPin, LOW);
                    delay(10);
                  }
                  break;

    case '2'  :   for(i=0; i<2; i++)
                  {
                    digitalWrite(ledPin, HIGH);
                    delay(10);   
                    digitalWrite(ledPin, LOW);
                    delay(10);
                  }
                  break;

    case '3'  :   for(i=0; i<3; i++)
                  {
                    digitalWrite(ledPin, HIGH);
                    delay(10);   
                    digitalWrite(ledPin, LOW);
                    delay(10);
                  }
                  break;

    case '4'  :   for(i=0; i<4; i++)
                  {
                    digitalWrite(ledPin, HIGH);
                    delay(10);   
                    digitalWrite(ledPin, LOW);
                    delay(10);
                  }
                  break;

    case '5'  :   for(i=0; i<5; i++)
                  {
                    digitalWrite(ledPin, HIGH);
                    delay(10);   
                    digitalWrite(ledPin, LOW);
                    delay(10);
                  }
    `               break;
                  
    case '6'  :   for(i=0; i<6; i++)
                  {
                    digitalWrite(ledPin, HIGH);
                    delay(10);   
                    digitalWrite(ledPin, LOW);
                    delay(10);
                  }
                  break;
                  
    case '7'  :   for(i=0; i<7; i++)
                  {
                    digitalWrite(ledPin, HIGH);
                    delay(10);   
                    digitalWrite(ledPin, LOW);
                    delay(10);
                  }
                  break;
                  
    case '8'  :   for(i=0; i<8; i++)
                  {
                    digitalWrite(ledPin, HIGH);
                    delay(10);   
                    digitalWrite(ledPin, LOW);
                    delay(10);
                  }
                  break;
                  
    case '9'  :   for(i=0; i<9; i++)
                  {
                    digitalWrite(ledPin, HIGH);
                    delay(10);   
                    digitalWrite(ledPin, LOW);
                    delay(10);
                  }
                  break;
                  
    case 'A'  :   for(i=0; i<10; i++)
                  {
                    digitalWrite(ledPin, HIGH);
                    delay(10);   
                    digitalWrite(ledPin, LOW);
                    delay(10);
                  }
                  break;
                  
    case 'B'  :   for(i=0; i<11; i++)
                  {
                    digitalWrite(ledPin, HIGH);
                    delay(10);   
                    digitalWrite(ledPin, LOW);
                    delay(10);
                  }
                  break;
                  
  case 'C'  :   for(i=0; i<12; i++)
                  {
                    digitalWrite(ledPin, HIGH);
                    delay(10);   
                    digitalWrite(ledPin, LOW);
                    delay(10);
                  }
                  break;
                  
  case 'D'  :   for(i=0; i<13; i++)
                  {
                    digitalWrite(ledPin, HIGH);
                    delay(10);   
                    digitalWrite(ledPin, LOW);
                    delay(10);
                  }
                  break;
                  
  case '*'  :   for(i=0; i<14; i++)
                  {
                    digitalWrite(ledPin, HIGH);
                    delay(10);   
                    digitalWrite(ledPin, LOW);
                    delay(10);
                  }
                  break;
                  
   case '0'  :   for(i=0; i<15; i++)
                  {
                    digitalWrite(ledPin, HIGH);
                    delay(10);   
                    digitalWrite(ledPin, LOW);
                    delay(10);
                  }
                  break;
                  
  case '#'  :   for(i=0; i<16; i++)
                  {
                    digitalWrite(ledPin, HIGH);
                    delay(10);   
                    digitalWrite(ledPin, LOW);
                    delay(10);
                  }
                  break;
  }
}                
