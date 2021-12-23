

/*  other way of displayign the menu using fuctions and incremetation and decrementation
theres a array conteaining the value 
arrayvalue = [[1,0],[0,1],[0,1],[0,1]]
everytime u increment a function coutner for defauis is 0 a variable nextcounter  is nexcouter = count + 1 and 
the function changes the values of the array, ex arrayvalue[0] == arrayvalue[1] and change of places and finaly counter gets a + 1 
when counter hits 3 it shoud stop and open an exception so counter = 0 and nextcouter = 3 from before and after the change redefine
nexetcouter as 0, if u decrement less then 0 if count = 0 in decrement check say hEY u cant  coutner = 0 next couter = 0 and reset continue
better to ignore the input in decremtn with counter == 0



*/
// modos de desligar e ligar o display
//deixar display mostar 'nada' display.println(); pode funcionar tb
//display.oled_command(SSD1305_DISPLAYOFF);
//display.oled_command(SSD1305_DISPLAYON);


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
int array_botoes[4][2] = {{1,0},{0,1},{0,1},{0,1}};
//v- voltage,a- alarm,rf -radio freq, ir - infrared
//definitions for initial colors in the display
int vword = array_botoes[3][1];//these are the equivalent to black and white to the word colors and the back light color 
int vback = array_botoes[3][0];  

int aword = array_botoes[2][1];
int aback = array_botoes[2][0];

int irword = array_botoes[1][1];
int irback = array_botoes[1][0];

int rfword = array_botoes[0][1];
int rfback = array_botoes[0][0];    

const int buttonPin1 = 2;  //decrements menucounter
const int buttonPin2 = 3; // selects the menu 
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
if (menucounter < 0){
menucounter = 0;
continue;
}

else{
array_botoes[menucounter][0] = 1;
array_botoes[menucounter][1] = 0;

array_botoes[(menucounter + 1)][0] = 0;
array_botoes[(menucounter +1)][1] = 1;

}  
  }

  if (buttonState3 == HIGH) {
	menucounter += 1;
	if(menucounter > 3){
		menucounter = 3;
		continue;
	}
	
	
	else{
		array_botoes[menucounter][0] = 1;
		array_botoes[menucounter][1] = 0;

		array_botoes[(menucounter - 1)][0] = 0;
		array_botoes[(menucounter - 1)][1] = 1;
	     }  
}
  
  if (buttonState2 == HIGH) { 
    //selct a menu
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
}