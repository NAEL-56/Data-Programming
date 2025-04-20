#include <stdio.h>
#include "lista.c"

void esvaziaLista(Lista *lista){ //funcao destroiLista adaptada para devolver vazia
   NodoLista *aux = lista->prim;
   while(aux != NULL){
       NodoLista *tmp = aux->prox;
       free(aux); 
       aux = tmp;
   }
   //free(lista);
}

Lista* mesclaOrdenadaLista(Lista *lista1, Lista *lista2){
   NodoLista *nodoL1 = lista1->prim;
   NodoLista *nodoL2 = lista2->prim;
   
   Lista *listaRes = criaLista();
   
   while(nodoL1 != NULL || nodoL2 != NULL){
   	
		if(nodoL1->info > nodoL2->info || nodoL2 == NULL){
			insereInicioLista(listaRes, nodoL1->info);
			nodoL1 = nodoL1->prox;
		}
		else{
			insereInicioLista(listaRes, nodoL2->info);
			nodoL2 = nodoL2->prox;
		}		
   }
   
   esvaziaLista(lista1);
   esvaziaLista(lista2);   
   
   return listaRes;
}

int main(){

   NodoLista *nodoL3;

   Lista *lista1 = criaLista();
   Lista *lista2 = criaLista();
   Lista *lista3;
   
   insereInicioLista(lista1, 'G');
   insereInicioLista(lista1, 'E');
   insereInicioLista(lista1, 'D');
   insereInicioLista(lista1, 'A');

   insereInicioLista(lista2, 'Z');
   insereInicioLista(lista2, 'T');
   insereInicioLista(lista2, 'B');
   
   lista3 = mesclaOrdenadaLista(lista1, lista2);
   nodoL3 = lista3->prim;
   
   while(nodoL3 != NULL){
   		printf("%c ", nodoL3->info);
		nodoL3 = nodoL3->prox;   	
   }

   destroiLista(lista1);
   destroiLista(lista2);
   // destroiLista(lista3); // liberar apos implementar mesclaOrdenadaLista

   return 0;
}
