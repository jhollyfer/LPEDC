// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1711 · ★★☆ · A árvore de 3T(n/4) + n² contada por nível

#include <stdio.h>

long chamadas[10], custo[10];
int tamanho[10];

void trabalho(int n, int nivel) {
    chamadas[nivel]++;
    tamanho[nivel] = n;
    if (n == 1) {
        custo[nivel]++; // a folha custa 1
        return;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) custo[nivel]++; // n² unidades
    for (int k = 0; k < 3; k++) trabalho(n / 4, nivel + 1);
}

int main(void) {
    int n = 256;
    trabalho(n, 0);
    long total = 0;
    printf("nível  chamadas  tamanho  custo\n");
    for (int i = 0; i < 10 && chamadas[i]; i++) {
        printf("%5d %9ld %8d %6ld\n", i, chamadas[i], tamanho[i], custo[i]);
        total += custo[i];
    }
    printf("Total: %ld | total / n² = %.4f (limite 16/13 = %.4f)\n", total,
           (double)total / ((double)n * n), 16.0 / 13.0);
    return 0;
}
