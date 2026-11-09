// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1720 · ★★☆ · Quatro ordenações contando comparações

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 2000

unsigned semente;
long comparacoes;
int aux[MAXN];

int sorteia(void) { // gerador congruencial: sempre a mesma sequência
    semente = semente * 1103515245u + 12345u;
    return (int)((semente >> 16) % 100000);
}

int menor(int a, int b) {
    comparacoes++;
    return a < b;
}

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insertion(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int x = v[i], j = i - 1;
        while (j >= 0 && menor(x, v[j])) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

void merge(int v[], int ini, int fim) {
    if (ini >= fim) return;
    int meio = (ini + fim) / 2;
    merge(v, ini, meio);
    merge(v, meio + 1, fim);
    int i = ini, j = meio + 1, k = 0;
    while (i <= meio && j <= fim) aux[k++] = menor(v[j], v[i]) ? v[j++] : v[i++];
    while (i <= meio) aux[k++] = v[i++];
    while (j <= fim) aux[k++] = v[j++];
    memcpy(v + ini, aux, k * sizeof(int));
}

void desce(int v[], int n, int i) {
    for (;;) {
        int maior = i, e = 2 * i + 1, d = 2 * i + 2;
        if (e < n && menor(v[maior], v[e])) maior = e;
        if (d < n && menor(v[maior], v[d])) maior = d;
        if (maior == i) return;
        troca(&v[i], &v[maior]);
        i = maior;
    }
}

void heapsort(int v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) desce(v, n, i);
    for (int fim = n - 1; fim > 0; fim--) {
        troca(&v[0], &v[fim]);
        desce(v, fim, 0);
    }
}

void quick(int v[], int ini, int fim) {
    if (ini >= fim) return;
    int pivo = v[fim], i = ini;
    for (int j = ini; j < fim; j++)
        if (menor(v[j], pivo)) troca(&v[i++], &v[j]);
    troca(&v[i], &v[fim]);
    quick(v, ini, i - 1);
    quick(v, i + 1, fim);
}

int ordenado(const int v[], int n) {
    for (int i = 1; i < n; i++)
        if (v[i - 1] > v[i]) return 0;
    return 1;
}

long mede(int qual, const int original[], int n, int *ok) {
    static int v[MAXN];
    memcpy(v, original, n * sizeof(int));
    comparacoes = 0;
    if (qual == 0) insertion(v, n);
    else if (qual == 1) merge(v, 0, n - 1);
    else if (qual == 2) heapsort(v, n);
    else quick(v, 0, n - 1);
    *ok = *ok && ordenado(v, n);
    return comparacoes;
}

int main(void) {
    int original[MAXN];
    semente = 2024;
    for (int i = 0; i < MAXN; i++) original[i] = sorteia(); // preço em centavos

    const char *nomes[] = {"insertion", "merge", "heapsort", "quicksort"};
    int ok = 1;
    printf("%-10s %9s %9s  razão\n", "", "n = 1000", "n = 2000");
    for (int q = 0; q < 4; q++) {
        long c1 = mede(q, original, 1000, &ok), c2 = mede(q, original, 2000, &ok);
        printf("%-10s %9ld %9ld  %5.2f\n", nomes[q], c1, c2, (double)c2 / c1);
    }
    printf("%-10s %9d %9d  %5.2f\n", "n²/4", 1000 * 1000 / 4, 2000 * 2000 / 4, 4.0);
    double a = 1000 * log2(1000), b = 2000 * log2(2000);
    printf("%-10s %9.0f %9.0f  %5.2f\n", "n lg n", a, b, b / a);
    printf("Todos ordenados: %s\n", ok ? "sim" : "não");
    return 0;
}
