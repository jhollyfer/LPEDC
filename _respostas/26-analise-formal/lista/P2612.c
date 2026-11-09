// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2612 · ★★☆ · Caso médio com quem não está

#include <stdio.h>

#define N 100

int comparacoes = 0;

int busca(const int v[], int n, int x) {
    for (int i = 0; i < n; i++) {
        comparacoes++;
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int objeto[N];
    for (int i = 0; i < N; i++) {
        objeto[i] = 5000 + 13 * i;       // códigos dos objetos
    }
    long soma = 0;
    for (int i = 0; i < N; i++) {
        comparacoes = 0;
        busca(objeto, N, objeto[i]);
        soma += comparacoes;
    }
    double media_presente = (double)soma / N;
    comparacoes = 0;
    busca(objeto, N, -1);
    int ausente = comparacoes;
    double media = 0.75 * media_presente + 0.25 * ausente;
    printf("presentes: média %.2f, ausente: %d\n", media_presente, ausente);
    printf("caso médio medido: %.3f\n", media);
    printf("fórmula:           %.3f\n", 0.75 * (N + 1) / 2.0 + 0.25 * N);
    return 0;
}
