// modos de desligar e ligar o display
//deixar display mostar 'nada' display.println(); pode funcionar tb
//display.oled_command(SSD1305_DISPLAYOFF);
//display.oled_command(SSD1305_DISPLAYON);


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RTClib.h"  
#include <string.h>

RTC_DS1307 rtc;


int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

int array_alarme [] = {0,0,0,0};
int array_timer_down [] = {0,0,0};

int menupagina1 = 0;
int menupagina2 = 0;
int menupagina3 = 0;
int menupagina4 = 0;

const int buttonPin1 = 2;  //decrements menucounter
const int buttonPin2 = 3; // selects the menu 
const int buttonPin3 = 4;  //increments menucounter

int time[] = {0,0,0};


String minutos; 
String horas;


Adafruit_SSD1306 display(-1);

String str=String(10);

void setup()   
{
   Serial.begin(9600);
  if (!rtc.begin()) {
    while (1);
  }

  if (!rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  }
   
  //rtc.adjust(DateTime(2022, 2, 11, 16, 40, 0));
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  

  display.clearDisplay();
}

void loop() {
  DateTime now = rtc.now();
  
	horas = String(now.hour());
	minutos = String(now.minute());
  
  time[0] = now.day();
  time[1] = now.month();
  time[2] = now.year();
  Serial.println(now.second());
  main_F(time);//roda todas as funcoes
  
  if(array_alarme[0]==1){
         if((array_alarme[1]== now.hour())  && (array_alarme[2] == now.minute()) && (array_alarme[3] == now.second())){
              		array_alarme[0] = 0;
              		//buzzer on
              		display.clearDisplay();
              		display.setTextSize(2);
              		display.setTextColor(1,0);
              		display.setCursor(10,18);
              		display.println("ALARMMMMMMM!");
              		delay(2000);
                  display.clearDisplay();
                  display.display();
	}
  }
}
