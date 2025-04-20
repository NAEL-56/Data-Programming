#include "lista_cont.c"
#include <stdio.h>
#include <string.h>

int main(){

   int retorno;
   ListaCont listaA, listaB;
   criaLista(&listaA);
   criaLista(&listaB);
   
   NodoLCont nodoAux;
   // Aqui seriam chamadas as funcoes de inicializacao de nodos
   NodoLCont nodo1 = {1, "Fulano de Tal", "fulano@email.com"};
   NodoLCont nodo2 = {2, "Beltrana de Tal", "beltrana@email.com"};
   NodoLCont nodo3 = {3, "Cicrano de Tal", "cicrano@email.com"};
   NodoLCont nodo4 = {4, "Ciclana de Tal", "ciclana@email.com"};
   NodoLCont nodo5 = {3, "Ciclano de Tal", "ciclano@email.com"}; //matricula igual nao sera concatenada
  
   retorno = insereLista(&listaA, nodo1, 0);
   retorno = insereLista(&listaA, nodo2, 1);
   
   retorno = insereLista(&listaB, nodo3, 0);
   retorno = insereLista(&listaB, nodo4, 1);
   retorno = insereUnicoLista(&listaB, nodo5, 0);
   //retorno = insereLista(&listaA, nodo5, 2); // retorno = 1
   
   nodoAux = buscaLista(listaA, 2); // nodoAux = nodo5   
   nodoAux = buscaInfoLista(listaA, 5); // nodoAux = nodo5
   
   //imprimeLista(listaA);

   //retorno = tamanhoLista(listaA); // retorno = 4
   
   retorno = concatenaLista(&listaA, listaB);
      
   retorno = removeLista(&listaB, 0); // retorno = 1
   //retorno = removeLista(&lista, 4); // retorno = 0
   
   imprimeLista(listaA);
   destroiLista(&listaA);

   //retorno = insereLista(&lista, nodo4, 0); // retorno = 1*/
   //imprimeLista(lista);
      
   return 0;
}

