// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2925 · ★★★ · De 3-SAT para conjunto independente

#include <stdbool.h>
#include <stdio.h>

#define M 4
#define NV 4
#define V (3 * M)

const int f[M][3] = {{1, 2, -3}, {-1, 3, 4}, {-2, -4, 3}, {1, -3, -4}};
int adj[V][V];

int lit(int a) {
    return f[a / 3][a % 3];
}

int main(void) {
    int arestas = 0;
    for (int a = 0; a < V; a++)
        for (int b = a + 1; b < V; b++)
            if (a / 3 == b / 3 || lit(a) == -lit(b)) adj[a][b] = adj[b][a] = 1, arestas++;
    printf("Grafo: %d vértices, %d arestas\n", V, arestas);
    for (int m = 0; m < (1 << V); m++) {
        int tam = 0;
        for (int v = 0; v < V; v++) tam += m >> v & 1;
        if (tam != M) continue;
        bool ok = true;
        for (int a = 0; a < V && ok; a++)
            for (int b = a + 1; b < V; b++)
                if ((m >> a & 1) && (m >> b & 1) && adj[a][b]) ok = false;
        if (!ok) continue;
        bool x[NV + 1] = {false};
        printf("Independente:");
        for (int v = 0; v < V; v++)
            if (m >> v & 1) {
                printf(" %s%d", lit(v) < 0 ? "não x" : "x", lit(v) < 0 ? -lit(v) : lit(v));
                if (lit(v) > 0) x[lit(v)] = true;
            }
        printf("\nAtribuição:");
        for (int i = 1; i <= NV; i++) printf(" x%d=%c", i, x[i] ? 'V' : 'F');
        bool todas = true;
        for (int c = 0; c < M; c++) {
            bool algum = false;
            for (int i = 0; i < 3; i++) {
                int l = f[c][i];
                if (l > 0 ? x[l] : !x[-l]) algum = true;
            }
            if (!algum) todas = false;
        }
        printf("\nSatisfaz a fórmula? %s\n", todas ? "sim" : "não");
        return 0;
    }
    printf("Sem independente de tamanho %d: insatisfatível\n", M);
    return 0;
}
