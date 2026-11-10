// A354 · Quantas vezes cada caso aparece

#include <stdio.h>
#include "0177-vermelhopreto.h"

int main(void) {
    int n = 10000;
    ArvVP *T = vp_cria();
    if (T == NULL) {
        return 1;
    }
    int max_rot = 0, max_caso1 = 0;
    for (int i = 0; i < n; i++) {
        int rot = T->rotacoes, c1 = T->casos[1];
        vp_insere(T, (int)((long)i * 7919 % n));
        if (T->rotacoes - rot > max_rot) {
            max_rot = T->rotacoes - rot;
        }
        if (T->casos[1] - c1 > max_caso1) {
            max_caso1 = T->casos[1] - c1;
        }
    }
    printf("%d inserções embaralhadas\n", n);
    printf("caso 1 (tio vermelho, recolore): %d vezes\n", T->casos[1]);
    printf("caso 2 (tio preto, triângulo):   %d vezes\n", T->casos[2]);
    printf("caso 3 (tio preto, linha):       %d vezes\n", T->casos[3]);
    printf("rotações: %d no total, no máximo %d numa inserção\n", T->rotacoes, max_rot);
    printf("recolorações (caso 1) seguidas numa inserção: no máximo %d\n", max_caso1);
    printf("altura %d, altura negra %d\n", vp_altura(T), vp_altura_negra(T));
    vp_libera(T);
    return 0;
}
// Saída:
// 10000 inserções embaralhadas
// caso 1 (tio vermelho, recolore): 4401 vezes
// caso 2 (tio preto, triângulo):   8 vezes
// caso 3 (tio preto, linha):       3347 vezes
// rotações: 3355 no total, no máximo 2 numa inserção
// recolorações (caso 1) seguidas numa inserção: no máximo 7
// altura 15, altura negra 8
