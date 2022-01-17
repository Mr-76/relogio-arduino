void pagina_2(){
  display.setTextSize(1); 
  display.setTextColor(array_botoes2[0][1], array_botoes2[0][0]);
  display.setCursor(0,0);
  display.println("TRANSMIT  RF");
  display.display();
 

  display.setTextColor(array_botoes2[1][1], array_botoes2[1][0]); 
  display.setCursor(0,9);
  display.println("RECIEVE  RF");
  display.display();
}

