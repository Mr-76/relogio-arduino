void pagina_5(){
  while(true){
    int sensorValue = analogRead(A0);
    float voltage= sensorValue * (5.0 / 1023.0);
    display.setTextSize(1); 
    display.setTextColor(1, 0);
    display.setCursor(0,0);
    display.println("VOLTAGEM PROBE");
  
    display.setTextColor(1,0); 
    display.setCursor(0,20);
    display.print(voltage, DEC);
    display.display();
  delay(500);
 }
}

