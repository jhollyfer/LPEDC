// 0187 · Reduções
// Exercício E1120 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define MAXM 8
#define MAXV (3 * MAXM)

int adj[MAXV][MAXV];

// monta o grafo da redução e procura clique com um vértice por cláusula
void reduz(const char *nome, int m, const int f[][3]) {
    int nv = 3 * m, arestas = 0;
    for (int a = 0; a < nv; a++)
        for (int b = 0; b < nv; b++) {
            int la = f[a / 3][a % 3], lb = f[b / 3][b % 3];
            adj[a][b] = a / 3 != b / 3 && la != -lb;
            if (a < b && adj[a][b]) arestas++;
        }
    long escolhas = 1;
    for (int c = 0; c < m; c++) escolhas *= 3;
    bool achou = false;
    for (long e = 0; e < escolhas && !achou; e++) {
        int v[MAXM];
        long r = e;
        for (int c = 0; c < m; c++) v[c] = 3 * c + (int)(r % 3), r /= 3;
        bool clique = true;
        for (int i = 0; i < m && clique; i++)
            for (int j = i + 1; j < m; j++)
                if (!adj[v[i]][v[j]]) clique = false;
        achou = clique;
    }
    printf("%s: %d vértices, %d arestas, clique de %d? %s\n", nome, nv, arestas, m, achou ? "sim (satisfatível)" : "não (insatisfatível)");
}

int main(void) {
    const int f1[4][3] = {{1, 2, 3}, {-1, -2, 3}, {1, -2, -3}, {-1, 2, -3}};
    const int f2[8][3] = {{1, 2, 3}, {1, 2, -3}, {1, -2, 3}, {1, -2, -3},
                          {-1, 2, 3}, {-1, 2, -3}, {-1, -2, 3}, {-1, -2, -3}};
    reduz("F1", 4, f1);
    reduz("F2", 8, f2);
    return 0;
}
