#ifndef _LISTA_2_H_
#define _LISTA_2_H_

typedef struct nodoLista2{
   int info;
   struct nodoLista2 *ant;
   struct nodoLista2 *prox;
} NodoLista2;

typedef struct{
   NodoLista2 *prim;
} Lista2;

// Funcao que cria uma lista
Lista2* criaLista2();

// Funcao que destroi uma lista
void destroiLista2(Lista2 *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioLista2(Lista2 *lista, int info);

#endif
