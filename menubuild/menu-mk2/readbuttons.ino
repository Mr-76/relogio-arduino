/* funcao le os estados dos botoes , HIGH e LOW*/
void readbuttons(){
	buttonState1 = digitalRead(buttonPin1);
	buttonState2 = digitalRead(buttonPin2);
	buttonState3 = digitalRead(buttonPin3);
}
