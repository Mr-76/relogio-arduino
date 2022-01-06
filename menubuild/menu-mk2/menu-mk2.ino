  

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
Adafruit_SSD1306 display(-1);
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int menucounter = 0;

int array_botoes[4][2] = {
  {1,0},
  {0,1},
  {0,1},
  {0,1}
};
int array_botoes2[2][2] = {
  {1,0},
  {0,1}
};
int array_botoes3[2][2] = {
 {1,0},
 {0,1}
};

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

   display.clearDisplay();
}

void pagina_1(){
  
  display.setTextSize(1); 
  display.setTextColor(array_botoes[0][1], array_botoes[0][0]);
  display.setCursor(0,0);
  display.println("RF");
  display.display();
 

  display.setTextColor(array_botoes[1][1], array_botoes[1][0]); 
  display.setCursor(0,9);
  display.println("INFRA RED");
  display.display();
  

  display.setTextColor(array_botoes[2][1], array_botoes[2][0]); 
  display.setCursor(0,18);
  display.println("ALARM");
  display.display();
 

  display.setTextColor(array_botoes[3][1], array_botoes[3][0]); 
  display.setCursor(0,27);
  display.println("VOLTAGE");
  display.display();

  display.setCursor(0,40);//for debug 
  display.print(menucounter, DEC);
  display.println("(DEC)");
  display.display();
  delay(2000);
 

}
void pagina_2(){
  display.setTextSize(1); 
  display.setTextColor(array_botoes2[0][1], array_botoes2[0][0]);
  display.setCursor(0,0);
  display.println("TRANSMIT  RF");
  display.display();
 

  display.setTextColor(array_botoes2[1][1], array_botoes2[1][0]); 
  display.setCursor(0,9);
  display.println("RECIEVE  RF");
  display.display();
}
void pagina_3(){
  display.setTextSize(1); 
  display.setTextColor(array_botoes3[0][1], array_botoes3[0][0]);
  display.setCursor(0,0);
  display.println("TRANSMIT IF");
  display.display();
 

  display.setTextColor(array_botoes3[1][1], array_botoes3[1][0]); 
  display.setCursor(0,9);
  display.println("RECIEVE IF");
  display.display();
}


void muda_array_Drecrese(int testearray[4][2]){
	testearray[menucounter][0] = 1;//selecionado
	testearray[menucounter][1] = 0;

	testearray[(menucounter + 1)][0] = 0;//nao selecionado
	testearray[(menucounter +1)][1] = 1;
		  
}

void muda_array_Crese(int testearray[4][2]){
	testearray[menucounter][0] = 1;//selecionado
	testearray[menucounter][1] = 0;
	  
	testearray[(menucounter - 1)][0] = 0;//nao selecionado
	testearray[(menucounter - 1)][1] = 1;  
}

void decreseMenu(int array_teste1[4][2]){
	display.clearDisplay();
	menucounter -= 1;
	if(menucounter < 0){//valor do menu nao pode ser menor que 0
		menucounter = 0;
	}
	else{
		muda_array_Drecrese(array_teste1);
	}	  
}

void cresceMenu(int maximo,int array_teste1[4][2]){
	display.clearDisplay();
	menucounter += 1;
	if(menucounter > maximo){//valor do menu nao pode ser maior que 3
		menucounter = maximo;
	}
	else{
		muda_array_Crese(array_teste1);
	}  
}
void readbuttons(){
	buttonState1 = digitalRead(buttonPin1);
	buttonState2 = digitalRead(buttonPin2);
	buttonState3 = digitalRead(buttonPin3);

}

void main_F(){
	readbuttons();
	if(buttonState1 == HIGH){
		decreseMenu(array_botoes);	  
	}
	  
	if (buttonState3 == HIGH){
	cresceMenu(3,array_botoes);	
	}	
	    

	pagina_1();

	 
	    
	    
	if (buttonState2 == HIGH){
		display.clearDisplay();
		if(menucounter == 0){
			while(true){
				readbuttons();
				if(buttonState1 == HIGH){
					decreseMenu(array_botoes2);	  
				}
				if (buttonState3 == HIGH){
					cresceMenu(1,array_botoes2);	
				}			
				pagina_2();
			}
		}
		
	if(menucounter == 1){
			while(true){
				readbuttons();
				if(buttonState1 == HIGH){
					decreseMenu(array_botoes3);	  
				}
				if (buttonState3 == HIGH){
					cresceMenu(1,array_botoes3);	
				}			
				pagina_3();
			}
	}
}
}	    
	   
	    
  
void loop() {
main_F();
}
