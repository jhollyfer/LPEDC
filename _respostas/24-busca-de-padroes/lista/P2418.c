// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2418 · ★★☆ · O KMP passo a passo

#include <stdio.h>
#include <string.h>

void calcula_pi(const char *p, int m, int pi[]) {
    pi[0] = 0;
    int k = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) k = pi[k - 1];
        if (p[j] == p[k]) k++;
        pi[j] = k;
    }
}

int main(void) {
    const char *t = "abaababcabab", *p = "abab";
    int n = (int)strlen(t), m = (int)strlen(p), pi[16], k = 0;
    calcula_pi(p, m, pi);
    printf(" i t[i] k antes k depois\n");
    for (int i = 0; i < n; i++) {
        int antes = k, recuos[16], r = 0;
        while (k > 0 && t[i] != p[k]) {
            k = pi[k - 1];
            recuos[r++] = k;
        }
        if (t[i] == p[k]) k++;
        printf("%2d   %c %7d %8d", i, t[i], antes, k);
        if (r > 0) {
            printf("  recuou para");
            for (int x = 0; x < r; x++) printf(" %d", recuos[x]);
        }
        if (k == m) {
            printf("  <- achou em %d", i - m + 1);
            k = pi[k - 1];
        }
        printf("\n");
    }
    return 0;
}
