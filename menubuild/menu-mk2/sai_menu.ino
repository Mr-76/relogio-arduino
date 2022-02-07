int sai_menu(){
	buttonState1 = digitalRead(buttonPin1);
	buttonState3 = digitalRead(buttonPin3);

  if ((buttonState1 == HIGH)  && (buttonState3 == HIGH)){
    
    return 1;

  }
  else{
    return 0;
  }
  
}