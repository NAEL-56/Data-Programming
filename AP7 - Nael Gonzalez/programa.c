#include <stdio.h>
#include "arvore_binaria.h"
#include <time.h>
#include <stdlib.h>

int main(){
   srand(1634041364); // Para reproduzir exemplo
   //srand(time(NULL)); // Para valores aleatorios

   // Aqui seriam chamadas as funcoes de inicializacao de infos
   Info info1 = {.matricula = 1, .nome = "Fulano de Tal", .email = "fulano@email.com"};
   Info info2 = {.matricula = 2, .nome = "Beltrana de Tal", .email = "beltrana@email.com"};
   Info info3 = {.matricula = 3, .nome = "Cicrano de Tal", .email = "cicrano@email.com"};
   Info info4 = {.matricula = 4, .nome = "Ciclana de Tal", .email = "ciclana@email.com"};
   Info info5 = {.matricula = 5, .nome = "Ciclano de Tal", .email = "ciclano@email.com"};
   
   ArvBinaria *arv;
   arv = criaArvore();
   
   insereArvore(arv, info4);
   insereArvore(arv, info5);
   insereArvore(arv, info2);
   
   insereArvore(arv, info3);
   insereArvore(arv, info1);
   
   Info infoAux = buscaInfoArvore(arv, 4); // infoAux.matricula = 4
   infoAux = buscaInfoArvore(arv, 8); // infoAux.matricula = -1
   
   removeInfoArvore(arv, 2); // matricula = 2 eh nodo de derivacao
   removeInfoArvore(arv, 5); // matricula = 2 eh nodo folha

   imprimeIndentadoArvore(arv);
   
   printf("\n %d \n", ehDegeneradaArvore(arv));
   
   destroiArvore(arv);
   return 0;
}
