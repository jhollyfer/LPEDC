// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2420 · ★★☆ · Quantos trechos diferentes no DNA

#include <stdio.h>
#include <string.h>

#define B 4
#define Q 101
#define MAXN 64

int valor(char c) {
    return c == 'A' ? 0 : c == 'C' ? 1 : c == 'G' ? 2 : 3;
}

void distintos(const char *dna, int m) {
    int n = (int)strlen(dna);
    int pot = 1;
    for (int k = 1; k < m; k++) pot = pot * B % Q;
    int h = 0;
    for (int k = 0; k < m; k++) h = (h * B + valor(dna[k])) % Q;

    int hash_de[MAXN], inicio[MAXN], n_dist = 0, conferencias = 0;
    printf("m = %d:", m);
    for (int i = 0; i + m <= n; i++) {
        int novo = 1;
        for (int d = 0; d < n_dist && novo; d++)
            if (hash_de[d] == h) {
                conferencias++;
                if (strncmp(dna + inicio[d], dna + i, m) == 0) novo = 0;
            }
        if (novo) {
            hash_de[n_dist] = h;
            inicio[n_dist++] = i;
            printf(" %.*s", m, dna + i);
        }
        if (i + m < n) {
            h = (h - valor(dna[i]) * pot % Q + Q) % Q;
            h = (h * B + valor(dna[i + m])) % Q;
        }
    }
    printf("\n  %d diferentes em %d janelas, %d conferências\n", n_dist, n - m + 1, conferencias);
}

int main(void) {
    const char *dna = "ACGTACGTTACGAACGT";
    distintos(dna, 3);
    distintos(dna, 4);
    return 0;
}
