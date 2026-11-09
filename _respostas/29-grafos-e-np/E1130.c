// 0189 · Juntando tudo
// Exercício E1130 · ★☆☆

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 8

const char *pontos[N] = {"Farmácia", "Ana", "Bruno", "Clara", "Dênis", "Edna", "Fábio", "Gil"};
const int px[N] = {0, 1, 4, 6, 7, 5, 2, 3};
const int py[N] = {0, 3, 4, 3, 0, 1, 6, 1};
int d[N][N];

int main(void) {
    for (int a = 0; a < N; a++)
        for (int b = 0; b < N; b++) d[a][b] = abs(px[a] - px[b]) + abs(py[a] - py[b]);

    bool visitado[N] = {true}; // a farmácia já é o ponto de partida
    int atual = 0, total = 0;
    printf("%s", pontos[0]);
    for (int passo = 1; passo < N; passo++) {
        int prox = -1;
        for (int v = 1; v < N; v++) // o mais perto ainda não visitado (empate: menor índice)
            if (!visitado[v] && (prox == -1 || d[atual][v] < d[atual][prox])) prox = v;
        visitado[prox] = true;
        total += d[atual][prox];
        atual = prox;
        printf(" %s", pontos[atual]);
    }
    total += d[atual][0];
    printf(" %s\nVizinho mais próximo: %d quarteirões\n", pontos[0], total);
    return 0;
}
