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
}

// Funcao que imprime uma arvore
void imprimeArvore(ArvBinaria *arv){
   printf("-----------------------------------------\n");
   imprimeNodoArvore(arv->raiz);
   printf("-----------------------------------------\n");
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

// Imprime nodo com tabs
void imprimeNodoIndentado(NoArvBinaria *raiz, int nivel){
	int i;
	if(raiz != NULL){
		// Imprime n tabs
		for(i = 0; i < nivel; i++){
			printf("\t");
		}
		// Imprime a matrícula no nodo
		printf("%d\n", raiz->info.matricula);
		// Imprime a esquerda e a direita
		imprimeNodoIndentado(raiz->esq, nivel + 1);
		imprimeNodoIndentado(raiz->dir, nivel + 1);
	}
}

// Funcao que imprime uma arvore em formato identado
void imprimeIndentadoArvore(ArvBinaria *arv){
	imprimeNodoIndentado(arv->raiz, 0);
	printf("\n");
}

// Funcao que retorna 1 se a árvore é degenerada, 0 se não.
int ehDegeneradaArvore(ArvBinaria *arv){
	// Árvore degenerada é uma em que todos nodos têm um
	// filho só.
	// Árvores vazias ou só com a raiz não são degeneradas.
	if(arv->raiz == NULL){
		// Árvore vazia: não é
		return 0;
	} else if(arv->raiz->esq == NULL && arv->raiz->dir == NULL){
		// Árvore só com a raiz: não é
		return 0;
	}
	int numero_de_filhos = 0;
	int contem_esquerda = 0;
	int contem_direita = 0;
	// Inicializa o ponteiro
	NoArvBinaria *ponteiro = arv->raiz;
	// O ponteiro percorre a árvore até encontrar algum nó
	// com dois filhos. Aí, retorna 0.
	// Se não encontrar nenhum, retorna 1.
	while(ponteiro != NULL){
		if(ponteiro->esq != NULL){
			contem_esquerda = 1; // booleano
		}
		if(ponteiro->dir != NULL){
			contem_direita = 1;
		}
		numero_de_filhos = contem_esquerda + contem_direita;
		if(numero_de_filhos == 2){
			// Não é degenerada
			return 0;
		}
		if(numero_de_filhos == 0){
			// Chegou ao final sem retornar, então é degenerada
			return 1;
		}
		// Se numero_de_filhos é só 1, vai para esse filho
		if(contem_esquerda == 1){
			ponteiro = ponteiro->esq;
		} else if(contem_direita == 1){
			ponteiro = ponteiro->dir;
		}
		// Reseta as variáveis para o próximo loop
		contem_esquerda = 0;
		contem_direita = 0;
		numero_de_filhos = 0;
	}
}
