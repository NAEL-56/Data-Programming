#ifndef _LISTA_ENC_DUPLA_H_
#define _LISTA_ENC_DUPLA_H_

#define TAM_MAX_NOME 40
#define TAM_MAX_EMAIL 25

typedef struct{
   int matricula;
   char nome[TAM_MAX_NOME];
   char email[TAM_MAX_EMAIL];
} Aluno;

typedef Aluno Info;

typedef struct nodoLEnc2{
   Info info;
   struct nodoLEnc2 *ant;
   struct nodoLEnc2 *prox;
} NodoLEnc2;

typedef struct ListaEnc2{
   struct nodoLEnc2 *prim;
} ListaEnc2;

// Funcao que cria uma lista
ListaEnc2* criaLista();

// Funcao que destroi uma lista
void destroiLista(ListaEnc2 *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeLista(ListaEnc2 *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioLista(ListaEnc2 *lista, Info info);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoLista(ListaEnc2* lista, int matricula);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoLista(ListaEnc2* lista, int matricula);

// Funcao que insere um nodo em um posi��o espec�fica
int inserePosicaoLista(ListaEnc2 *lista, int posicao, Info info);

// Funcao que imprime uma lista em ordem contr�ria
void imprimeInversoLista(ListaEnc2 *lista);

// Funcao que cria e devolve a c�pia de uma lista dada
ListaEnc2* copiaLista(ListaEnc2 *lista);

// Funcao que insere um elemento na lista em ordem decrescente de matr�cula
int insereOrdenadoLista(ListaEnc2 *lista, Info info);

#endif
