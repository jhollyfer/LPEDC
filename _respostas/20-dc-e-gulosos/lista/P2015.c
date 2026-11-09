// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2015 · ★★☆ · Huffman sem heap, para poucos símbolos

#include <stdio.h>

#define F 6

typedef struct {
    int freq, esq, dir, usado;
} No;

No no[2 * F];
int tam[F];

int menor_livre(int n) {
    int m = -1;
    for (int i = 0; i < n; i++) {
        if (!no[i].usado && (m < 0 || no[i].freq < no[m].freq)) {
            m = i;
        }
    }
    no[m].usado = 1;
    return m;
}

void prof(int i, int d) {
    if (no[i].esq < 0) {
        tam[i] = d;
        return;
    }
    prof(no[i].esq, d + 1);
    prof(no[i].dir, d + 1);
}

int main(void) {
    const char letra[F] = {'A', 'E', 'M', 'N', 'O', 'S'};
    const int freq[F] = {30, 20, 5, 10, 25, 10};
    int n = F;
    for (int i = 0; i < F; i++) {
        no[i] = (No){freq[i], -1, -1, 0};
    }
    while (n < 2 * F - 1) {
        int a = menor_livre(n);
        int b = menor_livre(n);
        no[n] = (No){no[a].freq + no[b].freq, a, b, 0};
        n++;
    }
    prof(n - 1, 0);
    int bits = 0;
    for (int i = 0; i < F; i++) {
        printf("%c: freq %2d, código de %d bits\n", letra[i], freq[i], tam[i]);
        bits += freq[i] * tam[i];
    }
    printf("Total: %d bits (código fixo: %d)\n", bits, 3 * 100);
    return 0;
}
