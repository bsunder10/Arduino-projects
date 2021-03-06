#include<VirtualWire.h>
//Libraries for OLED Display
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128      //Number of pixels
#define SCREEN_HEIGHT 64      //Number of pixels
#define OLED_RESET 4

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1 );

char data[20];            //recieving data
float a, b;               //data to display

void setup() {
  Serial.begin(9600);

//Setting up the RF Reciever
  vw_setup(2000);
  vw_set_rx_pin(8);
  vw_rx_start();

//Setting up the Display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
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

    float temp1 = atoi(strtok(data, ","));
    float temp2 = atoi(strtok(NULL, ","));

  //Display the recieved values
  //Serial.println(temp1);    
  Serial.println(temp2);

  //Converting it to decimal form
    a = temp1 / 100.0;
    b = temp2 / 100.0;

    //Display the result value
    //Serial.println(a);
    Serial.println(b);
  }
  else
  {
    Serial.println("NO messege found");
  }
  delay(1000);

//Displaying the values on the OLED
  display.setCursor(25,17);
  display.println(a);
  display.display();
  display.setCursor(25,38);
  display.println(b);
  display.display();
  display.clearDisplay();
  
  delay(1000);
}
