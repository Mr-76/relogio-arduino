#include "arrays_paginas.h"
void main_F(){
	readbuttons();//le os botoes
	
  	if(buttonState1 == HIGH){
		decreseMenu(array_botoes,menupagina1);	//decrementa o seletor do menu 
	}
	  
	if (buttonState3 == HIGH){
	  cresceMenu(3,array_botoes,menupagina1);	//incrementa o seletor do menu
	}	
	    

	pagina_1();//mostra a 1 pagina
   
	if (buttonState2 == HIGH){
		
		display.clearDisplay();//limpa o display
		
		if(menupagina1 == 0){
      

			while(true){
				readbuttons();
				if(buttonState1 == HIGH){
					decreseMenu(array_botoes2,menupagina2);	  
				}
				if (buttonState3 == HIGH){
					cresceMenu(1,array_botoes2,menupagina2);	
				}			
				pagina_2();//mostra a 2 pagina
				
				if(readexit()){
					break;
				}

			}
		}
		
	  if(menupagina1 == 1){
     
			while(true){
				readbuttons();
				if(buttonState1 == HIGH){
					decreseMenu(array_botoes3,menupagina3);	  
				}
				if (buttonState3 == HIGH){
					cresceMenu(1,array_botoes3,menupagina3);	
				}			
				pagina_3();//mostra a 3 pagina
				
				if(readexit()){
					break;
				}

			}
    }
    
    if(menupagina1 == 2){
      while(true){
        readbuttons();
        if (buttonState1 == HIGH){
          decreseMenu(array_botoes4,menupagina4);
        }
        
        if (buttonState3 == HIGH){
          cresceMenu(2,array_botoes4,menupagina4);
        }  
        pagina_4();  //mostra a 4 pagina      
      	if (readexit()){
			    break;
	      }
	}
    }
    if (menupagina1 == 3){
      display.clearDisplay();
      while(true){
      readbuttons();
      pagina_5();

      }
    }
}
}
