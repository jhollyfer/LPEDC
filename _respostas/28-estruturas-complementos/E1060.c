// 0177 · Rubro-negra clássica
// Exercício E1060 · ★★☆

#include <stdio.h>
#include "vermelhopreto.h"

int main(void) {
    ArvVP *T = vp_cria();
    if (T == NULL) {
        return 1;
    }
    int senhas[] = {10, 20, 30, 15, 25, 5, 1, 27};
    for (int i = 0; i < 8; i++) {
        int c1 = T->casos[1], c2 = T->casos[2], c3 = T->casos[3];
        vp_insere(T, senhas[i]);
        printf("insere %2d: caso 1: %d | caso 2: %d | caso 3: %d | pré", senhas[i],
               T->casos[1] - c1, T->casos[2] - c2, T->casos[3] - c3);
        vp_pre_ordem(T);
        printf("\n");
    }
    printf("rotações no total: %d\n", T->rotacoes);
    vp_libera(T);
    return 0;
}
