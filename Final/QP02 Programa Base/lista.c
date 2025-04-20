#include "lista.h"
#include <stdlib.h>

// Funcao que cria uma lista
Lista* criaLista(){
   Lista *lista = (Lista*)malloc(sizeof(Lista));
   lista->prim = NULL;
   return lista;
}

// Funcao que destroi uma lista
void destroiLista(Lista *lista){
   NodoLista *aux = lista->prim;
   while(aux != NULL){
       NodoLista *tmp = aux->prox;
       free(aux); 
       aux = tmp;
   }
   free(lista);
}

// Funcao que insere um nodo no inicio de uma lista
void insereInicioLista(Lista *lista, char info){
   NodoLista *novo = (NodoLista*)malloc(sizeof(NodoLista));
   novo->info = info;
   novo->prox = lista->prim;
   lista->prim = novo;
}
