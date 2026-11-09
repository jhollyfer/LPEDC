// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2424 · ★★★ · O SOS que some

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

int kmp(const char *t, const char *p) {
    int n = (int)strlen(t), m = (int)strlen(p), pi[64], k = 0, achou = 0;
    calcula_pi(p, m, pi);
    for (int i = 0; i < n; i++) {
        while (k > 0 && t[i] != p[k]) k = pi[k - 1];
        if (t[i] == p[k]) k++;
        if (k == m) {
            printf(" %d", i - m + 1);
            achou++;
            k = pi[k - 1]; // o conserto: reaproveita a borda do que já casou
        }
    }
    return achou;
}

int main(void) {
    const char *sinais[] = {"sososos", "xsosxsososx", "ososo"};
    for (int s = 0; s < 3; s++) {
        printf("%s:", sinais[s]);
        int n = kmp(sinais[s], "sos");
        printf(" (%d)\n", n);
    }
    printf("aaaaa:");
    printf(" (%d)\n", kmp("aaaaa", "aa"));
    return 0;
}
