#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

typedef struct Dado{       // <--.  Dado
	int id;				   //    :    '
	char nome[15];		   //    :    '
}aviao;				  	   // <--'  aviao }-------.
//                                             (FORMA)
typedef struct Elemento{   // <--.  Elemento <----'
	aviao aeronave;        //	 :     '
	struct Elemento *prox; //	 :	   '
}no;                       // <--'	   no }-------.
//                                             (FORMA)
typedef struct Lista{      // <--.   Lista <------'
	no *ini;               //    :     '
	no *fim;               //	 :     '
	int tam;               //	 :     '
}fila;                     // <--'	  fila


fila *Alocar_Fila();

void Inserir_Aviao(fila *Fila);

void Printar_Design_Aviao(int i);

void Printar_Fila(fila *Fila);

void Animacao_Decolagem(fila *Fila);

void Decolagem_Aviao(fila *Fila_Pista);

#endif
