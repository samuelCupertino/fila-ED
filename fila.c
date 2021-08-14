#include "fila.h"

fila *Alocar_Fila(){
	
	fila *fila_alocada=(fila*)malloc(sizeof(fila)); // Alocar espaco para fila 
	
	if(fila_alocada == NULL){  // Se Alocacao falhou finaliza execucao
		printf("Erro de Memória :(");
		exit(1);
	}
	
	fila_alocada->ini=NULL; // Se deu certo a alocacao, iniciaiza as variaveis da fila
	fila_alocada->fim=NULL;
	fila_alocada->tam=0;
	
	return fila_alocada;
}

void Inserir_Aviao(fila *Fila){
	no *n_aviao=(no*)malloc(sizeof(no)); // Alocar espaco para um nó de elemento aviao 
	
	if(n_aviao == NULL){  // Se Alocacao falhou finaliza execucao
		printf("Erro de Memória :(");
		exit(1);
	}
	
	printf("Informe o ID do avião: "); // Preenchimento dos dados do aviao
	scanf("%d", &n_aviao->aeronave.id);
	printf("Informe o Nome do avião: ");
	fflush(stdin);
	gets(n_aviao->aeronave.nome);
	n_aviao->prox=NULL;
	
	if(Fila->ini == NULL){ // Se nao ha aviao na fila, o novo aviao será o 1º
		Fila->ini=n_aviao;
		Fila->fim=n_aviao;
		Fila->tam=1;
	} else{               // Se ha aviao na fila, o novo aviao será o ultimo
		Fila->fim->prox=n_aviao;
		Fila->fim=n_aviao;
		Fila->tam++;
	}
	printf("Inserido com Sucesso!\n\n");
}


void Printar_Design_Aviao(int i){  // Funcao dedicada a printar desenho do aviao antes das informacoes do aviao que ele representa  
	char design_aviao[3][8]={"  /\\  ", "/-||-\\", "  /\\  "};

	printf("%s", design_aviao[i]); // Printa uma linha especifica do desenho do aviao referente a variavel 'i'
}

void Printar_Fila(fila *Fila){  // Funcao dedicada a printar a fila de avioes com o desenho e as informacoes de cada aviao  
	int i=0;
	no *aux=Fila->ini; // aux recebe o que ha no inicio da fila
	
	if (aux != NULL){	// Se ha um aviao no inicio da fila, printa os dados dele e dos demais da fila a partir dele 
		while(Fila->tam > i){
			i++;
			Printar_Design_Aviao(0); // Manda para funcao printar a 1º linha do desenho do aviao 
			printf("      .- %dº Aeronave\n", i);
			Printar_Design_Aviao(1); // Manda para funcao printar a 2º linha do desenho do aviao 
			printf("    <-:  ID: %d\n", aux->aeronave.id);
			Printar_Design_Aviao(2); // Manda para funcao printar a 3º linha do desenho do aviao 
			printf("      `- Nome: %s\n\n", aux->aeronave.nome);
			aux=aux->prox; //passa para o proximo aviao a ser printado 
		}
	} else{			      // Se nao ha um aviao no inicio da fila, printa que a Pista esta vazia
		printf("Pista Vazia\n\n");
	}

}

void Animacao_Decolagem(fila *Fila){
	char design_aviao[6][7]={"      ", "      ", "      ", "  /\\  ", "/-||-\\", "` /\\ ´"};
	char voo[7]={"|    |"};
	char limp[7]={"      "};
	int f=0; //  f - Quantidade de frames 
	int a;	 //  a - Aux para printar aviao (string: design_aviao) 
	int p;   //  p - Aux para mudar a posicao do aviao 
	
	while(f <= 8){ // Printar os 6 frame que compoe o movimento do aviao
		system ("CLS");
		
		a=0;
		while(a < 6){ // Printar o aviao na posicao que ele esta dentro da string (em cada frame a posicao muda, simulando movimento)
			printf("%s\n", design_aviao[a]);
			a++;
			
		}
		printf("\n");
				
		Printar_Fila(Fila); // Printar a fila de avioes atras do aviao que "se movimenta"
	
		if (f == 0) // delay de ligando turbinas
			Sleep(400);
				
		Sleep(150); // Delay na atualizacao do proximo frame (para simular o movimento) 
		
		p=0;
		while(p < a){ // Mudar a posicao do aviao dentro da string (atualizando o frame)
			if(p < a-1)
				strcpy(design_aviao[p], design_aviao[p+1]); // Mudar a posicao do aviao dentro da string
			else if(f < 2)
				strcpy(design_aviao[p], voo);  // Adicionar efeito de voo na asa do aviao dentro da string
			else
				strcpy(design_aviao[p], limp); // Limpar a ultima coluna da string para a cauda do aviao nao se repetir
			p++;
		}
		f++;
	}
	
	while(f > 4){ // Printar a fila de avioes avancando para posicao de partida 
		system ("CLS");
		
		a=f;
		while(a > 3){ // Printar a distancia da fila de avioes diminuindo em relacao a posicao de partida
			printf("%s\n", limp);
			a--;
		}
		printf("\n");
		
		Printar_Fila(Fila); // A cada distancia diminuida a lista se atualiza (para da o efeito de locomocao)
		
		Sleep(500);  // Delay na atualizacao do proximo frame (para simular o movimento)
		f--;
	}

}

void Decolagem_Aviao(fila *Fila_Pista){
	no *aux=Fila_Pista->ini; // aux recebe o aviao inicial da fila 
	
	Fila_Pista->ini=Fila_Pista->ini->prox; // o aviao inicial da fila pista  = passa a ser =  o proximo     
	Fila_Pista->tam--;
	
	free(aux); // O ex aviao inicial, é liberado
	Animacao_Decolagem(Fila_Pista); // iniciar animacao de aviao decolando
}

