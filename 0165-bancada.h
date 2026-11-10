// bancada.h · interface da bancada de testes: quatro estruturas de busca
// atrás da mesma interface, para medir todas com o mesmo teste
#ifndef BANCADA_H
#define BANCADA_H

#include <stdbool.h>

// um concorrente é uma tabela de ponteiros para função (assunto 0050): quem
// mede não sabe qual estrutura está do outro lado do void *
typedef struct {
    const char *nome;
    void *(*cria)(void);
    void (*insere)(void *e, int chave);            // repetida é ignorada
    bool (*busca)(void *e, int chave, int *custo); // custo: chaves comparadas
    void (*libera)(void *e);
} Estrutura;

#define NUM_CONCORRENTES 4

// BST sem balanceamento, AVL, skip list e lista com mover para a frente
extern const Estrutura CONCORRENTES[NUM_CONCORRENTES];

// sorteio repetível (o mesmo gerador do skip.c): devolve de 0 a 32767
int bc_sorteio(unsigned *estado);

// embaralha v[0..n-1] (Fisher-Yates) com o sorteio acima
void bc_embaralha(int v[], int n, unsigned *estado);

#endif
