#include<VirtualWire.h>
#include<SoftwareSerial.h>
#include <TinyGPS++.h>

TinyGPSPlus gps;
SoftwareSerial ss(9, 10);       //Rx, Tx for gsm

char data[20];

#define relay 13
#define xout A0
#define yout A1
#define zout A3

int x,y,z;

void setup() {
  Serial.begin(9600);

  pinMode(relay,OUTPUT);
  pinMode(xout,INPUT);
  pinMode(yout,INPUT);
  pinMode(zout,INPUT);
  
  vw_setup(2000);
  vw_set_rx_pin(8);
  vw_rx_start();
  digitalWrite(relay, HIGH);
 
}


void gsmgps()
{
  Serial.print("*****************");
  ss.println("AT+CMGF=1");   
  delay(1000);  
  Serial.println("done");
  ss.println("AT+CMGS=\"+919550231394\"\r"); 
  Serial.println("sone");
  delay(1000);
  gps.encode(Serial.read());
  ss.print(" My location is http://maps.google.com/maps?q=");
  ss.print(gps.location.lat(), 6);
  ss.print(",");
  ss.println(gps.location.lng(), 6);
  delay(100);
  ss.println((char)26);
  delay(5000);
      }

void loop() {

  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if(vw_get_message(buf, &buflen))
  {
    int i;
    for(i = 0; i < buflen; i++)
    {
      data[i] = buf[i];
    }
    int temp1 = atoi(strtok(data, ","));
    int temp2 = atoi(strtok(NULL, ",")); 

    Serial.println(temp1);
    Serial.print("******************");
    
    Serial.println(temp2);

    if(temp1 == 0)
    {
      Serial.println("can on the bike");
      Serial.println("relay LOW");
      digitalWrite(relay, LOW);
    }
    else{
      Serial.println("can't on bike");

    }
  }

  else
  {
    Serial.println("fsdajj");

  }
  delay(1000);

  x = analogRead(xout);
  y = analogRead(yout);
  z = analogRead(zout);

  Serial.println(x);
  Serial.println(y);
  Serial.println(z);

 /* if(y > 385 or y < 280)
  {
    Serial.println("\\\\\\\\\\\\\\\\\\\\\\\\\\");
    gsmgps();
    Serial.println("////////////////////////////////");
  }
*/
}
