// 0148 · Union-find
// Exercício E886 · ★★☆

#include <stdio.h>
#include "uniao.h"

int main(void) {
    const char *jogador[] = {"Alex", "Bia", "Cadu", "Davi", "Eli", "Fabi", "Gabo", "Hana", "Ivo"};
    int n = 9;
    // cada par já jogou junto na pelada de quinta
    int duplas[][2] = {{0, 4}, {2, 7}, {4, 8}, {1, 5}, {7, 3}, {8, 0}};
    UF *u = uf_cria(n);
    for (int i = 0; i < 6; i++) {
        uf_une(u, duplas[i][0], duplas[i][1]);
    }
    // um time por representante; o time sai na ordem do seu primeiro jogador
    int time = 1;
    for (int x = 0; x < n; x++) {
        int r = uf_acha(u, x);
        bool primeiro = true; // x é o menor do grupo?
        for (int y = 0; y < x; y++) {
            if (uf_acha(u, y) == r) {
                primeiro = false;
                break;
            }
        }
        if (!primeiro) {
            continue;
        }
        printf("Time %d (%d):", time++, uf_tamanho(u, x));
        for (int y = x; y < n; y++) {
            if (uf_acha(u, y) == r) {
                printf(" %s", jogador[y]);
            }
        }
        printf("\n");
    }
    uf_libera(u);
    return 0;
}
