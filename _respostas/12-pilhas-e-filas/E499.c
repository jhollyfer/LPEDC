// 0084 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E499 · ★☆☆

#include <stdbool.h>
#include <stdio.h>
// Na pasta do assunto basta #include "pilha.h" (o rodar compila o pilha.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0084-pilha-aplicacoes/pilha.c"

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
    const char *posfixas[4] = {"7 3 + 2 *", "7 3 2 * +", "100 2 3 + / 4 -", "6 2 / 3 1 - *"};
    int infixas[4] = {(7 + 3) * 2, 7 + 3 * 2, 100 / (2 + 3) - 4, (6 / 2) * (3 - 1)};

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
