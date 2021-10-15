// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include "RTClib.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

RTC_DS1307 rtc;
Adafruit_SSD1306 display(-1);
int bPin7 = 7; 
int botaodisplay =0;
char Time[7];
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
void setup () {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  pinMode(bPin7, INPUT); 
  display.clearDisplay();
  inicializartc();
}
 
void loop () {
 ligadesliga(bPin7);
 /*
 display.ssd1306_command(SSD1306_DISPLAYOFF);//desliga display
 botaodisplay = digitalRead(bPin7);
 
 if (botaodisplay == HIGH){
  display.ssd1306_command(SSD1306_DISPLAYON);
  }
*/
    
    DateTime now = rtc.now();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    // calculate a date which is 7 days, 12 hours, 30 minutes, and 6 seconds into the future
    DateTime future (now + TimeSpan(7,12,30,6));



mostrahoradata((int)now.hour(),(int)now.minute(),(int)now.second(),(int)now.year(),(int)now.month(),(int)now.day());

delay(2000);


}

int mostrahoradata(int horas,int minutos,int segundos,int dia,int mes, int ano){
delay(200);
display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(70,10);
display.print(horas, DEC) ;
display.print(":");
display.print(minutos,DEC);
display.print(":");
display.print(segundos,DEC);
display.setCursor(0,10);
display.print(ano, DEC) ;
display.print("/");
display.print(mes,DEC);
display.print("/");
display.print(dia,DEC);
display.display();//changes have effect

delay(1000);
display.clearDisplay();
return 0;

}

void inicializartc(){
   if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
   // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

int ligadesliga(int pino){
/* para controlar a liga e desliga usar 2 pinos e fechar um um cnector */
  
  display.ssd1306_command(SSD1306_DISPLAYON);//desliga display 
  botaodisplay = digitalRead(bPin7);
 if (botaodisplay == HIGH){
  display.ssd1306_command(SSD1306_DISPLAYOFF);
  }
  return 0;
  
  }


  
  
