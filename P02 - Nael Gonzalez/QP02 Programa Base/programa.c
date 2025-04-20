#include <stdio.h>
#include <string.h>
#include "abp.c"

/*int ehStringValidaNaABP(ABP *arv, char *string){
   // Implementar QP02!
   // Enviar apenas a implementacao dessa funcao.
   return 0;
}*/

int main(){

   ABP *arv;
   arv = criaABP();
       
   insereABP(arv, 'X');
   insereABP(arv, 'Z');
   insereABP(arv, 'C');
   insereABP(arv, 'R');
   insereABP(arv, 'S');
   insereABP(arv, 'A');
   insereABP(arv, 'O');
   insereABP(arv, 'E');
   insereABP(arv, 'D');
   insereABP(arv, 'B');
   insereABP(arv, 'I');
   
   char string[] = {"SUFIXO"};
   printf("Resultado: %d\n", ehStringValidaNaABP(arv, string));
 
   destroiABP(arv);
   return 0;
}
