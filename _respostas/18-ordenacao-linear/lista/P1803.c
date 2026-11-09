// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1803 · ★☆☆ · Radix com base 100: dois dígitos por passada

#include <stdio.h>

#define N 7
#define B 100 // base: dois dígitos decimais por passada

void passada(int v[], int n, int div) {
    int c[B] = {0}, saida[N];
    for (int i = 0; i < n; i++) c[(v[i] / div) % B]++;
    for (int x = 1; x < B; x++) c[x] += c[x - 1];
    for (int i = n - 1; i >= 0; i--) saida[--c[(v[i] / div) % B]] = v[i]; // estável
    for (int i = 0; i < n; i++) v[i] = saida[i];
}

int main(void) {
    int mat[N] = {241077, 230105, 241012, 190305, 230388, 180399, 210477};

    for (int div = 1; div <= 10000; div *= B) {
        passada(mat, N, div);
        printf("div %5d:", div);
        for (int i = 0; i < N; i++) printf(" %06d", mat[i]);
        printf("\n");
    }
    return 0;
}
