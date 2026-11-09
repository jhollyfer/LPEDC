// 0180 · Pigeonhole e chave composta
// Exercício E1078 · ★★☆

#include <stdio.h>
#include <stdlib.h>

#define MIN (-5)
#define MAX 8

typedef struct {
    char cidade[16];
    int graus;
} Leitura;

// pigeonhole do mais quente para o mais frio, estável: cada casa é uma
// fila de índices (primeiro, ultimo, prox), esvaziada da casa 8 até a -5
int ordena(Leitura *v, int n) {
    int primeiro[MAX - MIN + 1], ultimo[MAX - MIN + 1];
    int *prox = malloc((size_t)n * sizeof(int));
    Leitura *saida = malloc((size_t)n * sizeof(Leitura));
    if (prox == NULL || saida == NULL) {
        free(prox);
        free(saida);
        return -1;
    }
    for (int c = 0; c <= MAX - MIN; c++) {
        primeiro[c] = -1;
    }
    for (int i = 0; i < n; i++) {
        int c = v[i].graus - MIN; // -5 vai para a casa 0
        prox[i] = -1;
        if (primeiro[c] == -1) {
            primeiro[c] = i;
        } else {
            prox[ultimo[c]] = i;
        }
        ultimo[c] = i;
    }
    int k = 0;
    for (int c = MAX - MIN; c >= 0; c--) { // do mais quente para o mais frio
        for (int i = primeiro[c]; i != -1; i = prox[i]) {
            saida[k++] = v[i];
        }
    }
    for (int i = 0; i < n; i++) {
        v[i] = saida[i];
    }
    free(prox);
    free(saida);
    return 0;
}

int main(void) {
    Leitura v[] = {
        {"Urubici", -3}, {"Gramado", 4},   {"Curitiba", 8}, {"Sao Joaquim", -5},
        {"Lages", 4},    {"Bom Jardim", -3}, {"Canela", 4}, {"Caxias", 6},
    };
    int n = 8;
    if (ordena(v, n) != 0) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("%3d %s\n", v[i].graus, v[i].cidade);
    }
    return 0;
}
