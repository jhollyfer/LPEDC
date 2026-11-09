// Lista · Módulo 13 · Busca e ordenação
// Exercício P1321 · ★★★ · As quedas de mais da metade

#include <stdio.h>

// conta pares i < j com v[i] > 2 * v[j] e ordena v[p..r] (merge sort)
long long conta(int v[], int aux[], int p, int r) {
    if (p >= r) {
        return 0;
    }
    int q = (p + r) / 2;
    long long total = conta(v, aux, p, q) + conta(v, aux, q + 1, r);

    // as duas metades estão ordenadas: um ponteiro só anda para a frente
    int j = q + 1;
    for (int i = p; i <= q; i++) {
        while (j <= r && v[i] > 2LL * v[j]) {
            j++;
        }
        total += j - (q + 1);
    }

    // intercalação normal
    int i = p, k = p;
    j = q + 1;
    while (i <= q && j <= r) {
        aux[k++] = (v[i] <= v[j]) ? v[i++] : v[j++];
    }
    while (i <= q) {
        aux[k++] = v[i++];
    }
    while (j <= r) {
        aux[k++] = v[j++];
    }
    for (k = p; k <= r; k++) {
        v[k] = aux[k];
    }
    return total;
}

long long forca_bruta(const int v[], int n) {
    long long total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > 2LL * v[j]) {
                total++;
            }
        }
    }
    return total;
}

int main(void) {
    int precos[] = {40, 15, 22, 90, 10, 35, 8, 50};
    int n = 8;
    int aux[8];

    printf("força bruta: %lld pares\n", forca_bruta(precos, n));
    printf("merge sort: %lld pares\n", conta(precos, aux, 0, n - 1));
    printf("ordenado:");
    for (int i = 0; i < n; i++) {
        printf(" %d", precos[i]);
    }
    printf("\n");
    return 0;
}
