// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2625 · ★★★ · Total alocado contra pico de memória

#include <stdio.h>
#include <stdlib.h>

size_t total = 0, vivos = 0, pico = 0;

void intercala(int v[], int ini, int meio, int fim) {
    int n = fim - ini;
    int *aux = malloc(n * sizeof(int));
    if (aux == NULL) {
        return;
    }
    total += n * sizeof(int);
    vivos += n * sizeof(int);
    if (vivos > pico) {
        pico = vivos;
    }
    int i = ini, j = meio, k = 0;
    while (i < meio || j < fim) {
        if (j >= fim || (i < meio && v[i] <= v[j])) {
            aux[k++] = v[i++];
        } else {
            aux[k++] = v[j++];
        }
    }
    for (k = 0; k < n; k++) {
        v[ini + k] = aux[k];
    }
    free(aux);
    vivos -= n * sizeof(int);
}

void ordena(int v[], int ini, int fim) {
    if (fim - ini > 1) {
        int meio = ini + (fim - ini) / 2;
        ordena(v, ini, meio);
        ordena(v, meio, fim);
        intercala(v, ini, meio, fim);
    }
}

int main(void) {
    static int v[4096];
    int ns[] = {1024, 4096};
    for (int a = 0; a < 2; a++) {
        int n = ns[a];
        for (int i = 0; i < n; i++) {
            v[i] = n - i;
        }
        total = vivos = pico = 0;
        ordena(v, 0, n);
        printf("n = %4d: total %6zu bytes, pico %5zu bytes, vivos no fim %zu\n", n, total, pico, vivos);
    }
    return 0;
}
