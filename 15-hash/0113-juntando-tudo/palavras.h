// palavras.h · TAD contador de palavras (tabela hash com encadeamento)
#ifndef PALAVRAS_H
#define PALAVRAS_H

#include <stdbool.h>

#define TAM_PALAVRA 32 // palavras maiores são cortadas em 31 bytes

typedef struct Contador Contador;

// uma linha do relatório: a palavra e quantas vezes apareceu
typedef struct {
    const char *palavra; // aponta para dentro do contador: não dê free
    int vezes;
} Contagem;

// cria um contador vazio com m baldes; NULL se faltar memória
Contador *contador_cria(int m);

// soma 1 na contagem da palavra (cria com 1 se for nova); false sem memória
bool contador_soma(Contador *c, const char *palavra);

// quantas vezes a palavra apareceu (0 se nunca)
int contador_vezes(const Contador *c, const char *palavra);

// quantas palavras foram somadas, contando repetições
int contador_total(const Contador *c);

// quantas palavras diferentes existem
int contador_distintas(const Contador *c);

// vetor novo (malloc) com uma Contagem por palavra diferente, em ordem
// qualquer. Quem chama dá free no vetor. NULL se faltar memória.
Contagem *contador_lista(const Contador *c);

// libera tudo; os ponteiros das Contagem deixam de valer
void contador_libera(Contador *c);

#endif
