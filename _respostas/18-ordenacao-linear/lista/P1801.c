// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1801 · ★☆☆ · Counting sort passo a passo: o vetor C e a saída

#include <stdio.h>

#define N 10
#define K 5 // idades de 0 a 4

void mostra(const char *rotulo, const int v[], int n) {
    printf("%s", rotulo);
    for (int i = 0; i < n; i++) printf(" %d", v[i]);
    printf("\n");
}

int main(void) {
    int a[N] = {4, 1, 3, 4, 0, 2, 1, 4, 3, 1};
    int b[N], c[K] = {0};

    for (int i = 0; i < N; i++) c[a[i]]++; // 1) conta
    mostra("Contagem: C =", c, K);
    for (int x = 1; x < K; x++) c[x] += c[x - 1]; // 2) acumula
    mostra("Acumulado: C =", c, K);
    for (int i = N - 1; i >= 0; i--) { // 3) de trás para frente: estável
        c[a[i]]--;
        b[c[a[i]]] = a[i];
        printf("A[%d] = %d vai para B[%d] | C =", i, a[i], c[a[i]]);
        for (int x = 0; x < K; x++) printf(" %d", c[x]);
        printf("\n");
    }
    mostra("B =", b, N);
    return 0;
}
