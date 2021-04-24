 //novo codigo reles

//////////////////////////////////////////////////////////////////////////////////
#include <RCSwitch.h>
#include <Wire.h>
#include "RTClib.h"
#include <Arduino.h>
#include <TM1637Display.h>
#define CLK 4
#define DIO 5

TM1637Display display(CLK, DIO);
RCSwitch mySwitch = RCSwitch();
RTC_DS1307 rtc;
int pinolaser = 12;
const int bPin9 = 9; 
const int bPin8 = 8;
const int bPin7 = 7;
const int bPin6 = 6;
int botaodata = 0;  
int botaocronometro = 0;  
int botao_alarme = 0;
int botao_transmissor = 0;
char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sabadao"};
int hora;
int minutos;
int segundos;
int dia;
int mes;
int valor = 0;
int counter =0;
int minutos0 = 0;
int minutos1 = 0;
int minutost = 99;
int alarme = 0;
int horaA = 0;
int minutosA = 0;
int dowhile = 0;
void setup () {
  while (!Serial); // for Leonardo/Micro/Zero
  pinMode(3, OUTPUT);
  
  mySwitch.enableTransmit(10);// pin #10 
  mySwitch.setPulseLength(482);
  mySwitch.setProtocol(6);
   
  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
  }
  
//rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

pinMode(bPin9, INPUT);
pinMode(bPin8, INPUT);
pinMode(bPin7, INPUT);
pinMode(bPin6, INPUT);
pinMode(pinolaser, OUTPUT);


}
void loop () {

  
  DateTime now = rtc.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  DateTime future (now + TimeSpan(7, 12, 30, 6));
  
segundos = int(now.second());
minutos = int(now.minute());
hora = int(now.hour());


if (alarme == 1){
  
 if ((horaA == hora) and (minutosA == minutos)){
 digitalWrite(pinolaser,HIGH);
 delay(500);
 digitalWrite(pinolaser,LOW);
 delay(500);
 digitalWrite(pinolaser,HIGH);
 delay(500);
 digitalWrite(pinolaser,LOW);
 delay(500);
  digitalWrite(pinolaser,HIGH);
 delay(500);
 digitalWrite(pinolaser,LOW);
 delay(500);
  digitalWrite(pinolaser,HIGH);
 delay(500);
 digitalWrite(pinolaser,LOW);
 delay(500);
 alarme = 0;
 horaA = 0;
 minutosA =0;
  }
}


 
display.setBrightness(0x0b);

display.showNumberDecEx(minutos,0,true,2, 2);//deixa qual lado separado por : 
display.showNumberDecEx(hora,0b01000000, true, 2, 0);
delay(500);

  botaodata = digitalRead(bPin9);

  botaocronometro = digitalRead(bPin8);

  botao_alarme = digitalRead(bPin7);
  
  botao_transmissor = digitalRead(bPin6);

if (botaodata == HIGH) {
  dia = int(now.day()); 
  mes = int(now.month());
  
  display.showNumberDecEx(mes,0,true,2, 2);//deixa qual lado separado por : 
  display.showNumberDecEx(dia,0b01000000, true, 2, 0);
  delay(4000);
    
  }

if (botaocronometro == HIGH){
   counter += 1;
  if (counter > 1){
    minutos1 = ((minutos+(hora*60))*60)+(segundos);
    minutost = (minutos1 - minutos0);
    display.setBrightness(0x0c);
    display.showNumberDec(minutost, false);
    delay(700);
    display.setBrightness(0x0c);
    display.showNumberDec(minutost/60, false);
    delay(700);
    display.setBrightness(0x0c);
    display.showNumberDec(minutost/3600, false);
    delay(700);
    counter = 0;
    minutost = 0;
    minutos0 = 0;
    minutos1 = 0;
    }
    
   else{
   minutos0 = (((minutos+(hora*60))*60)+(segundos));
   display.setBrightness(0x0c);
   display.showNumberDec(100, false);
   delay(500);
   }
  }
  


if (botao_alarme == HIGH) {
  display.setBrightness(0x0c);
  display.showNumberDec(1111, false);
  delay(500);
  dowhile += 1;
  display.setBrightness(0x0c);
  display.showNumberDec(dowhile, false);
  delay(500);
  horaA = hora;
  minutosA = minutos;
  delay(1000);
  }
  
  while (dowhile == 1){
    
  botaodata = digitalRead(bPin9); // pq os while loops >: com read pois esses codigos fora do while so sao feitos uma vez entao nao 
  //mudam a nao ser que vc mande ele ler novamente

  botaocronometro = digitalRead(bPin8);

  botao_alarme = digitalRead(bPin7);
  
  botao_transmissor = digitalRead(bPin6);
  
    if (botaodata == HIGH){
      
        horaA += 1;
        display.setBrightness(0x0c);
        display.showNumberDecEx(minutos,0,true,2, 2);//deixa qual lado separado por : 
        display.showNumberDecEx(horaA,0b01000000, true, 2, 0);
        delay(100);
          }
          
    if (botaocronometro == HIGH){
        horaA -= 1;
        display.setBrightness(0x0c);
        display.showNumberDecEx(minutos,0,true,2, 2);//deixa qual lado separado por : 
        display.showNumberDecEx(horaA,0b01000000, true, 2, 0);
        delay(100);
    }

    
    if (botao_alarme == HIGH){
       
        delay(100);
        dowhile += 1;
        display.setBrightness(0x0c);
        display.showNumberDec(dowhile, false);
        delay(1000);
    }
  }
  
   while (dowhile == 2){
    
  botaodata = digitalRead(bPin9);

  botaocronometro = digitalRead(bPin8);

  botao_alarme = digitalRead(bPin7);
  
  botao_transmissor = digitalRead(bPin6);
    
    if (botaodata == HIGH){
        minutosA += 1;
        display.showNumberDecEx(minutosA,0,true,2, 2);//deixa qual lado separado por : 
        display.showNumberDecEx(horaA,0b01000000, true, 2, 0);
        delay(100);
   }
    if (botaocronometro == HIGH){
        minutosA -= 1;
        display.showNumberDecEx(minutosA,0,true,2, 2);//deixa qual lado separado por : 
        display.showNumberDecEx(horaA,0b01000000, true, 2, 0);
        delay(100);
    }
    
    if (botao_alarme == HIGH){
        dowhile =0;
         display.setBrightness(0x0b);
         display.showNumberDec(dowhile, false);
    display.showNumberDecEx(minutosA,0,true,2, 2);//deixa qual lado separado por : 
    display.showNumberDecEx(horaA,0b01000000, true, 2, 0);
    delay(2000);
    alarme = 1;
    } 
    }
 
  
  

if (botao_transmissor == HIGH){
    mySwitch.send("1011110001111111100100010101");
    display.setBrightness(0x0f);
    display.showNumberDec(3, false);
    delay(300);
  }
}
