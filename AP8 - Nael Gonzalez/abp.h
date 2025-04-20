#ifndef _ABP_H_
#define _ABP_H_

#define TAM_MAX_NOME 40
#define TAM_MAX_EMAIL 25

typedef struct{
   int matricula;
   char nome[TAM_MAX_NOME];
   char email[TAM_MAX_EMAIL];
} Aluno;

typedef Aluno Info;

typedef struct noArvBinaria{
   Info info;
   struct noArvBinaria *esq;
   struct noArvBinaria *dir;
} NoArvBinaria;

typedef struct{
   struct noArvBinaria *raiz;
} ABP;


// Funcao que cria uma ABP
ABP* criaABP();

// Funcao que imprime uma ABP
void imprimeABP(ABP *arv);

// Funcao que insere um elemento na ABP
void insereABP(ABP *arv, Info info);

// Funcao que busca uma informacao na ABP
Info buscaInfoABP(ABP *arv, int matricula);

// Funcao que remove uma informacao da ABP
void removeInfoABP(ABP *arv, int matricula);

// Funcao que destroi uma ABP
void destroiABP(ABP *arv);

void imprimeABPParentesesAninhados(ABP *arv);

int minimoABP(ABP *arv);

int maximoABP(ABP *arv);

void imprimeIndentadoArvore(ABP *arv);

#endif
