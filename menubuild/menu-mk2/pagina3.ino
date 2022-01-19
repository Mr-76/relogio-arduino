void pagina_3(){
  display.setTextSize(1); 
  display.setTextColor(array_botoes3[0][1], array_botoes3[0][0]);
  display.setCursor(0,0);
  display.println("TRANSMIT IF");
  display.display();
 

  display.setTextColor(array_botoes3[1][1], array_botoes3[1][0]); 
  display.setCursor(0,9);
  display.println("RECIEVE IF");
  display.display();
}