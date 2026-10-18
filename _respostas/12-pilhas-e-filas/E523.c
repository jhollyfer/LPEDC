// 0088 · Juntando tudo: a calculadora de expressões
// Exercício E523 · ★☆☆

#include <stdbool.h>
#include <stdio.h>
// Na pasta do assunto basta incluir fila.h e pilha.h (o rodar compila os .c
// junto). Aqui a resolução inclui as implementações para compilar sozinha.
#include "../../12-pilhas-e-filas/0088-juntando-tudo/fila.c"
#include "../../12-pilhas-e-filas/0088-juntando-tudo/pilha.c"

enum { SOMA = -1, SUB = -2, MULT = -3, DIV = -4 };

bool avalia(Fila *posfixa, int *resultado) {
    Pilha *val = pilha_cria();
    if (val == NULL) {
        return false;
    }
    bool ok = true;
    int t, a, b;
    while (ok && fila_retira(posfixa, &t)) {
        if (t >= 0) {
            printf(" %d", t);
            pilha_empilha(val, t);
        } else if (!pilha_desempilha(val, &b) || !pilha_desempilha(val, &a) || (t == DIV && b == 0)) {
            ok = false;
        } else {
            printf(" %c", t == SOMA ? '+' : t == SUB ? '-' : t == MULT ? '*' : '/');
            pilha_empilha(val, t == SOMA ? a + b : t == SUB ? a - b : t == MULT ? a * b : a / b);
        }
    }
    ok = ok && pilha_desempilha(val, resultado) && pilha_vazia(val);
    pilha_libera(val);
    return ok;
}

void calcula(const char *infixa, Fila *posfixa) {
    int r;
    printf("%-11s -> ", infixa);
    if (avalia(posfixa, &r)) {
        printf(" = %d\n", r);
    } else {
        printf(" fila vazia ou inválida\n");
    }
}

int main(void) {
    Fila *c1 = fila_cria();
    if (c1 == NULL) {
        return 1;
    }
    Fila *c2 = fila_cria();
    if (c2 == NULL) {
        fila_libera(c1);
        return 1;
    }

    // c1: 2 * (3 + 4) -> 2 3 4 + *
    fila_insere(c1, 2);
    fila_insere(c1, 3);
    fila_insere(c1, 4);
    fila_insere(c1, SOMA);
    fila_insere(c1, MULT);

    // c2: 2 * 3 + 4 -> 2 3 * 4 +
    fila_insere(c2, 2);
    fila_insere(c2, 3);
    fila_insere(c2, MULT);
    fila_insere(c2, 4);
    fila_insere(c2, SOMA);

    calcula("2 * (3 + 4)", c1);
    calcula("2 * 3 + 4", c2);
    fila_libera(c1);
    fila_libera(c2);
    return 0;
}
