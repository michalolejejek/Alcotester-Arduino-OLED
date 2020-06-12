#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Wiring:
// MQ-3 VCC - 5V ARDUINO
// MQ-3 GND - GND ARDUINO
// MQ-3 A0 - A0 ARDUINO

#define sensor A0
//#define led 53
//#define buz 22

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);



void setup()   {                
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.display(); // show splashscreen
  delay(2000);
  display.clearDisplay();   // clears the screen and buffer
  pinMode(sensor, INPUT);
  //pinMode(buz, OUTPUT);
  //pinMode(led, OUTPUT);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(1,0);
  display.println("ALCOTEST - WAIT");
  display.display();
  delay(2000);
  
}


void loop() {
  float adcValue=0;
  for(int i=0;i<10;i++)
  {
    adcValue+= analogRead(sensor);
    delay(10);
  }
    float v= (adcValue/10) * (5.0/1024.0);
    float mgL= 0.05 * v;
    Serial.print("pom.");
    Serial.print(mgL);
    Serial.print(" mg/L");
     display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(1,0);
  display.println("pom. \n");
  display.println(" mg/L        ");
  display.println(mgL,4);
  display.setCursor(0,1);
  display.display();
  delay(200);

    /*if(mgL > 0.09)
    {
      display.println("DRUNK!   ");
      Serial.println("    DRUNK! ");
      digitalWrite(buz, HIGH);
      digitalWrite(led, HIGH);
    }
    else
    {
      display.println("OK  ");
      Serial.println("   OK");
      digitalWrite(buz, LOW);
      digitalWrite(led, LOW);
    } */
 
}
