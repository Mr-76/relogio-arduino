#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// 0 is black and 1 is white
Adafruit_SSD1306 display(-1);
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int menucounter = 0;
//v- voltage,a- alarm,rf -radio freq, ir - infrared
//definitions for initial colors in the display
int vword = 1;
int vback = 0;    
int aword = 1;
int aback = 0;
int irword = 1;
int irback = 0;
int rfword = 0;
int rfback = 1;    

const int buttonPin1 = 2;  //decrements menucounter
const int buttonPin2 = 3;  
const int buttonPin3 = 4;  //increments menucounter
void setup()   
{          
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  

  // Clear the buffer.
}



void loop() {
buttonState1 = digitalRead(buttonPin1);
buttonState2 = digitalRead(buttonPin2);
buttonState3 = digitalRead(buttonPin3);

if (buttonState1 == HIGH) {
  menucounter -= 1;
  }

  if (buttonState3 == HIGH) {
  menucounter += 1;
  }

if (menucounter > 3 || menucounter < 0){
  menucounter = 0;
  }

 if (menucounter == 0){
   vword = 1;
   vback = 0;    
   aword = 1;
   aback = 0;
   irword = 1;
   irback = 0;
   rfword = 0;
   rfback = 1;  
  }

if (menucounter == 1){
rfword = irback = 1;
rfback = irword = 0;

  }
if (menucounter == 2){
irword = aback = 1;
irback = aword = 0;

  }
 if (menucounter == 3){
aword = vback = 1;
aback = vword = 0;

  }

delay(500);
  
  display.clearDisplay();

  // Display Text
  display.setTextSize(1); //0    1
  display.setTextColor(rfword, rfback);
  display.setCursor(0,0);
  display.println("RF");
  display.display();
 

  // Display Inverted Text 1     0
  display.setTextColor(irword, irback); // 'inverted' text
  display.setCursor(0,9);
  display.println("INFRA RED");
  display.display();
  
   // Display Inverted Text
  display.setTextColor(aword, aback); // 'inverted' text
  display.setCursor(0,18);
  display.println("ALARM");
  display.display();
 
   // Display Inverted Text
  display.setTextColor(vword, vback); // 'inverted' text 1 is white and 0 is black 
  display.setCursor(0,27);
  display.println("VOLTAGE");
  display.display();

  display.setCursor(0,35);//for debug 
  display.print(menucounter, DEC);
  display.println("(DEC)"); 
  display.display();
  delay(2000);
  display.clearDisplay();
  
  display.clearDisplay();  
  
  
  }
