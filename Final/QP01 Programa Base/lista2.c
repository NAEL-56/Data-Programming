#include "lista2.h"
#include <stdio.h>
#include <stdlib.h>

// Funcao que cria uma lista
Lista2* criaLista2(){
   Lista2 *lista = (Lista2*)malloc(sizeof(Lista2));
   lista->prim = NULL;
   return lista;
}

// Funcao que destroi uma lista
void destroiLista2(Lista2 *lista){
   NodoLista2 *aux = lista->prim;
   while(aux != NULL){
       NodoLista2 *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(lista);
}

// Funcao que insere um nodo no inicio de uma lista
int insereInicioLista2(Lista2 *lista, int info){
   NodoLista2 *novo = (NodoLista2*)malloc(sizeof(NodoLista2));
   novo->info = info;
   novo->ant = NULL;
   novo->prox = lista->prim;
   if (lista->prim != NULL)
      lista->prim->ant = novo;
   lista->prim = novo;
   return 1;
}

