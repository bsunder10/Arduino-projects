
#include <MPU6050_tockn.h>          //Accelrometer
#include <Wire.h>                   //I2C
#include<Adafruit_GFX.h>             //OLED
#include<Adafruit_SSD1306.h>        //OLED
#define USE_ARDUINO_INTERRUPTS true   //Pulse Sensor
#include<PulseSensorPlayground.h>    //Pulse Sensor


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4

//GSM
char msg;
char call;

// Gyro Sensor    SLK   SDA
MPU6050 mpu6050(Wire);
long timer = 0;
float a=0;
float b=0;
float c=0;

//Pulse Sensor
PulseSensorPlayground pulseSensor;
const int pulseWire = A0;
int Threshold = 510;

//Display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1 );


void setup()
{
  //Setting up GSM Module
  //mySerial.begin(115200);   // Setting the baud rate of GSM Module 
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  Serial.println("GSM SIM900A BEGIN");
  delay(100);
  Serial.begin(9600);
  
  //Setting up Sensor
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  
  //Setting up the display 
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1.75);
  display.setTextColor(WHITE);

  //Setting up Pulse sensor
  pulseSensor.analogInput(pulseWire);
  pulseSensor.setThreshold(Threshold);

   if(pulseSensor.begin()){
    Serial.println("Pulse sensor started");
   }

 
void loop()
{ 

     //pulse  
  int myBPM = pulseSensor.getBeatsPerMinute();
  if (pulseSensor.sawStartOfBeat()) { 
  Serial.print("BPM: "); // Print phrase "BPM: "
  Serial.println(myBPM); 

  //display on OLED
  display.setTextSize(2);
  display.setCursor(25,25);
  display.println("BPM is");
  display.setCursor(45,45);
  display.println(myBPM);
  display.display();
  display.clearDisplay();
  

 
  
  //Accelrometer 
  mpu6050.update();
  if(millis() - timer > 1000){
    a=mpu6050.getAccX();
    Serial.print("accX : ");Serial.print(a);
    b=mpu6050.getAccY();
    Serial.print("\taccY : ");Serial.print(b);
    c=mpu6050.getAccZ();
    Serial.print("\taccZ : ");Serial.println(c);
    timer = millis();
  }
  
 if(b>0.00&&c<0.00 )
 {
    Food();
    delay(2000);
Serial.println("Food");
 }
 
 if(b<-0.10&&c<-0.36 )
 {
    Water();
    delay(2000);
    Serial.println("Water");
 }
 
 if( b<-0.83 && c >0  )
 {
    Washroompls();
    delay(2000);
    Serial.println("Washroom");
 }
/* 
 if(a>0.60  && b<-0.10 && c<0.10)
 {
    Tabletspls();
    delay(2000);
    Serial.println("Tblets");
 }
 delay(3000);
 */
}



//Function to call Food
void Food()
{
   Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+91\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("I need food");// The SMS text you want to send
  delay(100);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

//Function to call Water
void Water()
{
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+91\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("I need water");// The SMS text you want to send
  delay(100);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

//Function to call Washroom
void Washroompls()
{
  Serial.println("********************************************");
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+91\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("I need to go to washroom");// The SMS text you want to send
  delay(100);
 Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

//Function to call tablets
void Tabletspls()
{
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+91\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("I need tablets");// The SMS text you want to send
  delay(100);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
