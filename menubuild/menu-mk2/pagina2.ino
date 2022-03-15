
void pagina_2(int array_botoes[5][2]){
  display.setTextSize(1); 
  display.setTextColor(array_botoes[0][1], array_botoes[0][0]);
  display.setCursor(0,0);
  display.println("TRANSMIT_RF");
 

  display.setTextColor(array_botoes[1][1], array_botoes[1][0]); 
  display.setCursor(0,9);
  display.println("RECIEVE_RF");
 


  display.setTextColor(array_botoes[2][1], array_botoes[2][0]); 
  display.setCursor(0,20);
  display.println("REPEAT_RF");
 
  
  display.display();
  delay(500); 
}

