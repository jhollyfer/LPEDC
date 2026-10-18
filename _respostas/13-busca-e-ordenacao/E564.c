// 0094 · Merge sort
// Exercício E564 · ★★★

#include <stdio.h>
#include <stdlib.h>

// intercala e conta: quando um da DIREITA sai antes, ele forma inversão
// com todos os que ainda restam na esquerda (q - i deles)
long long intercala(int v[], int w[], int p, int q, int r) {
    long long inv = 0;
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            inv += q - i;
            w[k++] = v[j++];
        }
    }
    while (i < q) {
        w[k++] = v[i++];
    }
    while (j < r) {
        w[k++] = v[j++];
    }
    for (k = 0; k < r - p; k++) {
        v[p + k] = w[k];
    }
    return inv;
}

long long conta(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return 0;
    }
    int q = p + (r - p) / 2;
    return conta(v, w, p, q) + conta(v, w, q, r) + intercala(v, w, p, q, r);
}

long long forca_bruta(const int v[], int n) {
    long long inv = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                inv++;
            }
        }
    }
    return inv;
}

int main(void) {
    // posição, no ranking da Bia, de cada série do ranking da Ana
    int bia[] = {3, 1, 7, 2, 8, 4, 6, 5};
    int n = 8;
    int *w = malloc(n * sizeof *w);
    if (w == NULL) {
        return 1;
    }
    long long bruta = forca_bruta(bia, n);   // antes: conta() ordena o vetor
    long long rapida = conta(bia, w, 0, n);
    printf("força bruta: %lld discordâncias\n", bruta);
    printf("merge sort:  %lld discordâncias\n", rapida);
    printf("de %d pares possíveis\n", n * (n - 1) / 2);
    free(w);
    return 0;
}
