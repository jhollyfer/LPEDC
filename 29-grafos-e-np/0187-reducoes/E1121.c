// 0187 · Reduções
// Exercício E1121 · ★★★
//
// Ache o bug. Este programa monta o grafo da redução 3-SAT -> clique para a
// fórmula (x1 ou x2) (x1 ou não x2) (não x1 ou x2) (não x1 ou não x2), que
// não tem solução (cada atribuição de x1, x2 derruba uma cláusula). Mas o
// programa acha uma clique de tamanho 4 e diz que ela é satisfatível:
//
//   Saída que aparece:
//   Clique: v0 v1 v2 v3 -> satisfatível
//
//   Saída esperada:
//   Sem clique de tamanho 4 -> insatisfatível
//
// O programa compila e roda sem erro; o problema é de lógica, numa linha só
// da construção do grafo. Conserte-a.
//
// Dicas:
// 1. Os vértices v0, v1, v2 são os três literais da PRIMEIRA cláusula. Uma
//    clique que usa dois vértices da mesma cláusula escolhe o quê?
// 2. A regra da redução tem duas condições: cláusulas diferentes E sem
//    contradição. O código só confere uma.
// 3. Resposta esperada: a saída esperada acima. Troque a != b por
//    a / 3 != b / 3.
//
// Escreva sua resposta abaixo (conserte o código):

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
            adj[a][b] = a != b && la != -lb; // literais que não se contradizem
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
