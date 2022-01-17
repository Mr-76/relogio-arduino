void pagina_4(){
  display.setTextSize(1); 
  display.setTextColor(array_botoes4[0][1], array_botoes4[0][0]);
  display.setCursor(0,0);
  display.println("ALARM");
  display.display();
 

  display.setTextColor(array_botoes4[1][1], array_botoes4[1][0]); 
  display.setCursor(0,9);
  display.println("TIMER_UP");
  display.display();


  display.setTextColor(array_botoes4[2][1], array_botoes4[2][0]); 
  display.setCursor(0,18);
  display.println("TIMER_DOWN");
  display.display();


  display.setTextColor(1,0); 
  display.setCursor(0,40);//for debug 
  display.print(menucounter, DEC);
  display.println("(DEC)");
  display.display();
  delay(500);  
}

