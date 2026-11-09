// Lista · Módulo 12 · Pilhas e filas
// Exercício P1227 · ★★★ · O verificador de fórmulas com três defeitos

#include <stdbool.h>
#include <stdio.h>

char par(char fecha) {
    if (fecha == ')') {
        return '(';
    }
    if (fecha == ']') {
        return '[';
    }
    return '{';
}

bool balanceado(const char *s) {
    char pilha[100];
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            if (n == 100) {
                return false;
            }
            pilha[n++] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (n == 0 || pilha[n - 1] != par(c)) { // fechou sem ter aberto
                return false;
            }
            n--;
        }
    }
    return n == 0; // sobrou algum aberto?
}

int main(void) {
    const char *formulas[5] = {"{[()]}", "([)]", "((", "())", "a[b{c}d]e"};
    for (int i = 0; i < 5; i++) {
        printf("%s: %s\n", formulas[i], balanceado(formulas[i]) ? "ok" : "erro");
    }
    return 0;
}
