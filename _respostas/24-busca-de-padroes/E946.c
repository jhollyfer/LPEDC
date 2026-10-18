// 0158 · KMP
// Exercício E946 · ★★☆

#include <stdio.h>
#include <string.h>

#define MAX 32

long forca_bruta(const char *t, const char *p, int *achados) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    long comp = 0;
    *achados = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) {
            comp++;
            if (t[i + j] != p[j]) {
                break;
            }
            j++;
        }
        if (j == m) {
            (*achados)++;
        }
    }
    return comp;
}

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

// conta toda comparação texto[i] com padrao[k], no while e no if
long kmp(const char *t, const char *p, int *achados) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    int pi[MAX];
    long comp = 0;
    int k = 0;
    *achados = 0;
    calcula_pi(p, m, pi);
    for (int i = 0; i < n; i++) {
        while (1) {
            comp++;                  // compara texto[i] com padrao[k]
            if (t[i] == p[k]) {
                k++;
                break;
            }
            if (k == 0) {
                break;               // não há borda menor para tentar
            }
            k = pi[k - 1];
        }
        if (k == m) {
            (*achados)++;
            k = pi[k - 1];
        }
    }
    return comp;
}

int main(void) {
    const char *texto = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaab"; // 29 'a' e um 'b'
    const char *padroes[] = {"aaaab", "baaaa", "aaaaa"};
    int a1, a2;

    for (int k = 0; k < 3; k++) {
        long fb = forca_bruta(texto, padroes[k], &a1);
        long km = kmp(texto, padroes[k], &a2);
        printf("%s: força bruta %3ld, KMP %2ld (achou %d e %d)\n",
               padroes[k], fb, km, a1, a2);
    }
    return 0;
}
