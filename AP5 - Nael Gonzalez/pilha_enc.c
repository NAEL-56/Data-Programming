#include "pilha_enc.h"
#include "fila_enc.h"
#include <stdio.h>
#include <stdlib.h>

// Funcao que cria uma pilha
PilhaEnc* criaPilha(){
   PilhaEnc *pilha = (PilhaEnc*)malloc(sizeof(PilhaEnc));
   pilha->topo = NULL;
   return pilha;
}

// Funcao que destroi uma pilha
void destroiPilha(PilhaEnc *pilha){
   NodoLEnc *aux = pilha->topo;
   while(aux != NULL){
       NodoLEnc *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(pilha);
}

// Funcao que insere um elemento na pilha
void empilhaPilha(PilhaEnc *pilha, Info info){
   NodoLEnc *novo = (NodoLEnc*)malloc(sizeof(NodoLEnc));
   novo->info = info;
   novo->prox = pilha->topo;
   pilha->topo = novo;
}

// Funcao que remove um elemento da pilha
Info desempilhaPilha(PilhaEnc* pilha){
   NodoLEnc *aux = pilha->topo; 
   /* Aqui assumimos que desempilha eh 
   chamada apenas se a pilha nao eh vazia */
   Info info = aux->info;
   pilha->topo = aux->prox;
   free(aux);
   return info;
}

// Funcao que determina se uma pilha eh vazia
int vaziaPilha(PilhaEnc *pilha){
   return (pilha->topo == NULL);
}

// Funcao que inverte a ordem dos nodos de uma pilha
void invertePilha(PilhaEnc *pilha){
	/*						CODIGO BONUS
	FilaEnc *filaAux;
	filaAux = criaFila();
	
   while(!vaziaPilha(pilha)){
    	enfileiraFila(filaAux, desempilhaPilha(pilha) );
   }
   
	while(!vaziaFila(filaAux)){
    	empilhaPilha(pilha, desenfileiraFila(filaAux) );
   }
   
   destroiFila(filaAux);
   */
	
	PilhaEnc *pilhaAux[2];
	pilhaAux[0] = criaPilha();
	pilhaAux[1] = criaPilha();
	
	while(!vaziaPilha(pilha)){
    	empilhaPilha(pilhaAux[0], desempilhaPilha(pilha) );
   }
   
   while(!vaziaPilha(pilhaAux[0])){
    	empilhaPilha(pilhaAux[1], desempilhaPilha(pilhaAux[0]) );
   }
   
   while(!vaziaPilha(pilhaAux[1])){
    	empilhaPilha(pilha, desempilhaPilha(pilhaAux[1]) );
   }
   
   destroiPilha(pilhaAux[0]);
   destroiPilha(pilhaAux[1]);
}
