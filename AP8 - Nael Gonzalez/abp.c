#include "abp.h"
#include <stdlib.h>
#include <stdio.h>

// Funcao que cria uma ABP
ABP* criaABP(){
   ABP * arv = (ABP*)malloc(sizeof(ABP));
   arv->raiz = NULL;
   return arv;
}

// Funcao auxiliar para imprimir uma ABP
void imprimeNodoABP(NoArvBinaria *raiz){
   if(raiz != NULL){
      imprimeNodoABP(raiz->esq);
      printf("%d | %s (%s)\n", raiz->info.matricula,
                               raiz->info.nome,
                               raiz->info.email);
      imprimeNodoABP(raiz->dir);
   }   
}

// Funcao que imprime uma ABP
void imprimeABP(ABP *arv){
   printf("-----------------------------------------\n");
   imprimeNodoABP(arv->raiz);
   printf("-----------------------------------------\n");
}

// Funcao que auxiliar para inserir um elemento na ABP
NoArvBinaria* insereNodoABP(NoArvBinaria *raiz, Info info){
   if(raiz == NULL){
      raiz = (NoArvBinaria*)malloc(sizeof(NoArvBinaria));
      raiz->info = info;
      raiz->esq = NULL;
      raiz->dir = NULL;
   }
   else if(info.matricula < raiz->info.matricula) 
      raiz->esq = insereNodoABP(raiz->esq, info); 
   else 
      raiz->dir = insereNodoABP(raiz->dir, info); 
   return raiz;
}

// Funcao que insere um elemento na ABP
void insereABP(ABP *arv, Info info){
   arv->raiz = insereNodoABP(arv->raiz, info);
}

// Funcao auxiliar para buscar uma informacao na ABP
Info buscaInfoNodoABP(NoArvBinaria *raiz, int matricula){
   if (raiz == NULL){
      Info infoAux = {-1, "", ""}; // matricula, nome, email
      return infoAux;
   }else if (raiz->info.matricula > matricula) 
      return buscaInfoNodoABP(raiz->esq, matricula);
   else if (raiz->info.matricula < matricula) 
      return buscaInfoNodoABP(raiz->dir, matricula);
   else
      return raiz->info;
}

// Funcao que busca uma informacao na ABP
Info buscaInfoABP(ABP *arv, int matricula){
   return buscaInfoNodoABP(arv->raiz, matricula);
}

// Funcao auxiliar para remover uma informacao da ABP
NoArvBinaria* removeInfoNodoABP(NoArvBinaria *raiz, int matricula){
   if (raiz == NULL)
      return NULL;
   else if (raiz->info.matricula > matricula)
      raiz->esq = removeInfoNodoABP(raiz->esq, matricula);
   else if (raiz->info.matricula < matricula)
      raiz->dir = removeInfoNodoABP(raiz->dir, matricula);
   else{
      if (raiz->esq == NULL && raiz->dir == NULL){
         free(raiz);
         raiz = NULL;
      }else if (raiz->esq == NULL){
         NoArvBinaria *tmp = raiz;
         raiz = raiz->dir; 
         free(tmp);
      }else if (raiz->dir == NULL){
         NoArvBinaria *tmp = raiz;
         raiz = raiz->esq; 
         free(tmp);
      }else{
         NoArvBinaria *tmp = raiz->esq;
         while(tmp->dir != NULL)
            tmp = tmp->dir;
         raiz->info = tmp->info;
         tmp->info.matricula = matricula;
         raiz->esq = removeInfoNodoABP(raiz->esq, matricula);
      }
   }
   return raiz;
}

// Funcao que remove uma informacao da ABP
void removeInfoABP(ABP *arv, int matricula){
   arv->raiz = removeInfoNodoABP(arv->raiz, matricula);
}

// Funcao auxiliar para destroir uma ABP
void destroiNodoABP(NoArvBinaria *raiz){
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

void imprimeNodoParentesis(NoArvBinaria *raiz){
	printf("%d(", raiz->info.matricula);
	/*if(raiz->esq == NULL && raiz->dir == NULL){
		printf("()");
	}
	else{*/
		printf("(");
		if(raiz->esq != NULL){
		imprimeNodoParentesis(raiz->esq);
		}
		printf(")(");
		if(raiz->dir != NULL){
		imprimeNodoParentesis(raiz->dir);
		}
		printf(")");
		
	//}
	//printf(")");
}


void imprimeABPParentesesAninhados(ABP *arv){
	printf("(");
	imprimeNodoParentesis(arv->raiz);
	printf(")");
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

void imprimeIndentadoArvore(ABP *arv){
   printf("-----------------------------------------\n");
   imprimeNodoArvoreIndentado(arv->raiz, 0);
   printf("\n-----------------------------------------\n");
}

int minimoABP(ABP *arv){
	if(arv->raiz == NULL) return -1;
	
	NoArvBinaria *nodo = arv->raiz;
	
	while(nodo->esq != NULL){
		nodo = nodo->esq;
	}
	return nodo->info.matricula;
}

int nodoMaximo(NoArvBinaria *nodo, int ant){ //comentarios supoem arvore qualquer (não necessariamente ABP)
	/*if(nodo->esq != NULL){
		if(nodo->esq->info.matricula > ant) ant = nodo->esq->info.matricula;
		ant = nodoMaximo(nodo->esq, ant);
	}*/
	if(nodo->dir != NULL){
		/*if(nodo->dir->info.matricula > ant)*/ ant = nodo->dir->info.matricula;
		ant = nodoMaximo(nodo->dir, ant);
	}
	return ant;
}

int maximoABP(ABP *arv){
	if(arv->raiz == NULL) return -1;
	return nodoMaximo(arv->raiz, arv->raiz->info.matricula);
}
