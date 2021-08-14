#include "fila.h"

int main (void){
	setlocale(LC_ALL, "portuguese");
	fila *Fila_Pista=Alocar_Fila();
	char op, sub_op;
	int aviao_pista;
	
	do{
		system("CLS");
		op='0';
		printf("1 - Número de aviões aguardando decolagem\n2 - Autorizar decolagem do primeiro avião\n3 - Adicionar um avião na fila da pista\n4 - Listar os aviões em espera\n");
		scanf("%c", &op);
		switch(op){
			
			case '1':
				system("CLS");
				printf("0 - Voltar\n\n");
				printf("Aviões aguardando decolagem: %d\n\n", Fila_Pista->tam);
				printf("`-> ");
				scanf("%s", &sub_op);
				break;
			
			case '2':
				do{
					system("CLS");
					if(Fila_Pista->tam > 0){
						printf("0 - Voltar   |   1 - Autorizar Decolagem\n\n\n");
						Printar_Fila(Fila_Pista);
						printf("\n`-> ");
						scanf("%s", &sub_op);
						if (sub_op == '1')
							Decolagem_Aviao(Fila_Pista);
					} else{
						system("CLS");
						printf("0 - Voltar   |   1 - Autorizar Decolagem\n\n");
						Printar_Fila(Fila_Pista);
						printf("`-> ");
						scanf("%s", &sub_op);
						sub_op='0';
					}
				}while(sub_op == '1');
				break;
			
			case '3':
				do{
					system("CLS");
					printf("0 - Voltar   |   1 - Inserir Aeronave\n\n");
					Inserir_Aviao(Fila_Pista);
					printf("`-> ");
					scanf("%s", &sub_op);
				}while(sub_op == '1');
				break;
			
			case '4':
				system("CLS");
				printf("0 - Voltar\n\n");
				Printar_Fila(Fila_Pista);
				printf("`-> ");
				scanf("%s", &sub_op);
				break;
		}
	}while(1);
	
}
