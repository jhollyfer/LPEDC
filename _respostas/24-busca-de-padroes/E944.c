// 0158 · KMP
// Exercício E944 · ★☆☆

#include <stdio.h>
#include <string.h>

#define MAX 32

void calcula_pi(const char *p, int m, int pi[]) {
    int k = 0;
    pi[0] = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) {
            k = pi[k - 1];
        }
        if (p[j] == p[k]) {
            k++;
        }
        pi[j] = k;
    }
}

int kmp(const char *texto, const char *padrao) {
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);
    int pi[MAX];
    int k = 0, total = 0;
    calcula_pi(padrao, m, pi);
    for (int i = 0; i < n; i++) {
        while (k > 0 && texto[i] != padrao[k]) {
            k = pi[k - 1];
        }
        if (texto[i] == padrao[k]) {
            k++;
        }
        if (k == m) {
            printf(" %d", i - m + 1);
            total++;
            k = pi[k - 1];           // aproveita a borda: acha as sobrepostas
        }
    }
    return total;
}

int main(void) {
    const char *lista = "ananas, banana e mais banana";
    printf("posições:");
    int t = kmp(lista, "ana");
    printf("\ntotal: %d\n", t);
    return 0;
}
