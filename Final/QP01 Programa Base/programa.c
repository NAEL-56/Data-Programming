#include <stdio.h>
#include <string.h>
#include "lista2.c"

void imprimeAlternadoLista2(Lista2 *lista){
	NodoLista2* inicial = lista->prim;
	
   NodoLista2* final = lista->prim;
   while(final->prox != NULL) final = final->prox;
   
   while(1){   	
	   if(inicial != final){   	
			printf("%d ", inicial->info);
			inicial = inicial->prox;
	   }

   		printf("%d ", final->info);
   		if(inicial != final){
   			final = final->ant;
		}
		else break;
	}
}


int main(){
   int i;
   Lista2 *lista;
   lista = criaLista2();
   
   insereInicioLista2(lista, 5); // deveria tratar retorno
   insereInicioLista2(lista, 4); // deveria tratar retorno
   insereInicioLista2(lista, 3); // deveria tratar retorno
   insereInicioLista2(lista, 2); // deveria tratar retorno
   insereInicioLista2(lista, 1); // deveria tratar retorno
   
   imprimeAlternadoLista2(lista);
   
   destroiLista2(lista);

   return 0;
}
