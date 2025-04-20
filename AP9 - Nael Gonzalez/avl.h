#ifndef _AVL_H_
#define _AVL_H_

#define TAM_MAX_NOME 40
#define TAM_MAX_EMAIL 25

typedef struct{
   int matricula;
   char nome[TAM_MAX_NOME];
   char email[TAM_MAX_EMAIL];
} Aluno;

typedef Aluno Info;

typedef struct noArvAVL{
   Info info;
   int alt;
   struct noArvAVL *esq;
   struct noArvAVL *dir;
} NoArvAVL;

typedef struct{
   struct noArvAVL *raiz;
} AVL;


// Funcao que cria uma AVL
AVL* criaAVL();

// Funcao que imprime uma AVL
void imprimeAVL(AVL *arv);

// Funcao que insere um elemento na AVL
void insereAVL(AVL *arv, Info info);

// Funcao que busca uma informacao na AVL
Info buscaInfoAVL(AVL *arv, int matricula);

// Funcao que destroi uma AVL
void destroiAVL(AVL *arv);

int removeInfoAVL(AVL *arv, int matricula);

int tamanhoAVL(AVL *arv);

#endif
