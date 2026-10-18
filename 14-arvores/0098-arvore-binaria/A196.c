// A196 · Calculando a árvore de expressão

#include <stdio.h>
#include "arvore.h"

// folha é um dígito; nó interno é um operador aplicado às duas subárvores
int avalia(const No *r) {
    if (r->esq == NULL && r->dir == NULL) {
        return r->info - '0'; // '8' vira 8
    }
    int a = avalia(r->esq); // primeiro as subárvores (pós-ordem)...
    int b = avalia(r->dir);
    switch (r->info) {      // ...depois o operador da raiz
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    default:  return a / b;
    }
}

// em ordem com parênteses em volta de cada operação
void mostra(const No *r) {
    if (r->esq == NULL && r->dir == NULL) {
        printf("%c", r->info);
        return;
    }
    printf("(");
    mostra(r->esq);
    printf(" %c ", r->info);
    mostra(r->dir);
    printf(")");
}

int main(void) {
    No *raiz = arv_cria('*',
                        arv_cria('-', arv_cria('8', NULL, NULL), arv_cria('3', NULL, NULL)),
                        arv_cria('+', arv_cria('4', NULL, NULL), arv_cria('2', NULL, NULL)));

    mostra(raiz);
    printf(" = %d\n", avalia(raiz));

    // troca a subárvore da direita: em vez de (4 + 2), só 9
    raiz->dir = arv_libera(raiz->dir); // poda primeiro (senão vaza)
    raiz->dir = arv_cria('9', NULL, NULL);
    mostra(raiz);
    printf(" = %d\n", avalia(raiz));

    raiz = arv_libera(raiz);
    return 0;
}
// Saída:
// ((8 - 3) * (4 + 2)) = 30
// ((8 - 3) * 9) = 45
