#include "arvore_binaria.h"
#include <stdlib.h>
#include <stdio.h>

// Funcao que cria uma arvore
ArvBinaria* criaArvore(){
   ArvBinaria * arv = (ArvBinaria*)malloc(sizeof(ArvBinaria));
   arv->raiz = NULL;
   return arv;
}

// Funcao auxiliar para imprimir uma arvore
void imprimeNodoArvore(NoArvBinaria *raiz){
   if(raiz != NULL){
      printf("%d | %s (%s)\n", raiz->info.matricula,
                               raiz->info.nome,
                               raiz->info.email);
      imprimeNodoArvore(raiz->esq);
      imprimeNodoArvore(raiz->dir);
   }
   else printf("NULL\n");
}

// Funcao que imprime uma arvore
void imprimeArvore(ArvBinaria *arv){
   printf("-----------------------------------------\n");
   imprimeNodoArvore(arv->raiz);
   printf("\n-----------------------------------------\n");
}

// Funcao que auxiliar para inserir um elemento na arvore
NoArvBinaria* insereNodoArvore(NoArvBinaria *raiz, Info info){
   if(raiz == NULL){
      NoArvBinaria *raiz = (NoArvBinaria*)malloc(sizeof(NoArvBinaria));
      raiz->info = info;
      raiz->esq = NULL;
      raiz->dir = NULL;
      return raiz;
   }
   else if(rand()%2) // Escolha arbitraria (?)
      raiz->esq = insereNodoArvore(raiz->esq, info); 
   else 
      raiz->dir = insereNodoArvore(raiz->dir, info); 
   return raiz;
}

// Funcao que insere um elemento na arvore
void insereArvore(ArvBinaria *arv, Info info){
   arv->raiz = insereNodoArvore(arv->raiz, info);
}

// Funcao auxiliar para buscar uma informacao na arvore
Info buscaInfoNodoArvore(NoArvBinaria *raiz, int matricula){
   if (raiz == NULL){
      Info infoAux = {.matricula = -1, .nome = "", .email = ""};
      return infoAux;
   }else if (raiz->info.matricula == matricula) 
      return raiz->info;
   else{
      Info infoAux = buscaInfoNodoArvore(raiz->esq, matricula);
      if (infoAux.matricula != -1)
        return infoAux;
      else 
        return buscaInfoNodoArvore(raiz->dir, matricula);
   }
}

// Funcao que busca uma informacao na arvore
Info buscaInfoArvore(ArvBinaria *arv, int matricula){
   return buscaInfoNodoArvore(arv->raiz, matricula);
}

// Funcao auxiliar para remover uma informacao da arvore
NoArvBinaria* removeInfoNodoArvore(NoArvBinaria *raiz, int matricula){
   if (raiz == NULL)
      return NULL;
   else if (raiz->info.matricula == matricula){
      if (raiz->esq == NULL && raiz->dir == NULL){
         free(raiz);
         return NULL;
      }
      else
         return raiz;
   }
   else{
      raiz->esq = removeInfoNodoArvore(raiz->esq, matricula);
      raiz->dir = removeInfoNodoArvore(raiz->dir, matricula);
   }
   return raiz;
}

// Funcao que remove uma informacao da arvore
void removeInfoArvore(ArvBinaria *arv, int matricula){
   arv->raiz = removeInfoNodoArvore(arv->raiz, matricula);
}

// Funcao auxiliar para destroir uma arvore
void destroiNodoArvore(NoArvBinaria *raiz){
   if(raiz != NULL){
      destroiNodoArvore(raiz->esq);
      destroiNodoArvore(raiz->dir);
      free(raiz);
   }
}

// Funcao que destroi uma arvore
void destroiArvore(ArvBinaria *arv){
   destroiNodoArvore(arv->raiz);
   free(arv);
}

void imprimeNodoArvoreIndentado(NoArvBinaria *raiz, int tabs){
	int i;
   for(i=0; i<tabs; i++) printf("\t");
   if(raiz != NULL){
      
      printf("%d | %s (%s)\n", raiz->info.matricula,
                               raiz->info.nome,
                               raiz->info.email);
      
      imprimeNodoArvoreIndentado(raiz->esq, tabs+1);
      imprimeNodoArvoreIndentado(raiz->dir, tabs+1);
   }
   else printf("NULL\n");
}

void imprimeIndentadoArvore(ArvBinaria *arv){
   printf("-----------------------------------------\n");
   imprimeNodoArvoreIndentado(arv->raiz, 0);
   printf("\n-----------------------------------------\n");
}

int ehDegeneradaArvore(ArvBinaria *arv){
	NoArvBinaria *nodoAux = arv->raiz;
	
	if(arv->raiz == NULL) return 0;
	if(arv->raiz->esq == NULL && arv->raiz->dir) return 0;
	while(nodoAux != NULL){
		if(nodoAux->esq != NULL && nodoAux->dir != NULL) return 0;
		if(nodoAux->esq != NULL) nodoAux = nodoAux->esq;
		else	if(nodoAux->dir != NULL) nodoAux = nodoAux->dir;
				else return 1;
	}
}
