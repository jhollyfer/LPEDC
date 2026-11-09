// 0177 · Rubro-negra clássica
// Exercício E1059 · ★★☆

#include <stdio.h>
#include "vermelhopreto.h"

// altura negra de x: pretos de x (exclusive) até a folha nil (inclusive)
int bh(const ArvVP *T, const NoVP *x) {
    int conta = 0;
    while (x != &T->nil) {
        x = x->esq;
        if (x->cor == PRETO) {
            conta++;
        }
    }
    return conta;
}

int nos(const ArvVP *T, const NoVP *x) {
    return x == &T->nil ? 0 : 1 + nos(T, x->esq) + nos(T, x->dir);
}

void tabela(const ArvVP *T, const NoVP *x) {
    if (x == &T->nil) {
        return;
    }
    tabela(T, x->esq);
    int b = bh(T, x), n = nos(T, x);
    printf("%3d %-8s bh %d | nós %2d | 2^bh - 1 = %d %s\n", x->chave,
           x->cor == VERMELHO ? "vermelho" : "preto", b, n, (1 << b) - 1,
           n >= (1 << b) - 1 ? "ok" : "FALHOU");
    tabela(T, x->dir);
}

int main(void) {
    ArvVP *T = vp_cria();
    if (T == NULL) {
        return 1;
    }
    int v[] = {40, 20, 60, 10, 30, 50, 70, 5, 15, 25};
    for (int i = 0; i < 10; i++) {
        vp_insere(T, v[i]);
    }
    tabela(T, T->raiz);
    vp_libera(T);
    return 0;
}
