void muda_array_Crese(int testearray[4][2],int &menu){
	testearray[menu][0] = 1;//selecionado
	testearray[menu][1] = 0;
	  
	testearray[(menu - 1)][0] = 0;//nao selecionado
	testearray[(menu - 1)][1] = 1;  
}
