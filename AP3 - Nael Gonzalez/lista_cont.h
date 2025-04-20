#ifndef _LISTA_CONT_H_
#define _LISTA_CONT_H_

#define TAM_MAX_NOME 40
#define TAM_MAX_EMAIL 25

#define TAM_MAX_LISTA 5

typedef struct{
   int matricula;
   char nome[TAM_MAX_NOME];
   char email[TAM_MAX_EMAIL];
} NodoLCont;

typedef struct{
   int ini;
   int fim;
   NodoLCont nodos[TAM_MAX_LISTA];
} ListaCont;

// Funcao que cria uma lista
void criaLista(ListaCont *lista);

// Funcao que destroi uma lista
void destroiLista(ListaCont *lista);

// Funcao que insere um nodo em uma posicao de uma lista
int insereLista(ListaCont *lista, NodoLCont nodo, int pos);

// Funcao que remove um nodo em uma posicao de uma lista
int removeLista(ListaCont *lista, int pos);

// Funcao que retorna a cardinalidade de uma lista
int tamanhoLista(ListaCont lista);

// Funcao que resgata um nodo de uma posicao de uma lista
NodoLCont buscaLista(ListaCont lista, int pos);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLCont buscaInfoLista(ListaCont lista, int matricula);

// Funcao que imprime todos os nodos de uma lista
void imprimeLista(ListaCont lista);

// função que une duas listas em sequência, retornando 1 se bem sucedida e 0 c.c.
int concatenaLista(ListaCont *listaA, ListaCont listaB);

// função que tenta inserir uma nova matrícula à lista, retornando 1 se bem-sucedida, e 0 caso aquela matrícula já esteja na lista
int insereUnicoLista(ListaCont *lista, NodoLCont nodo, int pos);

//função que insere em ordem de matricula
//int insereOrdenadoLista(ListaCont *lista, NodoLCont nodo);
#endif
