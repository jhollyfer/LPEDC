// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2403 · ★☆☆ · A borda de cada prefixo

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

void mostra(const char *p) {
    int m = (int)strlen(p), pi[64];
    calcula_pi(p, m, pi);
    printf("%s\n", p);
    for (int j = 0; j < m; j++) {
        // a borda é o prefixo de tamanho pi[j], que também termina em j
        printf("  %2d %-*.*s pi = %d", j, m, j + 1, p, pi[j]);
        if (pi[j] > 0) printf("  borda \"%.*s\"", pi[j], p);
        printf("\n");
    }
}

int main(void) {
    mostra("tatuta");
    mostra("aabaaab");
    return 0;
}
