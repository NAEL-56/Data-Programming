#include <stdio.h>
#include "avl.c"

int main(){

   // Aqui seriam chamadas as funcoes de inicializacao de infos
   Info info1 = {.matricula = 1, .nome = "Fulano de Tal", .email = "fulano@email.com"};
   Info info2 = {.matricula = 2, .nome = "Beltrana de Tal", .email = "beltrana@email.com"};
   Info info3 = {.matricula = 3, .nome = "Cicrano de Tal", .email = "cicrano@email.com"};
   Info info4 = {.matricula = 4, .nome = "Ciclana de Tal", .email = "ciclana@email.com"};
   
   AVL *arv;
   arv = criaAVL();
   
   insereAVL(arv, info1);
   insereAVL(arv, info2);
   insereAVL(arv, info3);
   
   insereAVL(arv, info4);
   
   imprimeAVL(arv);
   
   imprimeIndentadoArvore(arv);
   
   printf("\n Remocao: %d \n", removeInfoAVL(arv, 3)); // pensar em como implementar...
   
   printf("\n %d Nodos \n", tamanhoAVL(arv));
   
   destroiAVL(arv);
   return 0;
}
