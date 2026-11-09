// 0187 · Reduções
// Exercício E1121 · ★★★

#include <stdbool.h>
#include <stdio.h>

#define M 4
#define V (3 * M)

// (x1 ou x2) (x1 ou não x2) (não x1 ou x2) (não x1 ou não x2): insatisfatível.
// Cláusulas de dois literais repetem o último para caber em 3.
const int f[M][3] = {{1, 2, 2}, {1, -2, -2}, {-1, 2, 2}, {-1, -2, -2}};
int adj[V][V];

int main(void) {
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) {
            int la = f[a / 3][a % 3], lb = f[b / 3][b % 3];
            adj[a][b] = a / 3 != b / 3 && la != -lb; // cláusulas diferentes e sem contradição
        }

    // procura qualquer clique de tamanho M entre os V vértices
    for (int m = 0; m < (1 << V); m++) {
        int tam = 0;
        for (int v = 0; v < V; v++) tam += m >> v & 1;
        if (tam != M) continue;
        bool clique = true;
        for (int a = 0; a < V; a++)
            for (int b = a + 1; b < V; b++)
                if ((m >> a & 1) && (m >> b & 1) && !adj[a][b]) clique = false;
        if (clique) {
            printf("Clique:");
            for (int v = 0; v < V; v++)
                if (m >> v & 1) printf(" v%d", v);
            printf(" -> satisfatível\n");
            return 0;
        }
    }
    printf("Sem clique de tamanho %d -> insatisfatível\n", M);
    return 0;
}
