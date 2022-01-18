int array_botoes[4][2] = {
  {1,0},
  {0,1},
  {0,1},
  {0,1}
};
void pagina_1(){
  
  display.setTextSize(1); 
  display.setTextColor(array_botoes[0][1], array_botoes[0][0]);
  display.setCursor(0,0);
  display.println("RF");
  display.display();
 

  display.setTextColor(array_botoes[1][1], array_botoes[1][0]); 
  display.setCursor(0,9);
  display.println("INFRA RED");
  display.display();
  

  display.setTextColor(array_botoes[2][1], array_botoes[2][0]); 
  display.setCursor(0,18);
  display.println("ALARM");
  display.display();
 

  display.setTextColor(array_botoes[3][1], array_botoes[3][0]); 
  display.setCursor(0,27);
  display.println("VOLTAGE");
  display.display();

  display.setTextColor(1,0); 
  display.setCursor(0,40);//for debug 
  display.print(menucounter, DEC);
  display.println("(DEC)");
  display.display();
  delay(2000);
 

}
