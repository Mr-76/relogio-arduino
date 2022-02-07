void pagina_5(){
  display.setTextSize(1); 
  display.setTextColor(1, 0);
  display.setCursor(0,0);
  display.println("VOLTAGEM BATERIA");
 

  display.setTextColor(1, 0); 
  display.setCursor(0,20);
  display.println("VOLTAGEM PROBES");
  display.display();
  delay(500); 
}

