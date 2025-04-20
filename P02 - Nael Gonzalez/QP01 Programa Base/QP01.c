#include "abp.h"
#include "lista.h"
#include <stdlib.h>

Lista* ordenaComABPLista(Lista *lista){
	NodoLista nodoListaAux;
	nodoListaAux = lista->prim;
	
	ABP *arvoreAux = criaABP();
	Lista *novaLista= criaLista();
	
	while(nodoListaAux!=NULL){
		insereABP(arvoreAux, nodoListaAux->info);
		nodoListaAux = nodoListaAux->prox;
	}
	
	enlistaABP(arvoreAux->raiz, novaLista);
	
	//imprimeIndentadoArvore(arvoreAux);
	
	nodoListaAux = novaLista->prim;
	while(nodoListaAux != NULL){
		printf("%c", nodoListaAux->info);
		nodoListaAux = nodoListaAux->prox;
	}
	
	destroiABP(arvoreAux);
	
	return novaLista;
}

void enlistaABP(NodoABP *nodoArvoreAux, Lista *novaLista){
	
	if(nodoArvoreAux->dir != NULL) enlistaABP(nodoArvoreAux->dir, novaLista);
	insereInicioLista(novaLista, nodoArvoreAux->info);
	if(nodoArvoreAux->esq != NULL) enlistaABP(nodoArvoreAux->esq, novaLista);
}

/*void imprimeNodoArvoreIndentado(NodoABP *raiz, int tabs){
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
}*/
