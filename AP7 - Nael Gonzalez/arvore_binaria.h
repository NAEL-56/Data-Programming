#ifndef __ARVORE_BINARIA_H_
#define __ARVORE_BINARIA_H_

#define TAM_MAX_NOME 40
#define TAM_MAX_EMAIL 25

typedef struct{
   int matricula;
   char nome[TAM_MAX_NOME];
   char email[TAM_MAX_EMAIL];
} Info;

typedef struct noArvBinaria{
   Info info;
   struct noArvBinaria *esq;
   struct noArvBinaria *dir;
} NoArvBinaria;

typedef struct{
   struct noArvBinaria *raiz;
} ArvBinaria;


// Funcao que cria uma arvore
ArvBinaria* criaArvore();

// Funcao que imprime uma arvore
void imprimeArvore(ArvBinaria *arv);

// Funcao que insere um elemento na arvore
void insereArvore(ArvBinaria *arv, Info info);

// Funcao que busca uma informacao na arvore
Info buscaInfoArvore(ArvBinaria *arv, int matricula);

// Funcao que remove uma informacao da arvore
void removeInfoArvore(ArvBinaria *arv, int matricula);

// Funcao que destroi uma arvore
void destroiArvore(ArvBinaria *arv);

void imprimeIndentadoArvore(ArvBinaria *arv);

int ehDegeneradaArvore(ArvBinaria *arv);

#endif
