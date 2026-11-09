// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2430 · ★★★ · A roda da fortuna

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

// ocorrências de p no texto circular t: a busca passa do fim e volta ao começo
int circular(const char *t, const char *p) {
    int n = (int)strlen(t), m = (int)strlen(p), pi[64], k = 0, achou = 0;
    if (m > n) return 0;
    calcula_pi(p, m, pi);
    for (int i = 0; i < n + m - 1; i++) {
        char c = t[i % n]; // sem montar t + t: o índice dá a volta
        while (k > 0 && c != p[k]) k = pi[k - 1];
        if (c == p[k]) k++;
        if (k == m) {
            int ini = (i - m + 1) % n;
            printf(" %d%s", ini, ini + m > n ? "*" : "");
            achou++;
            k = pi[k - 1];
        }
    }
    return achou;
}

int main(void) {
    const char *roda = "abracadabra";
    const char *busca[] = {"abra", "raab", "aabr", "dabraabr", "aa"};
    for (int k = 0; k < 5; k++) {
        printf("%s:", busca[k]);
        int n = circular(roda, busca[k]);
        printf(" (%d)\n", n);
    }
    return 0;
}
