void timer_up(){
  int seconds = 0;
    display.clearDisplay();
      while(true){
          readbuttons();
          display.setTextSize(1);
          display.setTextColor(1,0);
          display.setCursor(50,18);
          display.println(seconds,DEC);
          display.display();
          seconds++;
          delay(600);

            
          if (readexit()){
			        break;
	          }
          }


}