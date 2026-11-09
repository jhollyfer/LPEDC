// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2909 · ★☆☆ · O verificador do caixeiro viajante

#include <stdbool.h>
#include <stdio.h>

#define N 5

const int d[N][N] = {{0, 12, 30, -1, 25}, {12, 0, 18, 20, -1}, {30, 18, 0, 15, 22},
                     {-1, 20, 15, 0, 17}, {25, -1, 22, 17, 0}};

bool aceita(const int r[], int n, int limite) {
    bool visto[N] = {false};
    for (int i = 0; i < n; i++) {
        if (visto[r[i]]) {
            printf("rejeitado (repete cidade)\n");
            return false;
        }
        visto[r[i]] = true;
    }
    int custo = 0;
    for (int i = 0; i < n; i++) {
        int x = r[i], y = r[(i + 1) % n];
        if (d[x][y] < 0) {
            printf("rejeitado (sem estrada %d-%d)\n", x, y);
            return false;
        }
        custo += d[x][y];
    }
    if (custo > limite) {
        printf("rejeitado (custo %d > %d)\n", custo, limite);
        return false;
    }
    printf("aceito (custo %d)\n", custo);
    return true;
}

int main(void) {
    int a[] = {0, 1, 2, 3, 4}, b[] = {0, 2, 4, 1, 3}, c[] = {0, 1, 3, 2, 4};
    aceita(a, N, 90);
    aceita(b, N, 100);
    aceita(c, N, 100);
    aceita(c, N, 90);
    return 0;
}
