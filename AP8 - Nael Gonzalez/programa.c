#include <stdio.h>
#include "abp.c"

int main(){

   // Aqui seriam chamadas as funcoes de inicializacao de infos
   Info info1 = {.matricula = 1, .nome = "Fulano de Tal", .email = "fulano@email.com"};
   Info info2 = {.matricula = 2, .nome = "Beltrana de Tal", .email = "beltrana@email.com"};
   Info info3 = {.matricula = 3, .nome = "Cicrano de Tal", .email = "cicrano@email.com"};
   Info info4 = {.matricula = 4, .nome = "Ciclana de Tal", .email = "ciclana@email.com"};
   Info info5 = {.matricula = 5, .nome = "Ciclano de Tal", .email = "ciclano@email.com"};
   
   ABP *arv;
   arv = criaABP();
   
   insereABP(arv, info3);
   insereABP(arv, info5);
   insereABP(arv, info2);
   
   insereABP(arv, info4);
   insereABP(arv, info1);
   
   Info infoAux = buscaInfoABP(arv, 4); // infoAux.matricula = 4
   infoAux = buscaInfoABP(arv, 8); // infoAux.matricula = -1
   
   removeInfoABP(arv, 2); // matricula = 2 eh derivacao
   removeInfoABP(arv, 3); // matricula = 2 eh a raiz
   removeInfoABP(arv, 8); // matricula = 2 nao existe
   
   imprimeABP(arv);
   
   imprimeIndentadoArvore(arv);
   
   imprimeABPParentesesAninhados(arv);
   
   printf("\n\nMax: %d", maximoABP(arv));
   printf("\n\nMin: %d", minimoABP(arv));
   
   destroiABP(arv);
   return 0;
}
