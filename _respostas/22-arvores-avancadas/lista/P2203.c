// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2203 · ★☆☆ · Vermelho com filho vermelho

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

int sem_vv(const No *r) {
    if (r == NULL) {
        return 1;
    }
    if (r->vermelho) {
        if ((r->esq != NULL && r->esq->vermelho) || (r->dir != NULL && r->dir->vermelho)) {
            printf("  %d vermelho tem filho vermelho\n", r->chave);
            return 0;
        }
    }
    return sem_vv(r->esq) && sem_vv(r->dir);
}

int main(void) {
    No *a1 = no(20, 'P', no(10, 'V', no(5, 'P', NULL, NULL), no(15, 'P', NULL, NULL)),
                no(30, 'V', no(25, 'P', NULL, NULL), NULL));
    No *a2 = no(20, 'P', no(10, 'P', NULL, NULL),
                no(30, 'V', no(25, 'V', NULL, NULL), no(40, 'P', NULL, NULL)));
    printf("Árvore 1:\n");
    printf("  %s\n", sem_vv(a1) ? "regra vale" : "regra quebrada");
    printf("Árvore 2:\n");
    printf("  %s\n", sem_vv(a2) ? "regra vale" : "regra quebrada");
    libera(a1);
    libera(a2);
    return 0;
}
