// Lista · Módulo 12 · Pilhas e filas
// Exercício P1215 · ★★☆ · Avaliar a notação PREfixa

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int avalia_prefixa(const char *s, int *resultado) {
    int pilha[100], n = 0;
    for (int i = (int) strlen(s) - 1; i >= 0; i--) {
        char c = s[i];
        if (c == ' ') {
            continue;
        }
        if (isdigit((unsigned char) c)) {
            pilha[n++] = c - '0';
            continue;
        }
        if (n < 2) {
            return 0; // faltou operando
        }
        int a = pilha[--n]; // o primeiro que sai é o da ESQUERDA
        int b = pilha[--n];
        int r;
        if (c == '+') {
            r = a + b;
        } else if (c == '-') {
            r = a - b;
        } else if (c == '*') {
            r = a * b;
        } else if (c == '/' && b != 0) {
            r = a / b;
        } else {
            return 0;
        }
        pilha[n++] = r;
    }
    if (n != 1) {
        return 0;
    }
    *resultado = pilha[0];
    return 1;
}

int main(void) {
    const char *exprs[6] = {"+ 9 * 2 3", "- * 5 6 / 8 2", "* + 1 2 + 3 4", "- 8 3", "+ 1", "/ 7 0"};
    for (int i = 0; i < 6; i++) {
        int r;
        if (avalia_prefixa(exprs[i], &r)) {
            printf("%s = %d\n", exprs[i], r);
        } else {
            printf("%s: inválida\n", exprs[i]);
        }
    }
    return 0;
}
