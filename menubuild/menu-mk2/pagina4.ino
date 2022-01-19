void pagina_4(){
display.display();

display.setTextSize(1); 
display.setTextColor(array_botoes4[0][1], array_botoes4[0][0]);
display.setCursor(0,0);
display.println("ALARM");



display.setTextColor(array_botoes4[1][1], array_botoes4[1][0]); 
display.setCursor(0,9);
display.println("TIMER_UP");



display.setTextColor(array_botoes4[2][1], array_botoes4[2][0]); 
display.setCursor(0,18);
display.println("TIMER_DOWN");



display.setTextColor(1,0); 
display.setCursor(0,40);//for debug 
display.print(menupagina4, DEC);
display.println("(DEC)");

delay(500);  
}