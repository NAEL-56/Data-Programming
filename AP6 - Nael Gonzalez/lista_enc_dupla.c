#include "lista_enc_dupla.h"
#include <stdio.h>
#include <stdlib.h>

// Funcao que cria uma lista
ListaEnc2* criaLista(){
   ListaEnc2 *lista = (ListaEnc2*)malloc(sizeof(ListaEnc2));
   lista->prim = NULL;
   return lista;
}

// Funcao que destroi uma lista
void destroiLista(ListaEnc2 *lista){
   NodoLEnc2 *aux = lista->prim;
   while(aux != NULL){
       NodoLEnc2 *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(lista);
}

// Funcao que imprime todos os nodos de uma lista
void imprimeLista(ListaEnc2 *lista){
   NodoLEnc2 *aux;
   printf("-----------------------------------------\n");
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      printf("%d | %s (%s)\n", aux->info.matricula,
                               aux->info.nome,
                               aux->info.email);
   printf("-----------------------------------------\n");
}

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoLista(ListaEnc2* lista, int matricula){
   NodoLEnc2 *aux;
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      if (aux->info.matricula == matricula)
         return aux;
   return NULL; 
}

// Funcao que insere um nodo no inicio de uma lista
int insereInicioLista(ListaEnc2 *lista, Info info){
   NodoLEnc2 *novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2));
   novo->info = info;
   novo->ant = NULL;
   novo->prox = lista->prim;
   if (lista->prim != NULL)
      lista->prim->ant = novo;
   lista->prim = novo;
   return 1;
}

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoLista(ListaEnc2* lista, int matricula){
   NodoLEnc2 *aux = lista->prim; 
   while(aux != NULL && aux->info.matricula != matricula){
      aux = aux->prox;
   }
   if (aux != NULL){
      if (aux->ant == NULL){
         lista->prim = aux->prox;
         if (aux->prox != NULL)
            aux->prox->ant = NULL;   
      }else{
         aux->ant->prox = aux->prox;
         if (aux->prox != NULL)
            aux->prox->ant = aux->ant;            
      }
      free(aux);
      return 1;
   }
   return 0; // Nao encontrou
}

// Funcao que insere um nodo em um posição específica, feita para treinar ponteiros
int inserePosicaoLista(ListaEnc2 *lista, int posicao, Info info){
	NodoLEnc2 *novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2));
	int i=1;
	
	novo->info = info;
	novo->prox = lista->prim;
	
	posicao--; //o cliente assume que a lista começa na posição 1, mas o programa trabalha como se a lista comece na posição 0
	
	if(posicao < 0) return 0; //previne entrada errada fornecida pelo usuário
	
	if(!posicao){
		lista->prim = novo;
		novo->ant = NULL;
	}
	else{
		novo->ant = lista->prim;
		
		for(;i<posicao;i++){
			if (novo->ant->prox == NULL) return 0;
			
			novo->ant = novo->ant->prox;
		}
		novo->prox = novo->ant->prox;
		novo->ant->prox = novo;
		
		if(novo->prox != NULL)
			novo->prox->ant = novo;
	}

	return 1;
}

// Funcao que imprime uma lista em ordem contrária
void imprimeInversoLista(ListaEnc2 *lista){
	NodoLEnc2 *aux;
	printf("-----------------------------------------\n");
   
	if(lista->prim != NULL){
		for(aux = lista->prim; aux->prox != NULL; aux = aux->prox){}

		for(; aux != NULL; aux = aux->ant){
			printf("%d | %s (%s)\n", aux->info.matricula,
	                               aux->info.nome,
	                               aux->info.email);
		printf("-----------------------------------------\n");
		}
	}
}

// Funcao que cria e devolve a cópia de uma lista dada
ListaEnc2* copiaLista(ListaEnc2 *lista){
	ListaEnc2 *copia = criaLista();
	NodoLEnc2 *aux;
	int status;
	
	if(lista->prim != NULL){
		for(aux = lista->prim; aux->prox != NULL; aux = aux->prox){}
   
		for(; aux != NULL; aux = aux->ant)
			status = insereInicioLista(copia, aux->info);
	}
	
	return copia;
}

// Funcao que insere um elemento na lista em ordem decrescente de matrícula
int insereOrdenadoLista(ListaEnc2 *lista, Info info){
	
	NodoLEnc2 *novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2)), *aux;
	
	if (novo == NULL) return 0; // Nao ha espaco em memoria
    	
	novo->info = info;
	
	if(lista->prim == NULL){
		novo->prox = NULL;
		lista->prim = novo;
		novo->ant = NULL;
	}
	else{
		if (info.matricula > lista->prim->info.matricula){
			novo->prox = lista->prim;
			lista->prim = novo;
			novo->ant = NULL;
			novo->prox->ant = novo;
		}
		else{
			for(aux = lista->prim; aux->prox != NULL && aux->prox->info.matricula > info.matricula; aux = aux->prox){}
	   		
	   		novo->prox = aux->prox;
	   		novo->ant = aux;
	   		aux->prox = novo;
	   		if(novo->prox != NULL)
	   			novo->prox->ant = novo;
		}
	}
	
	return 1;
}
