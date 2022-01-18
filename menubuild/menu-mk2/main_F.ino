#include "pagina1.h"
#include "pagina2.h"
#include "pagina3.h"
#include "pagina4.h"
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
    
    if(menucounter == 2){
      int menuclock = 0;
      while(true){
        readbuttons();
        if (buttonState1 == HIGH){
          decreseMenu(array_botoes4);
        }
        
        if (buttonState3 == HIGH){
          cresceMenu(2,array_botoes4);
        }
        pagina_4();        
      }
    }
}
}	   
