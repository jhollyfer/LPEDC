// 0126 · Permutações
// Exercício E753 · ★★☆

#include <stdio.h>

#define LOCAIS 5
#define N 4 // bairros

const char *nomes[LOCAIS] = {"Pizzaria", "Centro", "Jardim", "Lagoa", "Vila"};
const int dist[LOCAIS][LOCAIS] = {
    {0, 9, 4, 2, 4},
    {9, 0, 4, 4, 9},
    {4, 4, 0, 3, 2},
    {2, 4, 3, 0, 7},
    {4, 9, 2, 7, 0},
};

int melhor = -1;
int melhor_rota[N];
int testadas = 0;

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void rotas(int v[], int i) {
    if (i == N) {
        int km = dist[0][v[0]] + dist[v[N - 1]][0];
        for (int k = 0; k < N - 1; k++) {
            km += dist[v[k]][v[k + 1]];
        }
        testadas++;
        if (melhor < 0 || km < melhor) {
            melhor = km;
            for (int k = 0; k < N; k++) {
                melhor_rota[k] = v[k];
            }
        }
        return;
    }
    for (int j = i; j < N; j++) {
        troca(&v[i], &v[j]);
        rotas(v, i + 1);
        troca(&v[i], &v[j]);
    }
}

int main(void) {
    int bairros[N] = {1, 2, 3, 4};
    rotas(bairros, 0);
    printf("%d rotas testadas\n", testadas);
    printf("menor: %d km\n", melhor);
    printf("rota: %s", nomes[0]);
    for (int k = 0; k < N; k++) {
        printf(" -> %s", nomes[melhor_rota[k]]);
    }
    printf(" -> %s\n", nomes[0]);
    return 0;
}
