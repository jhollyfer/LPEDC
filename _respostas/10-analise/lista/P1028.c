// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1028 · ★★★ · Quantos times de futsal? Recursão contra tabela

#include <stdio.h>

long comb_rec(int n, int k, long *chamadas) {
    (*chamadas)++;
    if (k == 0 || k == n) {
        return 1;
    }
    return comb_rec(n - 1, k - 1, chamadas) + comb_rec(n - 1, k, chamadas);
}

long comb_tabela(int n, int k, long *somas) {
    long t[21][21];
    *somas = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i && j <= k; j++) {
            if (j == 0 || j == i) {
                t[i][j] = 1;
            } else {
                t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
                (*somas)++;
            }
        }
    }
    return t[n][k];
}

int main(void) {
    int casos[2][2] = {{12, 5}, {20, 10}};
    for (int c = 0; c < 2; c++) {
        int n = casos[c][0], k = casos[c][1];
        long chamadas = 0, somas;
        long a = comb_rec(n, k, &chamadas);
        long b = comb_tabela(n, k, &somas);
        if (a != b) {
            printf("As duas discordam!\n");
        }
        printf("C(%d, %d) = %ld | recursão: %ld chamadas | tabela: %ld somas\n", n, k, a, chamadas, somas);
    }
    return 0;
}
