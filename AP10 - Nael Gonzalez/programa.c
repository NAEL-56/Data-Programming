#include <stdio.h>
#include "grafo_ma.c"

int main(){
   
   int aux;
   GrafoMA *grafo = criaGrafoMA(10); // poderia ser um natural positivo qualquer
   
   // Aqui seriam chamadas as funcoes de inicializacao de infos
   Info info1 = {.matricula = 1, .nome = "Fulano de Tal", .email = "fulano@email.com"};
   Info info2 = {.matricula = 2, .nome = "Beltrana de Tal", .email = "beltrana@email.com"};
   Info info3 = {.matricula = 3, .nome = "Cicrano de Tal", .email = "cicrano@email.com"};
   Info info4 = {.matricula = 4, .nome = "Ciclana de Tal", .email = "ciclana@email.com"};
   Info info5 = {.matricula = 5, .nome = "Ciclano de Tal", .email = "ciclano@email.com"};
      
   aux = insereNodoGrafoMA(grafo, info1); // aux = 1
   aux = insereNodoGrafoMA(grafo, info2); // aux = 1
   aux = insereNodoGrafoMA(grafo, info2); // aux = 0
   aux = insereNodoGrafoMA(grafo, info3); // aux = 1
   aux = insereNodoGrafoMA(grafo, info4); // aux = 1
   aux = insereNodoGrafoMA(grafo, info5); // aux = 1
   
   aux = insereArestaGrafoMA(grafo, 1, 2); // implementar // aux = 1 
   aux = insereArestaGrafoMA(grafo, 2, 1); // implementar // aux = 0
   aux = insereArestaGrafoMA(grafo, 2, 2); // implementar // aux = 0
   aux = insereArestaGrafoMA(grafo, 2, 3); // implementar // aux = 1
   aux = insereArestaGrafoMA(grafo, 3, 5); // implementar // aux = 1
   aux = insereArestaGrafoMA(grafo, 2, 5); // implementar // aux = 1

   aux = removeArestaGrafoMA(grafo, 4, 1); // implementar // aux = 0
   aux = removeArestaGrafoMA(grafo, 5, 2); // implementar // aux = 1
   
   imprimeGrafoMA(grafo); // implementar
   /* Deve imprimir algo como:
   "Vertices:
    1 | Fulano de Tal (fulano@email.com)
    2 | Beltrana de Tal (beltrana@email.com)
    3 | Cicrano de Tal (cicrano@email.com)
    4 | Ciclana de Tal (ciclana@email.com)
    5 | Ciclano de Tal (ciclano@email.com)
    Arestas:
    {Beltrana de Tal, Fulano de Tal}
    {Cicrano de Tal, Beltrana de Tal}
    {Ciclano de Tal, Cicrano de Tal}"
   */
 
	printf("\n\n Tamanho: %d, Ordem: %d, Menor Grau: %d, Maior Grau: %d\n\n", tamanhoGrafoMA(grafo), ordemGrafoMA(grafo), menorGrauGrafoMA(grafo), maiorGrauGrafoMA(grafo));
 
   destroiGrafoMA(grafo);

   return 0;
}
