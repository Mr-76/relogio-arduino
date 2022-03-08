
void set_alarme(){
          DateTime now = rtc.now();
 // dps adicionar valores defaut de horas como as do momento
          //ex: sao 15:30:20 -- displaty do alarme deixa modificar a partir
          //desse valor
          display.clearDisplay();
          display.setTextSize(1.5); 
          display.setTextColor(1,0);
          display.setCursor(37,20);
          display.println("ALARM MENU");
          display.display();
          delay(5000);//impedir falso input
		      display.clearDisplay();
          
          array_alarme[1] = now.hour();
          array_alarme[2] = now.minute();
          array_alarme[3] = now.second();

			    for(int i = 1;i< sizeof(array_alarme)/(sizeof(array_alarme[0]));i++){
          display.clearDisplay();//limpar mensagem NEXT
          

          while(true){
            
            readbuttons();
            display.setTextSize(2); 
          
            display.setTextColor(1,0);
            display.setCursor(10,18);
            display.println(array_alarme[1],DEC);
            
            display.setTextColor(1,0);
            display.setCursor(50,18);
            display.println(array_alarme[2],DEC);
              
            display.setTextColor(1,0);
            display.setCursor(100,18);
            display.println(array_alarme[3],DEC);
            

          
            display.display();
            
            if(buttonState1 == HIGH){
              array_alarme[i] += 1;
              if ((array_alarme[i] >= 60) || (array_alarme[i] < 0)){
                array_alarme[i] = 0;
              }
              display.clearDisplay();
            }	
            if(buttonState3 == HIGH){
              array_alarme[i] -= 1;
              if ((array_alarme[i] >= 60) || (array_alarme[i] < 0)){
                array_alarme[i] = 0;
              }
              display.clearDisplay();
            }			

            if(buttonState2 == HIGH){
              display.clearDisplay();
              display.setTextSize(2); 
              display.setTextColor(1,0);
              display.setCursor(40,25);
              display.println("NEXT");
              display.display();
              delay(2000);
              break;
					}
				}
      }
      array_alarme[0] = 1;//ligar alarme

        
}