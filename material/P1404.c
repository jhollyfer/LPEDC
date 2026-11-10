// Lista · Módulo 14 · Árvores
// Exercício P1404 · ★☆☆ · A árvore genealógica, uma geração por linha
//
// Complete por_nivel, o percurso por nível (largura), mostrando cada nível
// numa linha. Use uma fila num vetor No *fila[32] com índices ini e fim. O
// truque para separar os níveis: no começo de cada volta, os que estão na
// fila (fim - ini) são exatamente os do nível atual. Tire esses todos,
// imprimindo e enfileirando os filhos, e só então passe de linha.
//
//   Saída esperada:
//   nível 0: Joana
//   nível 1: Pedro Carla
//   nível 2: Lara Davi Tomas
//   nível 3: Nina Yuri Zoe
//
// Dicas:
// 1. int tamanho = fim - ini; e um for de 0 a tamanho - 1.
// 2. Enfileire o filho esquerdo antes do direito.
// 3. O percurso por nível é a BFS (módulo 16) aplicada à árvore: fila, e não
//    pilha nem recursão.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char nome[10];
    struct No *esq, *dir;
} No;

No *novo(const char *nome, No *esq, No *dir) {
    No *p = malloc(sizeof(No));
    if (p == NULL) {
        exit(1);
    }
    snprintf(p->nome, sizeof p->nome, "%s", nome);
    p->esq = esq;
    p->dir = dir;
    return p;
}

void por_nivel(No *raiz) {
    No *fila[32];
    int ini = 0, fim = 0, nivel = 0;
    // complete aqui
    (void)raiz;
    (void)fila;
    (void)ini;
    (void)fim;
    (void)nivel;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    No *raiz = novo("Joana",
                    novo("Pedro", novo("Lara", NULL, NULL), novo("Davi", novo("Nina", NULL, NULL), NULL)),
                    novo("Carla", NULL, novo("Tomas", novo("Yuri", NULL, NULL), novo("Zoe", NULL, NULL))));

    por_nivel(raiz);
    libera(raiz);
    return 0;
}
