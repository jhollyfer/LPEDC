// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1820 · ★★☆ · Counting sort custa n + k: quando o k atrapalha

#include <stdio.h>
#include <string.h>

#define N 1000
#define MAXK 1000000

unsigned semente = 5;
long operacoes;
int aux[N];

int sorteia(int k) {
    semente = semente * 1103515245u + 12345u;
    unsigned x = (semente >> 16) << 15;
    semente = semente * 1103515245u + 12345u;
    return (int)((x | (semente >> 17)) % (unsigned)k);
}

void counting(const int v[], int saida[], int n, int k) {
    static int c[MAXK];
    for (int x = 0; x < k; x++) c[x] = 0;
    for (int i = 0; i < n; i++) c[v[i]]++;
    for (int x = 1; x < k; x++) c[x] += c[x - 1];
    for (int i = n - 1; i >= 0; i--) saida[--c[v[i]]] = v[i];
    operacoes += 2L * n + k;
}

void merge_sort(int v[], int ini, int fim) {
    if (ini >= fim) return;
    int meio = (ini + fim) / 2;
    merge_sort(v, ini, meio);
    merge_sort(v, meio + 1, fim);
    int i = ini, j = meio + 1, t = 0;
    while (i <= meio && j <= fim) {
        operacoes++;
        aux[t++] = v[i] <= v[j] ? v[i++] : v[j++];
    }
    while (i <= meio) aux[t++] = v[i++];
    while (j <= fim) aux[t++] = v[j++];
    memcpy(v + ini, aux, t * sizeof(int));
}

int main(void) {
    int ks[] = {10, 1000, 100000, 1000000};
    printf("      k  counting   merge  vencedor  iguais\n");
    for (int q = 0; q < 4; q++) {
        int k = ks[q], v[N], a[N], b[N];
        for (int i = 0; i < N; i++) v[i] = sorteia(k);
        operacoes = 0;
        counting(v, a, N, k);
        long oc = operacoes;
        memcpy(b, v, sizeof b);
        operacoes = 0;
        merge_sort(b, 0, N - 1);
        printf("%7d %9ld %7ld  %-8s  %s\n", k, oc, operacoes, oc < operacoes ? "counting" : "merge",
               memcmp(a, b, sizeof a) == 0 ? "sim" : "não");
    }
    return 0;
}
