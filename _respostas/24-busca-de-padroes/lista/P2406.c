// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2406 · ★☆☆ · A janela que rola pelo código de barras

#include <stdio.h>
#include <string.h>

#define Q 97

int main(void) {
    const char *codigo = "7891000315507";
    int n = (int)strlen(codigo), m = 4;

    int pot = 1; // 10^(m-1) mod Q
    for (int k = 1; k < m; k++) pot = pot * 10 % Q;

    int h = 0;
    for (int k = 0; k < m; k++) h = (h * 10 + (codigo[k] - '0')) % Q;
    for (int i = 0;; i++) {
        printf("%d: %.4s -> %2d\n", i, codigo + i, h);
        if (i + m >= n) break;
        // tira o dígito da esquerda, empurra e põe o da direita
        h = (h - (codigo[i] - '0') * pot % Q + Q) % Q;
        h = (h * 10 + (codigo[i + m] - '0')) % Q;
    }
    return 0;
}
