#include<VirtualWire.h>

char Array[20];

#define pir 9        //pir sensor
#define gas 11         //gas sesor
#define tran 10        //RF trans

int a,b,c;

void setup() {
 Serial.begin(9600);
 pinMode(gas, INPUT);
 pinMode(pir, INPUT);

 vw_setup(2000);
 vw_set_tx_pin(10);
}

void loop() {
  a = digitalRead(pir);
  Serial.println(a);
  b = digitalRead(gas);
  Serial.println(b);

  sprintf(Array, "%d,%d", a,b);
  vw_send((uint8_t *)Array, strlen(Array));
  vw_wait_tx();

  //delay(1000);
}
  
