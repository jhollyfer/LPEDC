// 0072 · Notação O: como o custo cresce
// Exercício E432 · ★★★

#include <stdio.h>

long passos = 0;

int tamanho(const char *s) {
    int t = 0;
    while (s[t] != '\0') {
        passos++;
        t++;
    }
    return t;
}

int conta_vogais(const char *texto) {
    int vogais = 0;
    int n = tamanho(texto); // mede uma vez só
    for (int i = 0; i < n; i++) {
        char c = texto[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vogais++;
        }
    }
    return vogais;
}

int main(void) {
    static char texto[4001];
    int tamanhos[3] = {1000, 2000, 4000};
    long anterior = 0;

    for (int k = 0; k < 3; k++) {
        int n = tamanhos[k];
        for (int i = 0; i < n; i++) {
            texto[i] = "abcde"[i % 5];
        }
        texto[n] = '\0';
        passos = 0;
        int v = conta_vogais(texto);
        printf("n = %d: %d vogais, %ld passos", n, v, passos);
        if (k > 0) {
            printf(", razão %.2f", (double)passos / anterior);
        }
        printf("\n");
        anterior = passos;
    }
    return 0;
}
