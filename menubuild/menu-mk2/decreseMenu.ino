void decreseMenu(int array_teste1[4][2]){
	display.clearDisplay();
	menucounter -= 1;
	if(menucounter < 0){//valor do menu nao pode ser menor que 0
		menucounter = 0;
	}
	else{
		muda_array_Drecrese(array_teste1);
	}	  
}
