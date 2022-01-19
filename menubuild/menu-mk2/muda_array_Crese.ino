/* a funcao modifica o array em ordem crescente
modifica 1 o valor atual de nao selecinado para selecionado 
e depois modifica o valor do anterior de selecioando para nao selecionado
lembrando na funcao display.setTextColor(x, y) x eh o back light e y as letras
x = letra letra = 1 letra acende
y = backlight back light = 0 back light apaga
*/


void muda_array_Crese(int testearray[4][2],int &menu){
	testearray[menu][0] = 1;//selecionado 
	testearray[menu][1] = 0;
	  
	testearray[(menu - 1)][0] = 0;//nao selecionado
	testearray[(menu - 1)][1] = 1;  
}
