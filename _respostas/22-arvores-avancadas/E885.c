// 0148 · Union-find
// Exercício E885 · ★★☆

#include <stdio.h>
#include "uniao.h"

int main(void) {
    // cabos do escritório: cada par liga dois computadores (0 a 6)
    int cabos[][2] = {{0, 1}, {1, 2}, {3, 4}, {2, 0}, {4, 5}, {5, 6}, {1, 4}, {6, 3}, {2, 5}};
    int n = 9;
    UF *u = uf_cria(7);
    int sobra = 0;
    for (int i = 0; i < n; i++) {
        int a = cabos[i][0], b = cabos[i][1];
        if (!uf_une(u, a, b)) { // já estavam ligados: este cabo fecha um ciclo
            printf("cabo %d (%d-%d) é redundante\n", i + 1, a, b);
            sobra++;
        }
    }
    printf("%d cabos redundantes; %d cabos bastam; rede %s\n", sobra, n - sobra,
           uf_grupos(u) == 1 ? "toda ligada" : "partida");
    uf_libera(u);
    return 0;
}
