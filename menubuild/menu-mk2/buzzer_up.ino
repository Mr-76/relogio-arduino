void buzzer_up(){
  const int buzzer = 9;
  
  pinMode(buzzer, OUTPUT);
                    
  for (int i = 0;i<100;i++){
                    
      analogWrite(buzzer,800);
      // tone(buzzer, 1000); // Send 1KHz sound signal...
      delay(1000);
      analogWrite(buzzer,100);       // ...for 1 sec
      // noTone(buzzer);     // Stop sound...
      delay(1000); 
  }
}
