#include <stdio.h.>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "estruturas.h"


int main(int argc, char** argv) {


func funcionario[30];
int quant_func=0;
rem remedio[400];
int cont_med=0;
vend venda[1000];
int cont_vendas=0;
int op;	
	do{
		op=menu(); 					//tudo aqui só faz chamar as funçoes, quando a função termina de executar ela da um 
		switch (op){				//getch pra ficar paradinha e se teclar qualquer tecla vai pro menu dnv.
	        case 1:
	        	quant_func=novo_funcionario(funcionario, quant_func);
	        	getch();
	        	op=0;
	            break;
	        case 2:
	        	soma_salario(funcionario, quant_func);
	        	getch();
	            op=0;
				break;
	        case 3:
	        	cont_med=cad_medicamento(remedio, cont_med);
	        	getch();
	            op=0;
				break;
	        case 4:
	        	teste_receita(remedio);
	        	getch();
	            op=0;
				break;
	        case 5:
	        	alterar_receita (remedio);
	        	getch();
	            op=0;
				break;
	        case 6:
	        	estoque (remedio);
	        	getch();
	            op=0;
				break;
	        case 7:
	        	att_estoque(remedio, cont_med);
	        	getch();
	        	op=0;
	            break;
	        case 8:
	        	qt_remedio_receita (remedio, cont_med);
	        	getch();
	        	op=0;
	        	break;
	        case 9:
				cont_vendas=nova_venda (venda, remedio, funcionario, quant_func, cont_med);
	        	getch();
	        	op=0;
	            break;
	        case 10:
	        	relatorio_data (venda, cont_vendas);
	        	getch();
	        	op=0;
	            break;
	        case 11:
	        	melhor_vendedor(funcionario, quant_func);
	        	getch();
	        	op=0;
	            break;
			case 12:
				gerador_xml(venda, cont_vendas);
	        	getch();
	        	op=0;
	            break;			
	        case 13:	
	        	exit(0);
	       		default:
	       		break;
    		}	
	}while(op<=0 || op>=14);
	system("PAUSE");
	return 0;
}
