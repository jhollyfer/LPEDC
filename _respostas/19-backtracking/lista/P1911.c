// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1911 · ★★☆ · Pintando o mapa do Norte

#include <stdio.h>

#define N 7
#define CORES 3

const char *uf[N] = {"AC", "AM", "RR", "RO", "PA", "AP", "TO"};
const char *nome_cor[CORES] = {"verde", "amarelo", "azul"};
const int viz[N][N] = {
    // AC AM RR RO PA AP TO
    {0, 1, 0, 1, 0, 0, 0}, // AC
    {1, 0, 1, 1, 1, 0, 0}, // AM
    {0, 1, 0, 0, 1, 0, 0}, // RR
    {1, 1, 0, 0, 0, 0, 0}, // RO
    {0, 1, 1, 0, 0, 1, 1}, // PA
    {0, 0, 0, 0, 1, 0, 0}, // AP
    {0, 0, 0, 0, 1, 0, 0}, // TO
};
int cor[N], primeira[N];
int total = 0;

int pode(int e, int c) {
    for (int v = 0; v < e; v++) {
        if (viz[e][v] && cor[v] == c) {
            return 0;
        }
    }
    return 1;
}

void pinta(int e) {
    if (e == N) {
        if (total == 0) {
            for (int i = 0; i < N; i++) {
                primeira[i] = cor[i];
            }
        }
        total++;
        return;
    }
    for (int c = 0; c < CORES; c++) {
        if (pode(e, c)) {
            cor[e] = c;
            pinta(e + 1);
            cor[e] = -1;
        }
    }
}

int main(void) {
    for (int i = 0; i < N; i++) {
        cor[i] = -1;
    }
    pinta(0);
    printf("Primeira coloração:\n");
    for (int i = 0; i < N; i++) {
        printf("  %s: %s\n", uf[i], nome_cor[primeira[i]]);
    }
    printf("Colorações com 3 cores: %d\n", total);
    return 0;
}
