#include "pagina1.h"
#include "pagina2.h"
#include "pagina3.h"
#include "pagina4.h"
void main_F(){
	readbuttons();
	
  if(buttonState1 == HIGH){
		decreseMenu(array_botoes,menupagina1);	  
	}
	  
	if (buttonState3 == HIGH){
	  cresceMenu(3,array_botoes,menupagina1);	
	}	
	    

	pagina_1();
   
	if (buttonState2 == HIGH){
		
    display.clearDisplay();
		if(menupagina1 == 0){
      int sai = 0;

			while(true){
				readbuttons();
				if(buttonState1 == HIGH){
					decreseMenu(array_botoes2,menupagina2);	  
				}
				if (buttonState3 == HIGH){
					cresceMenu(1,array_botoes2,menupagina2);	
				}
        else{}	
				pagina_2();
        sai = sai_menu();
        if(sai == 1){
          break;
        }
        else{}
        
			}
		}
		
	  if(menupagina1 == 1){
      int sai = 0;
			while(true){
				readbuttons();
				if(buttonState1 == HIGH){
					decreseMenu(array_botoes3,menupagina3);	  
				}
				if (buttonState3 == HIGH){
					cresceMenu(1,array_botoes3,menupagina3);	
				}			
				pagina_3();
        sai = sai_menu();
        if(sai == 1){
          break;
        }
        else{}
			}
    }
    
    if(menupagina1 == 2){
      int sai = 0;
      int menuclock = 0;
      while(true){
        readbuttons();
        if (buttonState1 == HIGH){
          decreseMenu(array_botoes4,menupagina4);
        }
        
        if (buttonState3 == HIGH){
          cresceMenu(2,array_botoes4,menupagina4);
        }
        pagina_4();   
        sai = sai_menu();
        if(sai == 1){
          break;
        }
        else{}     
      }
    }
}
}	   
