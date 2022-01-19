/*   decresce o array com um valor maximo  == a 0 pois se for menor que 0 o elemento no array nao exite*/

void cresceMenu(int maximo,int array_teste1[4][2],int &menu){
	display.clearDisplay();
	menu += 1;
	if(menu > maximo){//valor do menu nao pode ser maior que 3
		menu = maximo;
	}
	else{
		muda_array_Crese(array_teste1,menu);// o array cresce
	}  
}
