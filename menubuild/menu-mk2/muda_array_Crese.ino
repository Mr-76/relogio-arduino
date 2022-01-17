void muda_array_Crese(int testearray[4][2]){
	testearray[menucounter][0] = 1;//selecionado
	testearray[menucounter][1] = 0;
	  
	testearray[(menucounter - 1)][0] = 0;//nao selecionado
	testearray[(menucounter - 1)][1] = 1;  
}
