#include "abp.c"

int ehStringValidaNaABP(ABP *arvore, char *string){
	int flag;
	
	for(int i=0; i < strlen(string);i++){
		if(buscaInfoNodoABP(arvore->raiz, string[i], &flag))
	}
}

Info buscaInfoNodoABP(NoArvBinaria *raiz, int info, int *flag){
	NodoABP nodoAux = raiz;
	*flag =0;
	
	while(nodoAux != NULL){
		if (nodoAux == info) *flag = 1;
   else if (raiz->info.matricula > matricula) 
      nodoAux = nodoAux->esq;
   else if (raiz->info.matricula < matricula) 
      nodoAux = nodoAux->dir;
	}
	
      return flag
}
