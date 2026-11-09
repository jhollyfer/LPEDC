// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1814 · ★★☆ · Mediana: quickselect contra ordenar tudo

#include <stdio.h>
#include <string.h>

#define N 1001

unsigned semente = 13;
long comparacoes;
int aux[N];

int sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente >> 16) % 240); // minutos de espera
}

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int quickselect(int v[], int n, int pos) {
    int ini = 0, fim = n - 1;
    for (;;) {
        int pivo = v[fim], i = ini;
        for (int j = ini; j < fim; j++) {
            comparacoes++;
            if (v[j] < pivo) troca(&v[i++], &v[j]);
        }
        troca(&v[i], &v[fim]);
        if (i == pos) return v[i];
        if (pos < i) fim = i - 1;
        else ini = i + 1;
    }
}

void merge_sort(int v[], int ini, int fim) {
    if (ini >= fim) return;
    int meio = (ini + fim) / 2;
    merge_sort(v, ini, meio);
    merge_sort(v, meio + 1, fim);
    int i = ini, j = meio + 1, k = 0;
    while (i <= meio && j <= fim) {
        comparacoes++;
        aux[k++] = v[i] <= v[j] ? v[i++] : v[j++];
    }
    while (i <= meio) aux[k++] = v[i++];
    while (j <= fim) aux[k++] = v[j++];
    memcpy(v + ini, aux, k * sizeof(int));
}

void compara(const char *rotulo, const int tempo[]) {
    int v[N];
    memcpy(v, tempo, sizeof v);
    comparacoes = 0;
    int m1 = quickselect(v, N, N / 2);
    long c1 = comparacoes;
    memcpy(v, tempo, sizeof v);
    comparacoes = 0;
    merge_sort(v, 0, N - 1);
    printf("%s:\n  quickselect: mediana %3d, %6ld comparações\n", rotulo, m1, c1);
    printf("  merge sort:  mediana %3d, %6ld comparações\n", v[N / 2], comparacoes);
}

int main(void) {
    int tempo[N];
    for (int i = 0; i < N; i++) tempo[i] = sorteia();

    compara("sorteado", tempo);
    merge_sort(tempo, 0, N - 1); // agora o vetor está ordenado
    compara("ordenado", tempo);
    return 0;
}
