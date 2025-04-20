#include <stdio.h>
#include "grafo_la.c"

int main(){
 
   GrafoLA * grafo = criaGrafoLA(6);
   
   Disciplina disc0 = {0, 60, "Introducao a Programacao"};
   Disciplina disc1 = {1, 60, "Programacao Orientada a Objetos"};
   Disciplina disc2 = {2, 60, "Estruturas de Dados I"};
   Disciplina disc3 = {3, 90, "Algoritmos e Programacao"};
   Disciplina disc4 = {4, 60, "Processamento de Imagens"};
   Disciplina disc5 = {5, 60, "Visao Computacional"};
   
   insereNodoGrafoLA(grafo, disc0);
   insereNodoGrafoLA(grafo, disc1);
   insereNodoGrafoLA(grafo, disc2);
   insereNodoGrafoLA(grafo, disc3);
   insereNodoGrafoLA(grafo, disc4);
   insereNodoGrafoLA(grafo, disc5);
   
   insereArestaGrafoLA(grafo, 0, 1);
   insereArestaGrafoLA(grafo, 0, 2);

   insereArestaGrafoLA(grafo, 3, 1);
   insereArestaGrafoLA(grafo, 3, 2);
   insereArestaGrafoLA(grafo, 3, 4);
   insereArestaGrafoLA(grafo, 3, 5);

   insereArestaGrafoLA(grafo, 4, 5);
   
   removeArestaGrafoLA(grafo,3,5);
   
   imprimeGrafoLA(grafo);
   
   //printf("\n\n Ha conexao entre as materias: %d",haCaminhoGrafoLA(grafo, 0, 4));
   printf("\n\n Caminho entre as materias: ");
   
   imprimeCaminhoMinimoInversoGrafoLA(grafo, 3, 5);
   
   destroiGrafoLA(grafo);

   return 0;
}
