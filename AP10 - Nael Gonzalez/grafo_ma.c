#include <stdio.h>
#include <stdlib.h>
#include "grafo_ma.h"

// Funcao auxiliar que retorna o indice de um nodo em um grafo
int buscaNodoGrafoMA(GrafoMA *grafo, int matricula);

// Funcao que cria um grafo
GrafoMA* criaGrafoMA(int maxVertices){
   int i, j;
   GrafoMA *grafo = (GrafoMA*)malloc(sizeof(GrafoMA));
   grafo->infos = (Info*)malloc(sizeof(Info)*maxVertices);
   grafo->adjacencias = (int**)malloc(sizeof(int*)*maxVertices);
   for (i = 0; i < maxVertices; i++){
      grafo->adjacencias[i] = (int*)malloc(sizeof(int)*maxVertices);
      for (j = 0; j < maxVertices; j++)
         grafo->adjacencias[i][j] = 0;
   }
   grafo->maxVertices = maxVertices;
   grafo->fim = 0;
   return grafo;
}

// Funcao que insere um nodo em um grafo
int insereNodoGrafoMA(GrafoMA *grafo, Info info){
   if (grafo->fim < grafo->maxVertices && buscaNodoGrafoMA(grafo, info.matricula) == -1){
      grafo->infos[grafo->fim] = info;
      grafo->fim += 1;
      return 1;
   }
   return 0;
}

// Funcao que insere uma aresta em um grafo
int insereArestaGrafoMA(GrafoMA *grafo, int matricula1, int matricula2){
   int indice1, indice2;
	indice1 = buscaNodoGrafoMA(grafo, matricula1);
	indice2 = buscaNodoGrafoMA(grafo, matricula2);
	
	if(indice1 != -1 && indice2 != -1 && indice1 != indice2){
		if(!grafo->adjacencias[matricula1][matricula2])
			grafo->adjacencias[matricula1][matricula2] =1;
		else return 0;
		if(!grafo->adjacencias[matricula2][matricula1])
			grafo->adjacencias[matricula2][matricula1] =1;
		else return 0;
		
   		return 1;
	}
	return 0;
}

// Funcao que remove uma aresta de um grafo
int removeArestaGrafoMA(GrafoMA *grafo, int matricula1, int matricula2){
	int indice1, indice2;
	indice1 = buscaNodoGrafoMA(grafo, matricula1);
	indice2 = buscaNodoGrafoMA(grafo, matricula2);
	
	if(indice1 != -1 && indice2 != -1 && indice1 != indice2){
		if(grafo->adjacencias[matricula1][matricula2])
			grafo->adjacencias[matricula1][matricula2] =0;
		else return 0;
		if(grafo->adjacencias[matricula2][matricula1])
			grafo->adjacencias[matricula2][matricula1] =0;
		else return 0;
   		
   		return 1;
	}
	return 0;
}

// Funcao que imprime nodos e arestas de um grafo
void imprimeGrafoMA(GrafoMA *grafo){
	int i, j;
	
	printf("\n\n Vertices:\n");
	
   for (i = 0; i < grafo->fim; i++)
      printf("%d | %s (%s)\n", grafo->infos[i].matricula, grafo->infos[i].nome, grafo->infos[i].email);
      
    printf("\n\n Arestas:\n");
    
    for(i=0; i<grafo->fim; i++)
    	for(j=i; j<grafo->fim; j++)
    		if(grafo->adjacencias[i][j]) printf("{%s, %s}\n", grafo->infos[i].nome, grafo->infos[j].nome);
    		
    printf("\n\n");    
}

// Funcao que destroi um grafo
void destroiGrafoMA(GrafoMA *grafo){
   int i;
   for (i = 0; i < grafo->maxVertices; i++)
      free(grafo->adjacencias[i]);
   free(grafo->adjacencias);
   free(grafo->infos);
   free(grafo);
}

// Funcao auxiliar que retorna o indice de um nodo em um grafo
int buscaNodoGrafoMA(GrafoMA *grafo, int matricula){
   int i;
   for (i = 0; i < grafo->fim; i++)
      if(grafo->infos[i].matricula == matricula)
         return i;
   return -1;
}

int tamanhoGrafoMA(GrafoMA *grafo){
	int contador=0, i, j;
	
	for(i=0; i<grafo->fim; i++)
    	for(j=i; j<grafo->fim; j++)
    		if(grafo->adjacencias[i][j]) contador++;
    
    return contador;
}

int ordemGrafoMA(GrafoMA *grafo){
	int i;
   for (i = 0; i < grafo->fim; i++){}
   return i;
}

int menorGrauGrafoMA(GrafoMA *grafo){
	int menor= grafo->maxVertices+1, indice_menor=-1, contador=0, i, j;
	
	for(i=0; i<=grafo->fim; i++){
		contador=0;
		
		for(j=0; j<=grafo->fim; j++)
    		if(grafo->adjacencias[i][j]) contador++;
    	
    	if(contador < menor){
    		menor = contador;
    		indice_menor = i;
		}
	}
    	
	return menor;
}

int maiorGrauGrafoMA(GrafoMA *grafo){
	int maior=-1, indice_maior=-1, contador=0, i, j;
	
	for(i=0; i<=grafo->fim; i++){
		contador=0;
		
		for(j=0; j<=grafo->fim; j++)
    		if(grafo->adjacencias[i][j]) contador++;
    	
    	if(contador > maior){
    		maior = contador;
    		indice_maior = i;
		}
	}
    	
	return maior;
}
