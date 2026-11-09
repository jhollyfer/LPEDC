// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2204 · ★☆☆ · A altura negra de cada caminho

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
    if (r == NULL) {
        return 0;
    }
    int e = altura_negra(r->esq), d = altura_negra(r->dir);
    if (e < 0 || d < 0 || e != d) {
        return -1;
    }
    return e + (r->vermelho ? 0 : 1);
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
