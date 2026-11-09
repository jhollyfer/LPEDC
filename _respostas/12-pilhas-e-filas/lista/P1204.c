// Lista · Módulo 12 · Pilhas e filas
// Exercício P1204 · ★☆☆ · Quão fundo vão os parênteses?

#include <stdbool.h>
#include <stdio.h>

#define CAP 100

typedef struct {
    char v[CAP];
    int n;
} Pilha;

char par_de(char fecha) {
    if (fecha == ')') {
        return '(';
    }
    if (fecha == ']') {
        return '[';
    }
    return '{';
}

int profundidade(const char *s) {
    Pilha p = {.n = 0};
    int maior = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            if (p.n == CAP) {
                return -1;
            }
            p.v[p.n++] = c;
            if (p.n > maior) {
                maior = p.n;
            }
        } else if (c == ')' || c == ']' || c == '}') {
            if (p.n == 0 || p.v[p.n - 1] != par_de(c)) {
                return -1;
            }
            p.n--;
        }
    }
    return p.n == 0 ? maior : -1;
}

int main(void) {
    const char *formulas[6] = {"(a+b)", "{[(x)]}", "(a)[b]{c}", "((1+2)*[3-(4/5)])", "([)]", "(("};
    for (int i = 0; i < 6; i++) {
        printf("%s: %d\n", formulas[i], profundidade(formulas[i]));
    }
    return 0;
}
