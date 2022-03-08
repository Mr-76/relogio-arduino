void timer_down(){
  display.clearDisplay();
          delay(1000);

			    for(int i = 0;i< sizeof(array_timer_down)/(sizeof(array_timer_down[0]));i++){
          display.clearDisplay();//limpar mensagem NEXT
          while(true){
            
            readbuttons();
            display.setTextSize(2); 
          
            display.setTextColor(1,0);
            display.setCursor(10,18);
            display.println(array_timer_down[0],DEC);
            
            display.setTextColor(1,0);
            display.setCursor(50,18);
            display.println(array_timer_down[1],DEC);
              
            display.setTextColor(1,0);
            display.setCursor(100,18);
            display.println(array_timer_down[2],DEC);
            

            display.setTextSize(1); 
            display.setTextColor(1,0);
            display.setCursor(10,50);
            display.println(i,DEC);
            display.display();
            
            if(buttonState1 == HIGH){
              array_timer_down[i] += 1;
            }	
            if(buttonState3 == HIGH){
              array_timer_down[i] -= 1;	
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
        display.clearDisplay();
        int segundos = 0;
        segundos = (array_timer_down[0]*360) + (array_timer_down[1] * 60) + array_timer_down[2];
        while(true){
          readbuttons();
          display.setTextSize(2); 
          display.setTextColor(1,0);
          display.setCursor(40,25);
          display.println(segundos,DEC);
          display.display();
          segundos--;
          delay(1000);
          if (readexit()){
			      break;
	        }
        }



}