#ifndef _LISTA_ENC_H_
#define _LISTA_ENC_H_

#define TAM_MAX_NOME 40
#define TAM_MAX_EMAIL 25

typedef struct{
   int matricula;
   char nome[TAM_MAX_NOME];
   char email[TAM_MAX_EMAIL];
} Aluno;

typedef Aluno Info;

typedef struct nodoLEnc{
   Info info;
   struct nodoLEnc *prox;
} NodoLEnc;

typedef struct listaEnc{
   struct nodoLEnc *prim;
   int tamanho;
} ListaEnc;

// Funcao que cria uma lista
#include "lista_enc.c"
ListaEnc* criaLista();

// Funcao que destroi uma lista
void destroiLista(ListaEnc *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeLista(ListaEnc *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioLista(ListaEnc *lista, Info info);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc* buscaInfoLista(ListaEnc* lista, int matricula);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoLista(ListaEnc* lista, int matricula);

// Funcao que dá o tamanho de um lista
int tamanhoLista(ListaEnc *lista);

// Funcao que insere um elemento na lista em ordem decrescente por matrícula
int insereOrdenadoLista(ListaEnc *lista, Info info);

#endif
