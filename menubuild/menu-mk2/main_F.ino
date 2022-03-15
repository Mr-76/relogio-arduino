#include "pagina1.h"
#include "pagina3.h"
#include "pagina4.h"

int array_botoes[5][2] = {
  {1,0},
  {0,1},
  {0,1},
  {0,1},
  {0,1}
};

int  inicializa_array_local(){
  static int array_botoe[5][2] = {
          {1,0},
          {0,1},
          {0,1},
          {0,1},
          {0,1}
        };
        return array_botoe;

      }
void main_F(int time[3]){

	readbuttons();//le os botoes
	
  	if(buttonState1 == HIGH){
		decreseMenu(array_botoes,menupagina1);	//decrementa o seletor do menu 
	}
	  
	if (buttonState3 == HIGH){
	  cresceMenu(4,array_botoes,menupagina1);	//incrementa o seletor do menu
	}	
	    

	pagina_1(time);//mostra a 1 pagina
   
	if (buttonState2 == HIGH){
		
		//display.clearDisplay();//limpa o display
		
		if(menupagina1 == 0){
      display.clearDisplay();
      int array_seletor = inicializa_array_local();

			while(true){

				readbuttons();
				if(buttonState1 == HIGH){
					decreseMenu(array_seletor,menupagina2);	  
				}
				if (buttonState3 == HIGH){
					cresceMenu(2,array_seletor,menupagina2);	
				}			
				pagina_2(array_seletor);//mostra a 2 pagina
				
				if(buttonState2 == HIGH){
					if(menupagina2 == 0){
           // mySwitch.send("000000000001010100010001");
            //delay(1000);
					}
					if(menupagina2 == 1){
					//recieve
					}
					if(menupagina2 == 2){
					//repeatLisen
					}
				}	
				if(readexit()){
					break;
				}

			}
		}
		
	  if(menupagina1 == 1){
      int array_seletor = inicializa_array_local();
      display.clearDisplay();

			while(true){
				readbuttons();
				if(buttonState1 == HIGH){
					decreseMenu(array_seletor,menupagina3);	  
				}
				if (buttonState3 == HIGH){
					cresceMenu(1,array_seletor,menupagina3);	
				}			
				pagina_3(array_seletor);//mostra a 3 pagina
				
				if(readexit()){
					break;
				}

			}
    }
    
    if(menupagina1 == 2){
      int array_seletor = inicializa_array_local();
      display.clearDisplay();
      while(true){
        readbuttons();
        if (buttonState1 == HIGH){
          decreseMenu(array_seletor,menupagina4);
        }
        
        if (buttonState3 == HIGH){
          cresceMenu(2,array_seletor,menupagina4);
        }  
        if(buttonState2 == HIGH){
 
        if(menupagina4 == 0){
          //liga alarme
         set_alarme();
        }
        if(menupagina4 == 1){
          timer_up();
        }
        if (menupagina4 == 2){
          timer_down();
  
        }
      }
	    pagina_4(array_seletor);
	    //mostra a 4 pagina      
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
      if (readexit()){
			    break;
	      }
      }
    }

 if (menupagina1 == 4){
      display.clearDisplay();
      while(true){
      readbuttons();
      pagina_6();
      if (readexit()){
			    break;
	      }
}
}
}
}
