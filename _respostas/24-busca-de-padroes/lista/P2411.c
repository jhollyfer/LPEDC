// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2411 · ★★☆ · A tabela π atrasada

#include <stdio.h>
#include <string.h>

void calcula_pi(const char *p, int m, int pi[]) {
    pi[0] = 0;
    int k = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) k = pi[k - 1];
        if (p[j] == p[k]) k++;
        pi[j] = k; // o conserto: grava DEPOIS de tentar crescer a borda
    }
}

int kmp(const char *t, const char *p) {
    int n = (int)strlen(t), m = (int)strlen(p), pi[64], k = 0, achou = 0;
    calcula_pi(p, m, pi);
    printf("pi de %s:", p);
    for (int j = 0; j < m; j++) printf(" %d", pi[j]);
    printf("\n");
    for (int i = 0; i < n; i++) {
        while (k > 0 && t[i] != p[k]) k = pi[k - 1];
        if (t[i] == p[k]) k++;
        if (k == m) {
            printf("  achou em %d\n", i - m + 1);
            achou++;
            k = pi[k - 1];
        }
    }
    return achou;
}

int main(void) {
    printf("total: %d\n", kmp("tumtumtumtatumtum", "tumtum"));
    printf("total: %d\n", kmp("abababab", "abab"));
    return 0;
}
