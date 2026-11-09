// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1817 · ★★☆ · Conserte o radix sort das encomendas

#include <stdio.h>

#define N 8

void passada(int v[], int n, int div) {
    int c[10] = {0}, saida[N];
    for (int i = 0; i < n; i++) c[(v[i] / div) % 10]++;
    for (int d = 1; d < 10; d++) c[d] += c[d - 1];
    for (int i = n - 1; i >= 0; i--) saida[--c[(v[i] / div) % 10]] = v[i]; // erro 2: de trás para frente
    for (int i = 0; i < n; i++) v[i] = saida[i];
}

int main(void) {
    int peso[N] = {870, 12400, 45, 3005, 120, 9800, 340, 1250};

    int maior = peso[0];
    for (int i = 1; i < N; i++)
        if (peso[i] > maior) maior = peso[i];
    int digitos = 0;
    for (int x = maior; x > 0; x /= 10) digitos++; // erro 1: os dígitos do MAIOR
    for (int k = 0, div = 1; k < digitos; k++, div *= 10) passada(peso, N, div);

    for (int i = 0; i < N; i++) printf("%d ", peso[i]);
    printf("\n");
    return 0;
}
