#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

// Prototipos
int alturaNodoAVL(NoArvAVL *raiz);
int fatorBalanceamentoNodoAVL(NoArvAVL *raiz);
NoArvAVL* rotacaoEsquerdaAVL(NoArvAVL *raiz);
NoArvAVL* rotacaoDireitaAVL(NoArvAVL *raiz);
NoArvAVL* rotacaoDireitaEsquerdaAVL(NoArvAVL *raiz);
NoArvAVL* rotacaoEsquerdaDireitaAVL(NoArvAVL *raiz);

// Funcao que cria uma AVL
AVL* criaAVL(){
   AVL * arv = (AVL*)malloc(sizeof(AVL));
   arv->raiz = NULL;
   return arv;
}

// Funcao auxiliar para imprimir uma AVL
void imprimeNodoAVL(NoArvAVL *raiz){
   if(raiz != NULL){
      imprimeNodoAVL(raiz->esq);
      printf("%d | %s (%s)\n", raiz->info.matricula,
                               raiz->info.nome,
                               raiz->info.email);
      imprimeNodoAVL(raiz->dir);
   }   
}

// Funcao que imprime uma AVL
void imprimeAVL(AVL *arv){
   printf("-----------------------------------------\n");
   imprimeNodoAVL(arv->raiz);
   printf("-----------------------------------------\n");
}

// Funcao que retorna a altura de um nodo
int alturaNodoAVL(NoArvAVL *raiz){
   if(raiz->esq != NULL && raiz->dir != NULL){
      if(raiz->esq->alt < raiz->dir->alt)
         return raiz->dir->alt + 1;
      else
         return raiz->esq->alt + 1;
   }
   else if(raiz->esq != NULL)
      return raiz->esq->alt + 1;
   else if(raiz->dir != NULL)
      return raiz->dir->alt + 1;
   else
      return 1; 
}

// Funcao que retorna o fator de balanceamento de um nodo
int fatorBalanceamentoNodoAVL(NoArvAVL *raiz){
   if(raiz == NULL)
      return 0;
   if(raiz->esq != NULL && raiz->dir != NULL)
      return raiz->esq->alt - raiz->dir->alt;
   else if(raiz->esq != NULL)
      return raiz->esq->alt;
   else if(raiz->dir != NULL)
      return -raiz->dir->alt;
   return 0;
}

// Funcao que insere um elemento na AVL
NoArvAVL* insereNodoAVL(NoArvAVL *raiz, Info info){
   if(raiz == NULL){
      raiz = (NoArvAVL*)malloc(sizeof(NoArvAVL));
      raiz->info = info;
      raiz->alt = 1;
      raiz->esq = NULL;
      raiz->dir = NULL;
      return raiz;
   }
   else if(info.matricula < raiz->info.matricula)
      raiz->esq = insereNodoAVL(raiz->esq, info); 
   else if(info.matricula > raiz->info.matricula)
      raiz->dir = insereNodoAVL(raiz->dir, info); 
   
   raiz->alt = alturaNodoAVL(raiz);
   int FB = fatorBalanceamentoNodoAVL(raiz);
   int FBEsq = fatorBalanceamentoNodoAVL(raiz->esq);
   int FBDir = fatorBalanceamentoNodoAVL(raiz->dir);
      
   if (FB == 2 && FBEsq == 1){
      raiz = rotacaoDireitaAVL(raiz);
   }

   else if (FB == -2 && FBDir == -1){
      raiz = rotacaoEsquerdaAVL(raiz);
   }

   else if (FB == -2 && FBDir == 1){
      raiz = rotacaoDireitaEsquerdaAVL(raiz);
   }
   
   else if (FB == 2 && FBEsq == -1){
      raiz = rotacaoEsquerdaDireitaAVL(raiz);
   }   
   
   return raiz;
}

// Funcao que insere um elemento na AVL
void insereAVL(AVL *arv, Info info){
   arv->raiz = insereNodoAVL(arv->raiz, info);
}


// Funcao auxiliar para buscar uma informacao na AVL
Info buscaInfoNodoAVL(NoArvAVL *raiz, int matricula){
   if (raiz == NULL){
      Info infoAux = {-1, "", ""}; // matricula, nome, email
      return infoAux;
   }else if (raiz->info.matricula > matricula) 
      return buscaInfoNodoAVL(raiz->esq, matricula);
   else if (raiz->info.matricula < matricula) 
      return buscaInfoNodoAVL(raiz->dir, matricula);
   else
      return raiz->info;
}

// Funcao que busca uma informacao na AVL
Info buscaInfoAVL(AVL *arv, int matricula){
   return buscaInfoNodoAVL(arv->raiz, matricula);
}

// Funcao auxiliar para destroir uma AVL
void destroiNodoAVL(NoArvAVL *raiz){
   if(raiz != NULL){
      destroiNodoAVL(raiz->esq);
      destroiNodoAVL(raiz->dir);
      free(raiz);
   }
}

// Funcao que destroi uma AVL
void destroiAVL(AVL *arv){
   destroiNodoAVL(arv->raiz);
   free(arv);
}

// Rotacoes
// Rotacao simples a esquerda
NoArvAVL * rotacaoEsquerdaAVL(NoArvAVL *raiz){
   NoArvAVL *tmp1;
   NoArvAVL *tmp2;
   
   tmp1 = raiz;
   tmp2 = tmp1->dir;
   
   tmp1->dir = tmp2->esq;
   tmp2->esq = tmp1;

   tmp1->alt = alturaNodoAVL(tmp1);
   tmp2->alt = alturaNodoAVL(tmp2);
   
   return tmp2;
}

// Rotacao simples a direita 
NoArvAVL * rotacaoDireitaAVL(NoArvAVL *raiz){
   NoArvAVL *tmp1;
   NoArvAVL *tmp2;
   
   tmp1 = raiz;
   tmp2 = tmp1->esq;
   
   tmp1->esq = tmp2->dir;
   tmp2->dir = tmp1;
   
   tmp1->alt = alturaNodoAVL(tmp1);
   tmp2->alt = alturaNodoAVL(tmp2);

  return tmp2;
}

// Rotacao esquerda-direita
NoArvAVL * rotacaoEsquerdaDireitaAVL(NoArvAVL *raiz){
   NoArvAVL *tmp1;
   NoArvAVL *tmp2;
   NoArvAVL *tmp3;
   
   tmp1 = raiz;
   tmp2 = tmp1->esq;
   tmp3 = tmp1->esq->dir;
   
   tmp1->esq = tmp3->dir;
   tmp2->dir = tmp3->esq;
   tmp3->dir = tmp1;
   tmp3->esq = tmp2;

   tmp1->alt = alturaNodoAVL(tmp1);
   tmp2->alt = alturaNodoAVL(tmp2);
   tmp3->alt = alturaNodoAVL(tmp3);
   
   return tmp3;
}

// Rotacao direita-esquerda
NoArvAVL * rotacaoDireitaEsquerdaAVL(NoArvAVL *raiz){
   NoArvAVL *tmp1;
   NoArvAVL *tmp2;
   NoArvAVL *tmp3;
   
   tmp1 = raiz;
   tmp2 = tmp1->dir;
   tmp3 = tmp1->dir->esq;
   
   tmp1->dir = tmp3->esq;
   tmp2->esq = tmp3->dir;
   tmp3->esq = tmp1;
   tmp3->dir = tmp2;

   tmp1->alt = alturaNodoAVL(tmp1);
   tmp2->alt = alturaNodoAVL(tmp2);
   tmp3->alt = alturaNodoAVL(tmp3);
      
   return tmp3;
}

void imprimeNodoArvoreIndentado(NoArvAVL *raiz, int tabs){
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

void imprimeIndentadoArvore(AVL *arv){
   printf("-----------------------------------------\n");
   imprimeNodoArvoreIndentado(arv->raiz, 0);
   printf("\n-----------------------------------------\n");
}

int tamanhoNodoAVL(NoArvAVL *inicio){
	if (inicio == NULL) return 0;
	int tamanho = 1; //nodo inicial recebido
	if(inicio->esq != NULL) tamanho += tamanhoNodoAVL(inicio->esq);
	if(inicio->dir != NULL) tamanho += tamanhoNodoAVL(inicio->dir);
	return tamanho;
}

int tamanhoAVL(AVL *arv){
	return tamanhoNodoAVL(arv->raiz);
}


NoArvAVL* removeInfoNodoAVL(NoArvAVL *raiz, int matricula, int* flag){
	if (raiz == NULL)
      return 0;
   else if (raiz->info.matricula > matricula)
      raiz->esq = removeInfoNodoAVL(raiz->esq, matricula, flag);
   else if (raiz->info.matricula < matricula)
      raiz->dir = removeInfoNodoAVL(raiz->dir, matricula, flag);
   else{
   		
      if (raiz->esq == NULL && raiz->dir == NULL){
         free(raiz);
         raiz = NULL;
      }else if (raiz->esq == NULL){
         NoArvAVL *tmp = raiz;
         raiz = raiz->dir; 
         free(tmp);
      }else if (raiz->dir == NULL){
         NoArvAVL *tmp = raiz;
         raiz = raiz->esq; 
         free(tmp);
      }else{
	         NoArvAVL *tmp = raiz->esq;
	         while(tmp->dir != NULL)
	            tmp = tmp->dir;
	         raiz->info = tmp->info;
	         tmp->info.matricula = matricula;
	         raiz->esq = removeInfoNodoAVL(raiz->esq, matricula, flag);
		}
		
		*flag = 1; // apagamos a matricula
	}
		
  raiz->alt = alturaNodoAVL(raiz);
   int FB = fatorBalanceamentoNodoAVL(raiz);
   int FBEsq = fatorBalanceamentoNodoAVL(raiz->esq);
   int FBDir = fatorBalanceamentoNodoAVL(raiz->dir);
      
   if (FB > 0){
   		if(FBEsq == 1 || FBEsq == 0)
      		raiz = rotacaoDireitaAVL(raiz);
   }

   else if (FB < 0){
   		if(FBDir == -1 || FBDir == 0)
      		raiz = rotacaoEsquerdaAVL(raiz);
   }

   else if (FB > 0 && FBEsq == -1){
      raiz = rotacaoEsquerdaDireitaAVL(raiz);
   }
   
   else if (FB < 0 && FBDir == 1){
      raiz = rotacaoDireitaEsquerdaAVL(raiz);
   }
	
   return raiz;
}

int removeInfoAVL(AVL *arv, int matricula){
	int flag=0;
	arv->raiz = removeInfoNodoAVL(arv->raiz, matricula, &flag);
	return flag;
}
