#include <stdio.h>
#include "abp.c"
#include "lista.c"
#include "QP01.c"

Lista* ordenaComABPLista(Lista *lista){
   // Implementar QP01!
   // Enviar apenas a implementacao dessa funcao.
   return lista;
}

int main(){

   char nodo;
   int opcao;
   int retorno;

   Lista *lista;
   lista = criaLista();
   
   insereInicioLista(lista, 'J');
   insereInicioLista(lista, 'E');
   insereInicioLista(lista, 'B');
   insereInicioLista(lista, 'I');
   insereInicioLista(lista, 'O');
      
   lista = ordenaComABPLista(lista);

   destroiLista(lista);

   return 0;
}
