#include <stdio.h>
#include <stdlib.h>
#include "grafo_la.h"
#include "fila_enc.c"

// Funcao que cria um grafo 
GrafoLA *criaGrafoLA(int numVertices){
   int chave;
   GrafoLA * grafo = (GrafoLA*)malloc(sizeof(GrafoLA));
   grafo->vertices = (NoGrafo*)malloc(sizeof(NoGrafo)*numVertices);
   for (chave = 0; chave < numVertices; chave++)
      grafo->vertices[chave].lista = NULL;
   grafo->numVertices = numVertices;
   return grafo;
}

// Funcao que insere um nodo
void insereNodoGrafoLA(GrafoLA *grafo, Disciplina disciplina){
   // Assume ids que funcionam como indexadores
   grafo->vertices[disciplina.id].info = disciplina;
}

// Funcao que insere uma aresta em um grafo
void insereArestaGrafoLA(GrafoLA *grafo, int chave1, int chave2){
   ArestaGrafo *arestaAux = (ArestaGrafo*)malloc(sizeof(ArestaGrafo));
   arestaAux->chaveDest = chave2; 
   arestaAux->prox = grafo->vertices[chave1].lista;
   grafo->vertices[chave1].lista = arestaAux;
   // Em grafos nao-direcionados, ha a insercao da aresta simetrica
}

// Funcao que imprime vertices e arcos
void imprimeGrafoLA(GrafoLA *grafo){
   int chave;
   for (chave = 0; chave < grafo->numVertices; chave++){
      printf("%s [CH %d]\n", grafo->vertices[chave].info.nome, grafo->vertices[chave].info.ch);
   }
   printf("\n");
   for (chave = 0; chave < grafo->numVertices; chave++){
		ArestaGrafo *arestaAux = grafo->vertices[chave].lista; 
      for (; arestaAux != NULL; arestaAux = arestaAux->prox){
           printf("%s eh prerequisito para %s\n", grafo->vertices[chave].info.nome, grafo->vertices[arestaAux->chaveDest].info.nome);
      }     
   }
}

// Funcao que destroi um grafo
void destroiGrafoLA(GrafoLA *grafo){
   int chave;
   for (chave = 0; chave < grafo->numVertices; chave++) {
      ArestaGrafo *arestaAux = grafo->vertices[chave].lista;
      while(arestaAux != NULL){
         ArestaGrafo *arestaTmp = arestaAux->prox;
         free(arestaAux); 
         arestaAux = arestaTmp;
      }
   }
   free(grafo->vertices);
   free(grafo);
}

// Funcao auxiliar para Algs. de Caminhamento
void inicializaCaminhamentoGrafoLA(GrafoLA *grafo){
   int chave;
   ArestaGrafo *arestaAux;
   grafo->timestamp = 0;
   for (chave = 0; chave < grafo->numVertices; chave++){
      grafo->vertices[chave].cor = BRANCO;
      grafo->vertices[chave].tEntrada = -1; 
      grafo->vertices[chave].tSaida = -1; 
      grafo->vertices[chave].pai = -1; 
   }
   for (chave = 0; chave < grafo->numVertices; chave++)
		arestaAux = grafo->vertices[chave].lista;
		for (; arestaAux != NULL; arestaAux = arestaAux->prox){
           arestaAux->tipo = OUTRA;
      }
}

// Funcao auxiliar recursiva para o Caminhamento em Profundidade
void visitaNodoDFSGrafoLA(GrafoLA *grafo, int chave){
   grafo->vertices[chave].cor = CINZA;
   grafo->vertices[chave].tEntrada = grafo->timestamp++;
   ArestaGrafo *arestaAux = grafo->vertices[chave].lista;
   for(; arestaAux != NULL; arestaAux = arestaAux->prox){
       int chaveAux = arestaAux->chaveDest;
       if(grafo->vertices[chaveAux].cor == BRANCO){
          grafo->vertices[chaveAux].pai = chave; 
          arestaAux->tipo = EXPLORATORIA; 
          visitaNodoDFSGrafoLA(grafo, chaveAux);     
       }
   }
   grafo->vertices[chave].cor = PRETO;
   grafo->vertices[chave].tSaida = grafo->timestamp++; 
}

// Alg. para Caminhamento em Profundidade
void DFSGrafoLA(GrafoLA *grafo, int chaveInicial){
   inicializaCaminhamentoGrafoLA(grafo);
   visitaNodoDFSGrafoLA(grafo, chaveInicial); 
}

// Alg. para Caminhamento em Amplitude
void BFSGrafoLA(GrafoLA *grafo, int chaveInicial){
   inicializaCaminhamentoGrafoLA(grafo);
   FilaEnc *fila = criaFila();
   enfileiraFila(fila, chaveInicial); 
   grafo->vertices[chaveInicial].tEntrada = grafo->timestamp++;
   grafo->vertices[chaveInicial].cor = CINZA;
   grafo->vertices[chaveInicial].distInicio = 0;
   while(!vaziaFila(fila)){
      int chave1 = desenfileiraFila(fila);
      ArestaGrafo *arestaAux = grafo->vertices[chave1].lista;
      for(; arestaAux != NULL; arestaAux = arestaAux->prox){
          int chave2 = arestaAux->chaveDest;
          if(grafo->vertices[chave2].cor == BRANCO){
             grafo->vertices[chave2].pai = chave1;
             grafo->vertices[chave2].distInicio = grafo->vertices[chave1].distInicio + 1;
             grafo->vertices[chave2].tEntrada = grafo->timestamp++;
             grafo->vertices[chave2].cor = CINZA;
             arestaAux->tipo = EXPLORATORIA;
             enfileiraFila(fila, chave2); 
          }
      }
      grafo->vertices[chave1].cor = PRETO;
      grafo->vertices[chave1].tSaida = grafo->timestamp++;
   }
   destroiFila(fila);
}

int removeArestaGrafoLA(GrafoLA *grafo, int origem, int destino){
	ArestaGrafo *arestaAux = grafo->vertices[origem].lista;
	int i=0;
	if(arestaAux->chaveDest == destino){
		grafo->vertices[origem].lista = grafo->vertices[origem].lista->prox;
		free(arestaAux);
	} else for(; arestaAux->prox != NULL; arestaAux = arestaAux->prox){
				if(arestaAux->prox->chaveDest == destino){
					arestaAux->prox = arestaAux->prox->prox;
					free(arestaAux->prox);
					return 1;
				}
			}
	return 0;
}

int haCaminhoGrafoLA(GrafoLA *grafo, int origem, int destino){
	
	inicializaCaminhamentoGrafoLA(grafo);
	BFSGrafoLA(grafo, origem);
	if(grafo->vertices[destino].pai == -1) return 0;
	else return 1;
}



void imprimeCaminhoMinimoInversoGrafoLA(GrafoLA *grafo, int origem, int destino){
	if(haCaminhoGrafoLA(grafo, origem, destino)){
		
		int nodoAux;
		for(nodoAux = destino; nodoAux != origem; nodoAux = grafo->vertices[nodoAux].pai){
			printf("%d-", nodoAux);
		}
		printf("%d", origem);
	}
}

int componentesConexosGrafoLA(GrafoLA *grafo){
	int i, contador = 0, flag;
	ArestaGrafo *arestaAux;
	
	for(; i < grafo->numVertices; i++){
		flag =1;
		for(arestaAux = grafo->vertices[i].lista; arestaAux != NULL; arestaAux = arestaAux->prox){
			if(arestaAux->chaveDest == i){
				flag=0;
				break;
			}
		}
		if(flag) contador++;
	}
	return contador;
}
























