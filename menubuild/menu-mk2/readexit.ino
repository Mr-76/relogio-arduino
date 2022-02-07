int readexit(){
	buttonState1 = digitalRead(buttonPin1);
	buttonState3 = digitalRead(buttonPin3);
	
	if ((buttonState1 == 1) && (buttonState3 == 1)){

	return 1;

	}  
	else{
	return 0;
	}

}
