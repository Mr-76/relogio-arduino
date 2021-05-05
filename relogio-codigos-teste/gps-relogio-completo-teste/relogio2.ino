 //novo codigo reles

//////////////////////////////////////////////////////////////////////////////////
#include <TM1637Display.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <math.h>
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
TinyGPSPlus gps;


double  lat1;
double  lat11;
double  lat2;
double  lon1;
double  lon11;
double  lon2;
double  R;
double  b1;
double  b2;
double  pi = 3.1415926535897932384626433832795;
double  b ;
double  c ;
double  k;
double x;
double y;
double d;
double l ;
double lon0;
double lat0;
int cont = 0;
int soma = 0;
int RXPin = 2; //red
int TXPin = 3;
int GPSBaud = 9600;

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
int gps_ativar = 0;
SoftwareSerial gpsSerial(RXPin, TXPin);
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
  
gpsSerial.begin(GPSBaud);
  
if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
  }
  
//rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

pinMode(bPin9, INPUT);
pinMode(bPin8, INPUT);
pinMode(bPin7, INPUT);
pinMode(bPin6, INPUT);
pinMode(pinolaser, OUTPUT);// tirar


}
void loop () {

  
DateTime now = rtc.now();

DateTime future (now + TimeSpan(7, 12, 30, 6));


print_data_hora(); // bando de serial print >:D

mostrar_tempo(); // mostra hora no display


if (alarme == 1){
alarme_checa(); // função alarme 
}
delay(500);

botaodata = digitalRead(bPin9);
botaocronometro = digitalRead(bPin8);
botao_alarme = digitalRead(bPin7);
botao_transmissor = digitalRead(bPin6);


if (botaodata == HIGH) {
delay(3000);
gps_ativar += 1;
}


gps_ativo(); // gps trabalhando





if (botaocronometro == HIGH){
   counter += 1;
}  

cronometro();



if (botao_alarme == HIGH) {
  alarme_cria();
}
  
  
if (botao_transmissor == HIGH){
    mySwitch.send("1011110001111111100100010101");
    display.setBrightness(0x0f);
    display.showNumberDec(3, false);
    delay(300);
  }
}




void print_data_hora(){

/*  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
//  Serial.print(now.hour(), DEC);
// Serial.print(':');
//  Serial.print(now.minute(), DEC);
//  Serial.print(':');
//  Serial.print(now.second(), DEC);

Serial.println();
*/


}

void gps_ativo(){

if (gps_ativar > 0){
display.setBrightness(0x0c);// isso fala pra vc que o loop esta funcioando __ aFIM DE TESTES
display.showNumberDec(soma, false);
delay(500);

 while (gpsSerial.available() > 0){ // testar dps se o serial é da conecção dos satelites
     botaodata = digitalRead(bPin9); // sair do loop :>
     if (botaodata == HIGH){
     delay(1000);
     gps_ativar = 0;
     break;
     }
     if (gps.encode(gpsSerial.read())){
      displayInfo();
    
    }

}

}



}

void cronometro(){

if (counter > 1){
    minutos1 = ((minutos+(hora*60))*60)+(segundos);
    minutost = (minutos1 - minutos0);
    display.setBrightness(0x0c);
    display.showNumberDec(minutost, false); // mostra em segundos
    delay(700);
    display.setBrightness(0x0c);
    display.showNumberDec(minutost/60, false);// mostra em minutors
    delay(700);
    display.setBrightness(0x0c);
    display.showNumberDec(minutost/3600, false);// mostra em horas
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

void alarme_cria(){

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


}

void mostrar_tempo(){

DateTime now = rtc.now();

DateTime future (now + TimeSpan(7, 12, 30, 6));


segundos = int(now.second());
minutos = int(now.minute());
hora = int(now.hour());

display.setBrightness(0x0b);
display.showNumberDecEx(minutos,0,true,2, 2);//deixa qual lado separado por : 
display.showNumberDecEx(hora,0b01000000, true, 2, 0);

}


void alarme_checa(){
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


void displayInfo()
{
  if (gps.location.isValid())
  {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat());
    Serial.println("latitude2");
    double lat11 = (gps.location.lat()); // point 1
    Serial.println(lat11,6);
    Serial.println("------------");
    delay(1000);

    Serial.print("Longitude: ");
    Serial.println(gps.location.lng());
    Serial.println("longitude2");
    double lon11 = (gps.location.lng());//point 1
    Serial.println(lon11,6);
    Serial.println("------------");
    delay(1000);

if (cont == 0){
  lon0 = lon11;
  lat0 = lat11;
  }

if (cont >= 1){
delay(10000);
lat2 = lat11;

lon2 = lon11;

b1 = lat0 * pi/180 ;// φ, λ in radians
b2 = lat2 * pi/180;
 R = 6371; // metres
 b = (lat2-lat0) * pi/180;
 c = (lon2-lon0) * pi/180;

x = (c) * cos((b1+b2)/2);
y = (b);
d = (sqrt(x*x + y*y) * R)*1000;
l = (int) d;
soma += l;
//Serial.println(d,6);
//delay(2000);
//Serial.println(l);
//delay(2000);
//Serial.println("soma");
//Serial.println(soma);
delay(1000);
display.setBrightness(0x0c);
display.showNumberDec(soma, false);

  Serial.println("satelites");
  Serial.println(gps.satellites.value());
  Serial.println(gps.satellites.value());
  delay(1000);
  lat0 = lat2;
  lon0 = lon2;
  }
   cont += 1;
  }


  else
  {
    Serial.println("Location: Not Available");
  }

}
                                                     
