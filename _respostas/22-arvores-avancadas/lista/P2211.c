// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2211 · ★★☆ · O fiscal completo da rubro-negra

#include <limits.h>
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

No *f(int chave, char cor) {
    return no(chave, cor, NULL, NULL);
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

bool busca_ok(const No *r, long min, long max) {
    if (r == NULL) {
        return true;
    }
    if (r->chave <= min || r->chave >= max) {
        return false;
    }
    return busca_ok(r->esq, min, r->chave) && busca_ok(r->dir, r->chave, max);
}

int quebrou = 0;

int cores(const No *r) {
    if (r == NULL) {
        return 0;
    }
    if (r->vermelho && (( r->esq && r->esq->vermelho) || (r->dir && r->dir->vermelho))) {
        if (quebrou == 0) {
            quebrou = 3;
        }
        return -1;
    }
    int e = cores(r->esq), d = cores(r->dir);
    if (e < 0 || d < 0) {
        return -1;
    }
    if (e != d) {
        if (quebrou == 0) {
            quebrou = 4;
        }
        return -1;
    }
    return e + (r->vermelho ? 0 : 1);
}

int fiscal(const No *r, int *altura_negra) {
    if (!busca_ok(r, (long)INT_MIN - 1, (long)INT_MAX + 1)) {
        return 1;
    }
    if (r != NULL && r->vermelho) {
        return 2;
    }
    quebrou = 0;
    int h = cores(r);
    if (h < 0) {
        return quebrou;
    }
    *altura_negra = h;
    return 0;
}

int main(void) {
    No *arv[4] = {
        no(40, 'P', no(20, 'V', f(10, 'P'), f(30, 'P')), no(60, 'V', f(50, 'P'), f(70, 'P'))),
        no(40, 'P', no(20, 'P', f(10, 'V'), f(30, 'V')), no(60, 'P', f(50, 'V'), f(45, 'V'))),
        no(40, 'V', f(20, 'P'), f(60, 'P')),
        no(40, 'P', no(20, 'P', f(10, 'P'), NULL), no(60, 'P', f(50, 'V'), f(70, 'P'))),
    };
    for (int i = 0; i < 4; i++) {
        int h = 0;
        int regra = fiscal(arv[i], &h);
        if (regra == 0) {
            printf("%c: rubro-negra válida, altura negra %d\n", 'A' + i, h);
        } else {
            printf("%c: quebra a regra %d\n", 'A' + i, regra);
        }
        libera(arv[i]);
    }
    return 0;
}
