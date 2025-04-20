#ifndef _LISTA_ENC_DUPLA_H_
#define _LISTA_ENC_DUPLA_H_

typedef struct nodoLista{
   char info;
   struct nodoLista *prox;
} NodoLista;

typedef struct{
   NodoLista *prim;
} Lista;

// Funcao que cria uma lista
Lista* criaLista();

// Funcao que destroi uma lista
void destroiLista(Lista *lista);

// Funcao que insere um nodo no inicio de uma lista
void insereInicioLista(Lista *lista, char info);

#endif
