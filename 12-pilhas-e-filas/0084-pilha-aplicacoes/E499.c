// 0084 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E499 · ★☆☆
//
// A função avalia abaixo já calcula uma expressão pós-fixa. Falta o resto:
// preencha o vetor posfixas com as expressões a), b) e c) traduzidas para a
// pós-fixa (a d já está pronta) e o vetor infixas com a mesma conta escrita
// direto em C, para o programa conferir uma com a outra.
//
//   a) (7 + 3) * 2
//   b) 7 + 3 * 2
//   c) 100 / (2 + 3) - 4
//   d) 6 2 / 3 1 - *        (já em pós-fixa; a infixa é (6 / 2) * (3 - 1))
//
//   Saída esperada:
//   7 3 + 2 * = 20 (em C: 20) confere
//   7 3 2 * + = 13 (em C: 13) confere
//   100 2 3 + / 4 - = 16 (em C: 16) confere
//   6 2 / 3 1 - * = 6 (em C: 6) confere
//
// Dicas:
// 1. Os números aparecem na mesma ordem nas duas notações; só os
//    operadores mudam de lugar.
// 2. Na b, a multiplicação acontece primeiro, então o * aparece antes do +.
// 3. Em infixas, escreva a conta mesmo: {(7 + 3) * 2, ...}. O compilador
//    calcula.
// 4. Resposta esperada: as quatro linhas acima.
//
// Escreva sua resposta abaixo (preencha os dois vetores):

#include <stdbool.h>
#include <stdio.h>
#include "pilha.h"

// números inteiros não negativos separados por espaço e + - * /
bool avalia(const char *expr, int *resultado) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return false;
    }
    bool ok = true;
    for (int i = 0; expr[i] != '\0' && ok; i++) {
        char c = expr[i];
        if (c >= '0' && c <= '9') {
            int numero = 0;
            for (; expr[i] >= '0' && expr[i] <= '9'; i++) {
                numero = numero * 10 + (expr[i] - '0');
            }
            i--;
            pilha_empilha(p, numero);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int a, b;
            if (!pilha_desempilha(p, &b) || !pilha_desempilha(p, &a) || (c == '/' && b == 0)) {
                ok = false;
            } else {
                pilha_empilha(p, c == '+' ? a + b : c == '-' ? a - b : c == '*' ? a * b : a / b);
            }
        }
    }
    if (ok && (!pilha_desempilha(p, resultado) || !pilha_vazia(p))) {
        ok = false;
    }
    pilha_libera(p);
    return ok;
}

int main(void) {
    const char *posfixas[4] = {"", "", "", "6 2 / 3 1 - *"};
    int infixas[4] = {0, 0, 0, (6 / 2) * (3 - 1)};

    for (int i = 0; i < 4; i++) {
        int r;
        if (avalia(posfixas[i], &r)) {
            printf("%s = %d (em C: %d) %s\n", posfixas[i], r, infixas[i], r == infixas[i] ? "confere" : "NÃO confere");
        } else {
            printf("%c) expressão pós-fixa inválida ou vazia\n", 'a' + i);
        }
    }
    return 0;
}
