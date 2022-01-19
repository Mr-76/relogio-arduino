void pagina_1(){
  display.display();
  display.setTextSize(1); 
  display.setTextColor(array_botoes[0][1], array_botoes[0][0]);
  display.setCursor(0,0);
  display.println("RF");
  

  display.setTextColor(1,0);
  display.setCursor(90,2);
  display.println("15:41");
  

  display.setTextColor(1,0);
  display.setCursor(80,14);
  display.println("19/01/22");
   

  display.setTextColor(array_botoes[1][1], array_botoes[1][0]); 
  display.setCursor(0,9);
  display.println("INFRA RED");
  
  

  display.setTextColor(array_botoes[2][1], array_botoes[2][0]); 
  display.setCursor(0,18);
  display.println("ALARM");
  
 

  display.setTextColor(array_botoes[3][1], array_botoes[3][0]); 
  display.setCursor(0,27);
  display.println("VOLTAGE");
  

  display.setTextColor(array_botoes[4][1], array_botoes[4][0]);  
  display.setCursor(0,39);
  display.println("GPS");
  

  display.setTextColor(1,0); 
  display.setCursor(0,50);//for debug 
  display.print(menupagina1, DEC);
  display.println("(DEC)");
  
  delay(500);
  
 

}