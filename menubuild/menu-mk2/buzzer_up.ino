void buzzer_up(){
  const int buzzer = 9;
  pinMode(buzzer, OUTPUT);
                    
  for (int i = 0;i<100;i++){
                    
      analogWrite(buzzer,900);
      // tone(buzzer, 1000); // Send 1KHz sound signal...
      delay(100);
      analogWrite(buzzer,0);       // ...for 1 sec
      // noTone(buzzer);     // Stop sound...
      delay(100); 
  }
  analogWrite(buzzer,0);
}
