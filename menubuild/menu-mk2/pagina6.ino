void pagina_6(){
  int a = 2;

  
  display.display();
  
  display.setTextSize(1); 
  display.setTextColor(1, 0);
  display.setCursor(0,0);
  
  display.println("VELOCIDADE: ");
  

  display.setTextSize(1); 
  display.setTextColor(1, 0);
  display.setCursor(73,0);
  display.print(a, DEC);
  

  display.setTextSize(1); 
  display.setTextColor(1, 0);
  display.setCursor(90,0);
  display.print("km/h");
  
 
 

  display.setTextColor(1, 0); 
  display.setCursor(0,20);
  display.println("LAT:111 LONG: 1923");
  

  

  display.setTextColor(1, 0); 
  display.setCursor(0,40);
  display.println("distancia  ");
  

}