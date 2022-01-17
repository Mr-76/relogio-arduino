void cresceMenu(int maximo,int array_teste1[4][2]){
	display.clearDisplay();
	menucounter += 1;
	if(menucounter > maximo){//valor do menu nao pode ser maior que 3
		menucounter = maximo;
	}
	else{
		muda_array_Crese(array_teste1);
	}  
}
