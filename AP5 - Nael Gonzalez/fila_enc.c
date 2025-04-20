#include "fila_enc.h"
#include "pilha_enc.h"
#include <stdio.h>
#include <stdlib.h>

// Funcao que cria uma fila
FilaEnc* criaFila(){
   FilaEnc *fila = (FilaEnc*)malloc(sizeof(FilaEnc));
   fila->ini = NULL;
   fila->fim = NULL;
   return fila;
}

// Funcao que destroi uma fila
void destroiFila(FilaEnc *fila){
   NodoLEnc *aux = fila->ini;
   while(aux != NULL){
       NodoLEnc *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(fila);
}

// Funcao que insere um elemento na fila
void enfileiraFila(FilaEnc *fila, Info info){
   NodoLEnc *novo = (NodoLEnc*)malloc(sizeof(NodoLEnc));
   novo->info = info;
   novo->prox = NULL;
   if (fila->fim != NULL)
      fila->fim->prox = novo;
   else
      fila->ini = novo;
   fila->fim = novo;
}

// Funcao que remove um elemento da fila
Info desenfileiraFila(FilaEnc *fila){
   NodoLEnc *aux = fila->ini; 
   Info info = aux->info;
   fila->ini = aux->prox;
   if (fila->ini == NULL)
      fila->fim = NULL;
   free(aux);
   return info;
}

// Funcao que determina se uma fila eh vazia
int vaziaFila(FilaEnc *fila){
   return (fila->ini == NULL);
}

// Funcao que inverte a ordem dos nodos de uma fila
void inverteFila(FilaEnc *fila){
	PilhaEnc *pilhaAux;
	pilhaAux = criaPilha();
	
	Info infoAux;
	
	while(!vaziaFila(fila)){
    	infoAux = desenfileiraFila(fila);
    	empilhaPilha(pilhaAux, infoAux);
   }
   
   while(!vaziaPilha(pilhaAux)){
   		infoAux = desempilhaPilha(pilhaAux);
    	enfileiraFila(fila, infoAux);
   }
   
   destroiPilha(pilhaAux);
}

