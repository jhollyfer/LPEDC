// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2409 · ★☆☆ · A batida que se repete

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
    const char *batidas[] = {"tumtatumtatumta", "tumtumpa", "abcabcab", "xxxxxx", "samba"};
    for (int b = 0; b < 5; b++) {
        int m = (int)strlen(batidas[b]), pi[64];
        calcula_pi(batidas[b], m, pi);
        int periodo = m - pi[m - 1];
        printf("%-16s período %2d (\"%.*s\")", batidas[b], periodo, periodo, batidas[b]);
        if (m % periodo == 0 && periodo < m) printf(", repete %d vezes inteiras", m / periodo);
        printf("\n");
    }
    return 0;
}
