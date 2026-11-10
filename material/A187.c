// A187 · Merge sort sem recursão, de baixo para cima

#include <stdio.h>
#include <stdlib.h>

// junta v[p..q-1] e v[q..r-1], já ordenados, usando w como rascunho
void intercala(int v[], int w[], int p, int q, int r) {
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        w[k++] = (v[i] <= v[j]) ? v[i++] : v[j++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (k = 0; k < r - p; k++) {
        v[p + k] = w[k];
    }
}

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) printf(" %d", v[i]);
    printf("\n");
}

int main(void) {
    int tempos[] = {41, 17, 33, 8, 52, 26, 12};   // 7: não é potência de 2
    int n = 7;
    int *w = malloc(n * sizeof *w);
    if (w == NULL) {
        return 1;
    }

    printf("início:     ");
    mostra(tempos, n);
    // blocos de 1 viram blocos de 2, que viram de 4, que viram de 8...
    for (int largura = 1; largura < n; largura *= 2) {
        for (int p = 0; p < n - largura; p += 2 * largura) {
            int q = p + largura;
            int r = p + 2 * largura;
            if (r > n) {
                r = n;                  // o último bloco pode ser mais curto
            }
            intercala(tempos, w, p, q, r);
        }
        printf("blocos de %d:", 2 * largura);
        mostra(tempos, n);
    }
    free(w);
    return 0;
}
// Saída (o 12 fica sozinho até a última rodada; 3 rodadas = log2 de 8):
// início:      41 17 33 8 52 26 12
// blocos de 2: 17 41 8 33 26 52 12
// blocos de 4: 8 17 33 41 12 26 52
// blocos de 8: 8 12 17 26 33 41 52
