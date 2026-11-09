// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1002 · ★☆☆ · A planilha inteira contra a diagonal

#include <stdio.h>

int soma_tudo(int m[8][8], int n, int *somas) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s += m[i][j];
            (*somas)++;
        }
    }
    return s;
}

int soma_diagonal(int m[8][8], int n, int *somas) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += m[i][i];
        (*somas)++;
    }
    return s;
}

int main(void) {
    int m[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            m[i][j] = i + j;
        }
    }
    for (int n = 2; n <= 8; n *= 2) {
        int st = 0, sd = 0;
        int tudo = soma_tudo(m, n, &st);
        int diag = soma_diagonal(m, n, &sd);
        printf("n = %d: soma %d (%d somas), diagonal %d (%d somas)\n", n, tudo, st, diag, sd);
    }
    return 0;
}
