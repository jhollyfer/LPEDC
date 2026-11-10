// arvoreb.h · interface do TAD árvore B (grau mínimo T = 2: de 1 a 3 chaves por nó)
#ifndef ARVOREB_H
#define ARVOREB_H

#include <stdbool.h>

#define AB_T 2               // grau mínimo
#define AB_MAX (2 * AB_T - 1) // máximo de chaves num nó (3)

typedef struct NoB {
    int n;                      // quantas chaves estão em uso
    int chave[AB_MAX];          // em ordem crescente
    struct NoB *filho[AB_MAX + 1];
    bool folha;
} NoB;

// insere (repetida é ignorada) e devolve a raiz, que muda quando ela se divide
NoB *ab_insere(NoB *raiz, int chave);

// procura a chave; em *visitados, quantos nós foram lidos (pode ser NULL)
bool ab_busca(const NoB *r, int chave, int *visitados);

int ab_altura(const NoB *r);  // em arestas: só a raiz, altura 0; vazia, -1
void ab_mostra(const NoB *r); // um nível por linha: [10 20] [40]
int ab_divisoes(void);        // quantas divisões de nó já aconteceram

NoB *ab_libera(NoB *r);

#endif
