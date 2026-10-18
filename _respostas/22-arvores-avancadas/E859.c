// 0144 · Árvores gerais
// Exercício E859 · ★☆☆

#include <stdio.h>
#include "arvgen.h"

int folhas(const NoG *r) {
    if (r->filho == NULL) {
        return 1;
    }
    int total = 0;
    for (const NoG *p = r->filho; p != NULL; p = p->irmao) {
        total += folhas(p);
    }
    return total;
}

int grupos(const NoG *r) {
    if (r->filho == NULL) {
        return 0;
    }
    int total = 1; // r tem filho: conta ele
    for (const NoG *p = r->filho; p != NULL; p = p->irmao) {
        total += grupos(p);
    }
    return total;
}

int main(void) {
    NoG *churrasco = ag_cria("churrasco", 0);
    NoG *carnes = ag_adiciona(churrasco, "carnes", 0);
    ag_adiciona(carnes, "picanha", 120);
    ag_adiciona(carnes, "linguica", 35);
    ag_adiciona(carnes, "frango", 28);
    NoG *bebidas = ag_adiciona(churrasco, "bebidas", 0);
    ag_adiciona(bebidas, "refri", 24);
    ag_adiciona(bebidas, "cerveja", 60);
    ag_adiciona(churrasco, "carvao", 30);

    printf("Itens (folhas): %d\n", folhas(churrasco));
    printf("Grupos (nós com filhos): %d\n", grupos(churrasco));
    printf("Total: R$ %d\n", ag_total(churrasco));

    ag_libera(churrasco);
    return 0;
}
