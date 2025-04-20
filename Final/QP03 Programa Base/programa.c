#include <stdio.h>
#include <string.h>
#include "abp.c"

int ehCONSOANTE(char letra){
	int i;
   char vogal[6] = {'A', 'E', 'I', 'O', 'U'};
   
   for(i=0; i<6; i++) if(letra == vogal[i]) return 0;
   
   return 1;
}

NodoABP* numConsoantesNodo(NodoABP* nodoAux, int *consoantes){
	if(nodoAux != NULL){
		numConsoantesNodo(nodoAux->esq, consoantes);
		if (ehCONSOANTE(nodoAux->info)) *consoantes++;
		numConsoantesNodo(nodoAux->dir, consoantes);
	}
}

int numConsoantesABP(ABP *arv){
   int consoantes = 0;
   
   numConsoantesNodo(arv->raiz, &consoantes);
   
   return consoantes;
}

int main(){

   ABP *arv;
   arv = criaABP();
       
   insereABP(arv, 'X');
   insereABP(arv, 'E');
   insereABP(arv, 'D');
   insereABP(arv, 'B');
   insereABP(arv, 'I');
   
   return numConsoantesABP(arv);
   
   destroiABP(arv);
}
