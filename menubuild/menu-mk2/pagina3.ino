
void pagina_3(int array_botoes[5][2]){
  display.setTextSize(1); 
  display.setTextColor(array_botoes[0][1], array_botoes[0][0]);
  display.setCursor(0,0);
  display.println("TRANSMIT IF");
 

  display.setTextColor(array_botoes[1][1], array_botoes[1][0]); 
  display.setCursor(0,9);
  display.println("RECIEVE IF");
  
  




  display.setTextColor(1,0); 
  display.setCursor(0,50);//for debug 
  display.print(menupagina3, DEC);
  display.display();
  delay(500);}
