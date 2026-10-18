// 0160 · Rabin-Karp
// Exercício E957 · ★★☆

#include <stdio.h>
#include <string.h>

int iguais(const char *t, const char *p, int m) {
    for (int j = 0; j < m; j++) {
        if (t[j] != p[j]) {
            return 0;
        }
    }
    return 1;
}

// agora o módulo é parâmetro, e a função conta ocorrências e falsos positivos
void rabin_karp(const char *t, const char *p, int q) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    int pot = 1;
    for (int j = 0; j < m - 1; j++) {
        pot = pot * 10 % q;
    }
    int hp = 0, ht = 0;
    for (int j = 0; j < m; j++) {
        hp = (hp * 10 + (p[j] - '0')) % q;
        ht = (ht * 10 + (t[j] - '0')) % q;
    }
    int achados = 0, falsos = 0;
    for (int i = 0; i <= n - m; i++) {
        if (ht == hp) {
            if (iguais(t + i, p, m)) {
                achados++;
            } else {
                falsos++;
            }
        }
        if (i < n - m) {
            ht = (ht - (t[i] - '0') * pot % q + q) % q;
            ht = (ht * 10 + (t[i + m] - '0')) % q;
        }
    }
    printf("q = %5d: %d ocorrências, %2d falsos positivos\n", q, achados, falsos);
}

int main(void) {
    const char *serie = "902620261187420263355926102026738920261049582026";
    int primos[] = {7, 13, 101, 10007};
    for (int k = 0; k < 4; k++) {
        rabin_karp(serie, "2026", primos[k]);
    }
    return 0;
}
