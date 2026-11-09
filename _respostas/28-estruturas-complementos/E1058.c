// 0177 · Rubro-negra clássica
// Exercício E1058 · ★☆☆

#include <stdio.h>
#include "vermelhopreto.h"

NoVP *minimo(ArvVP *T, NoVP *x) {
    while (x->esq != &T->nil) {
        x = x->esq;
    }
    return x;
}

NoVP *maximo(ArvVP *T, NoVP *x) {
    while (x->dir != &T->nil) {
        x = x->dir;
    }
    return x;
}

int main(void) {
    ArvVP *T = vp_cria();
    if (T == NULL) {
        return 1;
    }
    int ceps[] = {69050, 69020, 69099, 69010, 69077, 69045, 69033};
    for (int i = 0; i < 7; i++) {
        vp_insere(T, ceps[i]);
    }
    printf("em ordem:");
    vp_em_ordem(T);
    printf("\nmenor: %d | maior: %d\n", minimo(T, T->raiz)->chave, maximo(T, T->raiz)->chave);
    NoVP *x = vp_busca(T, 69088);
    printf("69088: %s\n", x == &T->nil ? "não cadastrado" : "cadastrado");
    vp_libera(T);
    return 0;
}
