// COMENTE SEU CÓDIGO

#include <stdio.h>
#include <string.h>
#include "fila_enc.h"
#include "pilha_enc.h"

int main(){
   PilhaEnc *pilha;
   pilha = criaPilha();

   FilaEnc *fila;
   fila = criaFila();
   
   Info info1 = {1, "Fulano de Tal", "fulano@email.com"};
   Info info2 = {2, "Beltrana de Tal", "beltrana@email.com"};
   Info info3 = {3, "Cicrano de Tal", "cicrano@email.com"};
   Info info4 = {4, "Ciclana de Tal", "ciclana@email.com"};
   Info info5 = {5, "Ciclano de Tal", "ciclano@email.com"};
	
	
   Info infoAux;
	
   empilhaPilha(pilha, info1); 
   empilhaPilha(pilha, info2); 
   empilhaPilha(pilha, info3); 
   empilhaPilha(pilha, info4); 
   empilhaPilha(pilha, info5); 

	invertePilha(pilha);

   while (!vaziaPilha(pilha)){
      infoAux = desempilhaPilha(pilha);
      printf("%d | %s (%s)\n", infoAux.matricula, infoAux.nome, infoAux.email);   
   }

   destroiPilha(pilha);
   /*
   enfileiraFila(fila, info1); 
   enfileiraFila(fila, info2); 
   enfileiraFila(fila, info3); 
   enfileiraFila(fila, info4); 
   enfileiraFila(fila, info5); 

	inverteFila(fila);

   while (!vaziaFila(fila)){
      infoAux = desenfileiraFila(fila);
      printf("%d | %s (%s)\n", infoAux.matricula, infoAux.nome, infoAux.email);   
   }
   
   destroiFila(fila);*/

   return 0;
}
