// 0148 · Union-find
// Exercício E888 · ★★★

#include <stdbool.h>
#include <stdio.h>
#include "uniao.h"

#define L 5
#define TOPO (L * L)       // elemento virtual ligado a toda a linha de cima
#define FUNDO (L * L + 1)  // elemento virtual ligado a toda a linha de baixo

int main(void) {
    bool aberta[L * L] = {false};
    UF *u = uf_cria(L * L + 2);
    int dl[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    int passo = 0;
    for (int i = 0; i < L * L; i++) {
        int c = (i * 9 + 7) % (L * L); // a ordem dos furos
        int lin = c / L, col = c % L;
        aberta[c] = true;
        passo++;
        if (lin == 0) {
            uf_une(u, c, TOPO);
        }
        if (lin == L - 1) {
            uf_une(u, c, FUNDO);
        }
        for (int k = 0; k < 4; k++) {
            int nl = lin + dl[k], nc = col + dc[k];
            if (nl >= 0 && nl < L && nc >= 0 && nc < L && aberta[nl * L + nc]) {
                uf_une(u, c, nl * L + nc);
            }
        }
        if (uf_juntos(u, TOPO, FUNDO)) {
            break;
        }
    }
    printf("A água passou no passo %d (%d de %d abertas)\n", passo, passo, L * L);
    for (int lin = 0; lin < L; lin++) {
        for (int col = 0; col < L; col++) {
            putchar(aberta[lin * L + col] ? '#' : '.');
        }
        putchar('\n');
    }
    uf_libera(u);
    return 0;
}
