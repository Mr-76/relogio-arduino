// modos de desligar e ligar o display
//deixar display mostar 'nada' display.println(); pode funcionar tb
//display.oled_command(SSD1305_DISPLAYOFF);
//display.oled_command(SSD1305_DISPLAYON);


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

int menupagina1 = 0;
int menupagina2 = 0;
int menupagina3 = 0;
int menupagina4 = 0;

const int buttonPin1 = 2;  //decrements menucounter
const int buttonPin2 = 3; // selects the menu 
const int buttonPin3 = 4;  //increments menucounter

Adafruit_SSD1306 display(-1);


void setup()   
{          
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  

   display.clearDisplay();
}

void loop() {

main_F();
}
