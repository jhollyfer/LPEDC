// 0175 · Conceitos e sucessor
// Exercício E1050 · ★★★

#include <stdio.h>
#include "arvpai.h"

// devolve a altura de r, ou -2 se algum nó tiver fator fora de -1..1.
// Uma passada só: cada nó usa as alturas que os filhos já devolveram.
int altura_se_avl(const NoP *r) {
    if (r == NULL) {
        return -1;
    }
    int he = altura_se_avl(r->esq);
    int hd = altura_se_avl(r->dir);
    if (he == -2 || hd == -2 || he - hd > 1 || hd - he > 1) {
        return -2;
    }
    return 1 + (he > hd ? he : hd);
}

void mostra_desequilibrados(const NoP *r) {
    if (r == NULL) {
        return;
    }
    mostra_desequilibrados(r->esq);
    int f = ap_fator(r);
    if (f > 1 || f < -1) {
        printf(" %d (fator %d)", r->chave, f);
    }
    mostra_desequilibrados(r->dir);
}

void testa(const char *nome, const int *v, int n) {
    NoP *raiz = NULL;
    for (int i = 0; i < n; i++) {
        raiz = ap_insere(raiz, v[i]);
    }
    int h = altura_se_avl(raiz);
    printf("%s: ", nome);
    if (h == -2) {
        printf("não é AVL. Desequilibrados:");
        mostra_desequilibrados(raiz);
        printf("\n");
    } else {
        printf("é AVL, altura %d\n", h);
    }
    raiz = ap_libera(raiz);
}

int main(void) {
    int horarios[] = {800, 615, 1030, 700, 650, 920, 1200, 730};
    int codigos[] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65};
    int crescente[] = {1, 2, 3, 4, 5};
    testa("horários", horarios, 8);
    testa("códigos", codigos, 10);
    testa("crescente", crescente, 5);
    return 0;
}
