// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2204 · ★☆☆ · A altura negra de cada caminho
//
// Outra regra da rubro-negra: todo caminho de um nó até um NULL passa pelo
// MESMO número de nós pretos. Esse número, contado a partir da raiz, é a
// ALTURA NEGRA. Complete altura_negra(r): ela devolve a altura negra da
// árvore (NULL conta 0 aqui) ou -1 se dois caminhos discordam. O main
// testa as duas árvores (V vermelho, P preto, escritas como raiz(esquerda,
// direita), com - no lugar de um filho vazio) e mostra o resultado.
//
//   Árvore 1: 30P(15V(8P, 20P), 45P(-, 50V))
//   Árvore 2: 30P(15P(8P, -), 45P(40P, 50P))
//
//   Saída esperada:
//   Árvore 1: altura negra 2
//   Árvore 2: altura negra -1
//
// Dicas:
// 1. Calcule e = altura_negra(esq) e d = altura_negra(dir). Se algum for
//    -1 ou e != d, devolva -1.
// 2. Senão, devolva e + (r é preto ? 1 : 0).
// 3. Resposta esperada: 2 na árvore 1; -1 na 2 (pela esquerda do 15 são 3
//    pretos; pela direita do 15, só 2).
//
// Escreva sua resposta abaixo (complete o código):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    bool vermelho;
    struct No *esq, *dir;
} No;

No *no(int chave, char cor, No *esq, No *dir) {
    No *n = malloc(sizeof *n);
    if (n == NULL) {
        exit(1);
    }
    *n = (No){chave, cor == 'V', esq, dir};
    return n;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int altura_negra(const No *r) {
    (void)r;
    // COMPLETE AQUI
    return 0;
}

int main(void) {
    No *a1 = no(30, 'P', no(15, 'V', no(8, 'P', NULL, NULL), no(20, 'P', NULL, NULL)),
                no(45, 'P', NULL, no(50, 'V', NULL, NULL)));
    No *a2 = no(30, 'P', no(15, 'P', no(8, 'P', NULL, NULL), NULL),
                no(45, 'P', no(40, 'P', NULL, NULL), no(50, 'P', NULL, NULL)));
    printf("Árvore 1: altura negra %d\n", altura_negra(a1));
    printf("Árvore 2: altura negra %d\n", altura_negra(a2));
    libera(a1);
    libera(a2);
    return 0;
}
