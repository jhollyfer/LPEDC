// 0088 · Juntando tudo: a calculadora de expressões
// Exercício E523 · ★☆☆
//
// A função avalia abaixo é a etapa 2 da calculadora: ela consome uma fila
// pós-fixa (números >= 0 e operadores como códigos negativos do enum) com
// uma pilha de valores. Faça você a etapa 1, à mão: converta 2 * (3 + 4) e
// 2 * 3 + 4 para a pós-fixa e insira os itens nas filas c1 e c2 com
// fila_insere, usando SOMA e MULT para os operadores.
//
//   Saída esperada:
//   2 * (3 + 4) ->  2 3 4 + * = 14
//   2 * 3 + 4   ->  2 3 * 4 + = 10
//
// Dicas:
// 1. Os números entram na fila na mesma ordem em que aparecem na infixa.
// 2. Em 2 * (3 + 4), o "(" segura o * na pilha de operadores até o ")",
//    então o + sai primeiro. Em 2 * 3 + 4, o * sai assim que chega o +.
// 3. Resposta esperada: c1 recebe 2, 3, 4, SOMA, MULT; c2 recebe 2, 3,
//    MULT, 4, SOMA. A saída é a das duas linhas acima.
//
// Escreva sua resposta abaixo (preencha as duas filas):

#include <stdbool.h>
#include <stdio.h>
#include "fila.h"
#include "pilha.h"

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

    // c1: 2 * (3 + 4) em pós-fixa

    // c2: 2 * 3 + 4 em pós-fixa

    calcula("2 * (3 + 4)", c1);
    calcula("2 * 3 + 4", c2);
    fila_libera(c1);
    fila_libera(c2);
    return 0;
}
