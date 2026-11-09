// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1818 · ★★☆ · Onde pôr o depósito: a mediana ponderada

#include <stdio.h>
#include <stdlib.h>

#define N 7
#define KM 31

typedef struct {
    const char *nome;
    int km, entregas;
} Loja;

long custo(const Loja v[], int n, int p) {
    long total = 0;
    for (int i = 0; i < n; i++) total += (long)v[i].entregas * abs(v[i].km - p);
    return total;
}

int main(void) {
    Loja v[N] = {{"Taruma", 26, 11}, {"Lago Azul", 7, 2}, {"Santa Etelvina", 18, 1},
                 {"Cidade Nova", 2, 5}, {"Colonia", 21, 2}, {"Monte das Oliveiras", 12, 1},
                 {"Novo Israel", 5, 1}};
    Loja ord[N];
    int c[KM] = {0};

    for (int i = 0; i < N; i++) c[v[i].km]++;
    for (int x = 1; x < KM; x++) c[x] += c[x - 1];
    for (int i = N - 1; i >= 0; i--) ord[--c[v[i].km]] = v[i];

    int total = 0;
    for (int i = 0; i < N; i++) total += ord[i].entregas;
    int acumulado = 0, mediana_p = -1;
    for (int i = 0; i < N && mediana_p == -1; i++) {
        acumulado += ord[i].entregas;
        printf("km %2d %-20s peso %2d, acumulado %2d de %d\n", ord[i].km, ord[i].nome, ord[i].entregas,
               acumulado, total);
        if (2 * acumulado >= total) mediana_p = ord[i].km; // chegou à metade
    }

    int mediana_s = ord[N / 2].km;
    long soma = 0;
    for (int i = 0; i < N; i++) soma += (long)v[i].km * v[i].entregas;
    int media = (int)((2 * soma + total) / (2 * total)); // arredondada
    int melhor = 0;
    for (int p = 1; p < KM; p++)
        if (custo(v, N, p) < custo(v, N, melhor)) melhor = p;

    printf("Mediana ponderada: km %2d, custo %ld\n", mediana_p, custo(v, N, mediana_p));
    printf("Força bruta:       km %2d, custo %ld\n", melhor, custo(v, N, melhor));
    printf("Mediana simples:   km %2d, custo %ld\n", mediana_s, custo(v, N, mediana_s));
    printf("Média ponderada:   km %2d, custo %ld\n", media, custo(v, N, media));
    return 0;
}
