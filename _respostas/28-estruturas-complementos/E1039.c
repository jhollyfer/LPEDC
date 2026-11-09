// 0174 · Lista com sentinela
// Exercício E1039 · ★☆☆

#include <stdio.h>
#include "sentinela.h"

int soma(const ListaS *L) {
    int total = 0;
    for (const NoS *x = L->nil.prox; x != &L->nil; x = x->prox) {
        total += x->chave;
    }
    return total;
}

int main(void) {
    ListaS *carrinho = sent_cria();
    if (carrinho == NULL) {
        return 1;
    }
    int precos[] = {1250, 899, 2340, 475};
    for (int i = 0; i < 4; i++) {
        sent_insere_fim(carrinho, precos[i]);
    }
    printf("Carrinho: ");
    sent_mostra(carrinho);
    int total = soma(carrinho);
    printf("Total: R$ %d.%02d\n", total / 100, total % 100);
    sent_libera(carrinho);
    return 0;
}
