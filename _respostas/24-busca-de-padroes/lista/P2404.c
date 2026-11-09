// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2404 · ★☆☆ · Onde aparece o CEP

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

int kmp_primeira(const char *t, const char *p, int *comparacoes) {
    int n = (int)strlen(t), m = (int)strlen(p), pi[64];
    calcula_pi(p, m, pi);
    *comparacoes = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (;;) { // compara t[i] com p[k]; se errar, recua pela tabela
            (*comparacoes)++;
            if (t[i] == p[k]) {
                k++;
                break;
            }
            if (k == 0) break;
            k = pi[k - 1];
        }
        if (k == m) return i - m + 1;
    }
    return -1;
}

int main(void) {
    const char *msg = "entregar no CEP 69060-000; se fechado, 69060-001 ou 69061-000";
    const char *ceps[] = {"69060-001", "69061-000", "69000-000"};
    for (int c = 0; c < 3; c++) {
        int comp;
        int pos = kmp_primeira(msg, ceps[c], &comp);
        printf("%s: posição %d, %d comparações\n", ceps[c], pos, comp);
    }
    return 0;
}
