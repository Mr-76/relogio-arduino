/*   decresce o array com um valor minimo  == a 0 pois se for menor que 0 o elemento no array nao exite*/

void decreseMenu(int array_teste1[4][2],int &menu){
	display.clearDisplay();
	menu -= 1;
	if(menu < 0){//valor do menu nao pode ser menor que 0
		menu = 0;
	}
	else{
		muda_array_Drecrese(array_teste1,menu);//array de decrescer
	}	  
}
