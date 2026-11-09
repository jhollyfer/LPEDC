// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1812 · ★★☆ · Radix LSD mostrando o vetor C de cada passada

#include <stdio.h>

#define N 8

void passada(int v[], int n, int div) {
    int c[10] = {0}, saida[N];
    printf("dígitos:");
    for (int i = 0; i < n; i++) {
        printf(" %d", (v[i] / div) % 10);
        c[(v[i] / div) % 10]++;
    }
    for (int d = 1; d < 10; d++) c[d] += c[d - 1];
    printf("\nC acumulado:");
    for (int d = 0; d < 10; d++) printf(" %d", c[d]);
    for (int i = n - 1; i >= 0; i--) saida[--c[(v[i] / div) % 10]] = v[i]; // estável
    for (int i = 0; i < n; i++) v[i] = saida[i];
    printf("\nvetor:");
    for (int i = 0; i < n; i++) printf(" %d", v[i]);
    printf("\n");
}

int main(void) {
    int cod[N] = {465, 331, 902, 747, 283, 540, 615, 801};

    for (int div = 1; div <= 100; div *= 10) {
        printf("Passada div = %d\n", div);
        passada(cod, N, div);
    }
    return 0;
}
