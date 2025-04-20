#ifndef _ABP_H_
#define _ABP_H_

typedef struct nodo{
   char info;
   struct nodo *esq;
   struct nodo *dir;
} NodoABP;

typedef struct{
   NodoABP *raiz;
} ABP;


// Funcao que cria uma ABP
ABP* criaABP();

// Funcao que insere um elemento na ABP
void insereABP(ABP *arv, char info);

// Funcao que destroi uma ABP
void destroiABP(ABP *arv);

#endif
