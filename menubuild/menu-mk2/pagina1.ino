
void pagina_1(String horas,int time[3]){
  
  display.setTextSize(1); 
  display.setTextColor(array_botoes[0][1], array_botoes[0][0]);
  display.setCursor(0,0);
  display.println("RF");
   

  display.setTextColor(1,0);
  display.setCursor(90,2);
  display.println(horas);
   

  display.setTextColor(1,0);
  display.setCursor(80,14);
  display.println(time[0],DEC);
   
  
  display.setTextColor(1,0);
  display.setCursor(90,14);
  display.println(time[1],DEC);
   

  display.setTextColor(1,0);
  display.setCursor(100,14);
  display.println(time[2],DEC);
    

  display.setTextColor(array_botoes[1][1], array_botoes[1][0]); 
  display.setCursor(0,9);
  display.println("INFRA RED");
   
  

  display.setTextColor(array_botoes[2][1], array_botoes[2][0]); 
  display.setCursor(0,18);
  display.println("ALARM");
   
 

  display.setTextColor(array_botoes[3][1], array_botoes[3][0]); 
  display.setCursor(0,27);
  display.println("VOLTAGE");
   

  display.setTextColor(1,0); 
  display.setCursor(0,40);//for debug 
  display.print(menupagina1, DEC);
  display.println("(DEC)");
  display.display();
  delay(500);

}