// Lista · Módulo 03 · Laços
// Exercício P0330 · ★★★ · O triângulo de Pascal

#include <stdio.h>

int main(void) {
    const int LINHAS = 7;

    for (int n = 0; n < LINHAS; n++) {
        for (int e = 0; e < (LINHAS - 1 - n) * 2; e++) {
            printf(" ");
        }
        int c = 1, soma = 0;
        for (int k = 0; k <= n; k++) {
            printf("%4d", c);
            soma += c;
            c = c * (n - k) / (k + 1);
        }
        printf("   (soma %d)\n", soma);
    }
    return 0;
}
