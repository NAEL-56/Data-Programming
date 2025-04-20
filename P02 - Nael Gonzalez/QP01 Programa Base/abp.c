#include "abp.h"
#include <stdlib.h>

// Funcao que cria uma ABP
ABP* criaABP(){
   ABP * arv = (ABP*)malloc(sizeof(ABP));
   arv->raiz = NULL;
   return arv;
}

// Funcao auxiliar para destroir uma ABP
void destroiNodoABP(NodoABP *raiz){
   if(raiz != NULL){
      destroiNodoABP(raiz->esq);
      destroiNodoABP(raiz->dir);
      free(raiz);
   }
}

// Funcao que destroi uma ABP
void destroiABP(ABP *arv){
   destroiNodoABP(arv->raiz);
   free(arv);
}

// Funcao que auxiliar para inserir um elemento na ABP
NodoABP* insereNodoABP(NodoABP *raiz, char info){
   if(raiz == NULL){
      raiz = (NodoABP*)malloc(sizeof(NodoABP));
      raiz->info = info;
      raiz->esq = NULL;
      raiz->dir = NULL;
   }
   else if(info < raiz->info) 
      raiz->esq = insereNodoABP(raiz->esq, info); 
   else 
      raiz->dir = insereNodoABP(raiz->dir, info); 
   return raiz;
}

// Funcao que insere um elemento na ABP
void insereABP(ABP *arv, char info){
   arv->raiz = insereNodoABP(arv->raiz, info);
}
