// A153 · Buscar por condição e tirar o último

#include <stdio.h>
#include "lista.h"

// variação da busca: em vez de "igual a", o primeiro nó "acima de" limite
static No *busca_acima(No *inicio, int limite) {
    No *p = inicio;
    while (p != NULL && p->valor <= limite) {
        p = p->prox;
    }
    return p; // o nó, ou NULL se ninguém passou do limite
}

int main(void) {
    // contas do mês, em reais
    No *contas = NULL;
    contas = lista_insere_inicio(contas, 480);
    contas = lista_insere_inicio(contas, 99);
    contas = lista_insere_inicio(contas, 135);
    contas = lista_insere_inicio(contas, 62);
    lista_imprime(contas);

    No *cara = busca_acima(contas, 100);
    if (cara != NULL) printf("primeira acima de R$ 100: %d\n", cara->valor);
    if (busca_acima(contas, 500) == NULL) printf("nenhuma acima de R$ 500\n");

    // tirar o ÚLTIMO: o anterior dele (99) passa a apontar para NULL
    lista_remove(&contas, 480);
    lista_imprime(contas);

    // tirar até sobrar um nó e depois o único: o início vira NULL
    lista_remove(&contas, 135);
    lista_remove(&contas, 62);
    lista_imprime(contas);
    lista_remove(&contas, 99);
    lista_imprime(contas);

    // na lista vazia, buscar e remover só devolvem "não achei"
    if (lista_busca(contas, 62) == NULL && !lista_remove(&contas, 62)) {
        printf("lista vazia: nada para buscar nem tirar\n");
    }

    lista_libera(contas);
    return 0;
}
// Saída:
// 62 -> 135 -> 99 -> 480 -> NULL
// primeira acima de R$ 100: 135
// nenhuma acima de R$ 500
// 62 -> 135 -> 99 -> NULL
// 99 -> NULL
// NULL
// lista vazia: nada para buscar nem tirar
