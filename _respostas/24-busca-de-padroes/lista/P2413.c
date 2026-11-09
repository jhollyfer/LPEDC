// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2413 · ★★☆ · O colar girado

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

// mostra todo k tal que girar a k casas para a esquerda dá b
int giros(const char *a, const char *b) {
    int n = (int)strlen(a);
    if ((int)strlen(b) != n) return 0;
    char dobro[128];
    snprintf(dobro, sizeof dobro, "%s%s", a, a);
    int pi[64], k = 0, achou = 0;
    calcula_pi(b, n, pi);
    for (int i = 0; i < 2 * n - 1; i++) { // ocorrências que começam antes de n
        while (k > 0 && dobro[i] != b[k]) k = pi[k - 1];
        if (dobro[i] == b[k]) k++;
        if (k == n) {
            printf(" %d", i - n + 1);
            achou++;
            k = pi[k - 1];
        }
    }
    return achou;
}

int main(void) {
    const char *pares[][2] = {{"azulverdeazulverde", "verdeazulverdeazul"},
                              {"amarelopreto", "pretoamarelo"},
                              {"rosabranco", "brancoroxa"},
                              {"ouroouroouro", "ouroouroouro"}};
    for (int k = 0; k < 4; k++) {
        printf("%s -> %s:", pares[k][0], pares[k][1]);
        int g = giros(pares[k][0], pares[k][1]);
        printf("%s (%d giro(s))\n", g ? "" : " não é rotação", g);
    }
    return 0;
}
