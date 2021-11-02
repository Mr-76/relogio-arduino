// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#define IR_RECEIVE_PIN  2
#define IR_SEND_PIN          2
#include <Arduino.h>
#include <IRremote.h>
#include "RTClib.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

RTC_DS1307 rtc;
Adafruit_SSD1306 display(-1);
int pinodisplay = 7; 
int pinosniffer = 8;
int botao_transmissor = 9;
char Time[7];
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
void setup () {
  
  Serial.begin(9600);
  IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK); // Specify send pin and enable feedback LED at default feedback LED pin
 Serial.print(F("Ready to send IR signals at pin "));
 Serial.println(IR_SEND_PIN);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK, USE_DEFAULT_FEEDBACK_LED_PIN);
  Serial.print(F("Ready to receive IR signals at pin "));
  Serial.println(IR_RECEIVE_PIN);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  pinMode(pinodisplay, INPUT);
  pinMode(pinosniffer, INPUT); 
  pinMode(botao_transmissor,INPUT);
  display.clearDisplay();
  inicializartc();
  //mySwitch.enableReceive(0);
}

uint16_t sAddress = 0xB;
uint8_t sCommand = 0xA;
uint8_t sRepeats = 1;

uint16_t ssAddress = 0xBF00;
uint8_t ssCommand = 0x3;
uint8_t ssRepeats = 1;

uint16_t ssAddress = 0x707;
uint8_t ssCommand = 0x2;
uint8_t ssRepeats = 1;

 
void loop () {
  DateTime now = rtc.now();
  reciver();
  sender();
 snifferrf(pinosniffer);
 ligadesliga(pinodisplay);
 
 mostrahoradata((int)now.hour(),(int)now.minute(),(int)now.second(),(int)now.year(),(int)now.month(),(int)now.day());
transmitir();
    
    
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
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

int ligadesliga(int pino){
/* para controlar a liga e desliga usar 2 pinos e fechar um um cnector */
  
  display.ssd1306_command(SSD1306_DISPLAYON);//desliga display 
 if (digitalRead(pino) == HIGH){
  display.ssd1306_command(SSD1306_DISPLAYOFF);
  }
  return 0;
  
  }
 int snifferrf(int pinosniffer){
 if (digitalRead(pinosniffer) == HIGH){
    delay(5000);
    display.ssd1306_command(SSD1306_DISPLAYON);
    display.clearDisplay();
    display.display();
   while (true){
    mySwitch.enableReceive(0);
    Serial.println("loop working");
   if (digitalRead(pinosniffer) == HIGH){
    break;
    }
   if (mySwitch.available()) {
    Serial.print("Received ");
    Serial.print( mySwitch.getReceivedValue() );
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(70,10);
  display.print(((int)mySwitch.getReceivedValue()), BIN);//ainda ver o tipo de variavel que witch gera
  display.display();
  delay(2000);
  display.clearDisplay();
   mySwitch.resetAvailable();
  }}}
  }
  void transmitir(){
  if (digitalRead(botao_transmissor) == HIGH){ 
    mySwitch.enableTransmit(10);                                                                                                                                       
    mySwitch.send("1011110001111111100100010101");
    delay(500);
  }}
  
  
    void reciver(){
      //adicinar pino de teste
    if (IrReceiver.decode()) {

        // Print a short summary of received data
        IrReceiver.printIRResultShort(&Serial);
        if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
            // We have an unknown protocol here, print more info
            IrReceiver.printIRResultRawFormatted(&Serial, true);
        }
        Serial.println();

        IrReceiver.resume(); // Enable receiving of the next value 
    }}

    void sender(){
      
      IrSender.sendNEC(sAddress, sCommand, sRepeats);
   delay(1000);
   IrSender.sendNEC(ssAddress, ssCommand, ssRepeats);
   delay(1000);
      
      
      }
  


  
  
