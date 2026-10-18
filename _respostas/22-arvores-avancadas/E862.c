// 0144 · Árvores gerais
// Exercício E862 · ★★☆

#include <stdio.h>
#include "arvgen.h"

int conta_nivel(const NoG *r, int alvo) {
    if (alvo == 0) {
        return 1;
    }
    int total = 0;
    for (const NoG *p = r->filho; p != NULL; p = p->irmao) {
        total += conta_nivel(p, alvo - 1);
    }
    return total;
}

void mostra_nivel(const NoG *r, int alvo) {
    if (alvo == 0) {
        printf(" %s", r->nome);
        return;
    }
    for (const NoG *p = r->filho; p != NULL; p = p->irmao) {
        mostra_nivel(p, alvo - 1);
    }
}

int main(void) {
    NoG *joaquim = ag_cria("Joaquim", 0);
    NoG *rosa = ag_adiciona(joaquim, "Rosa", 0);
    ag_adiciona(rosa, "Paulo", 0);
    NoG *rita = ag_adiciona(rosa, "Rita", 0);
    ag_adiciona(rita, "Leo", 0);
    NoG *jorge = ag_adiciona(joaquim, "Jorge", 0);
    ag_adiciona(jorge, "Nina", 0);
    ag_adiciona(jorge, "Otto", 0);
    ag_adiciona(jorge, "Pedro", 0);
    ag_adiciona(joaquim, "Vera", 0);

    for (int g = 0; g <= ag_altura(joaquim); g++) {
        printf("Geração %d (%d):", g, conta_nivel(joaquim, g));
        mostra_nivel(joaquim, g);
        printf("\n");
    }

    ag_libera(joaquim);
    return 0;
}
