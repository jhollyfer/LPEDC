// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2421 · ★★★ · A senha do cofre

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

// maior trecho que é prefixo, sufixo e aparece também no meio
int senha(const char *s) {
    int m = (int)strlen(s), pi[128];
    calcula_pi(s, m, pi);
    int meio = 0; // maior borda de um prefixo que não é o texto inteiro
    for (int j = 1; j < m - 1; j++)
        if (pi[j] > meio) meio = pi[j];
    int L = pi[m - 1];
    while (L > 0 && L > meio) L = pi[L - 1]; // desce pela cadeia de bordas
    return L;
}

int main(void) {
    const char *dicas[] = {"fixprefixsuffix", "abcdabc", "aaaa", "papapapa", "araraquara"};
    for (int k = 0; k < 5; k++) {
        int L = senha(dicas[k]);
        if (L == 0) printf("%-16s sem senha\n", dicas[k]);
        else printf("%-16s senha \"%.*s\"\n", dicas[k], L, dicas[k]);
    }
    return 0;
}
