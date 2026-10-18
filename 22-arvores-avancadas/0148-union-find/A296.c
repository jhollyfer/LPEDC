// A296 · As ilhas do mapa

#include <stdio.h>
#include "uniao.h"

#define LIN 5
#define COL 8

// cada célula (i, j) vira o elemento i * COL + j do union-find
int main(void) {
    const char *mapa[LIN] = {
        "##..#...",
        "#...##..",
        "..#..#.#",
        ".###...#",
        "....##.#",
    };
    UF *u = uf_cria(LIN * COL);
    int terra = 0;
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if (mapa[i][j] != '#') {
                continue;
            }
            terra++;
            // basta olhar para a direita e para baixo: as outras duas
            // direções já foram vistas pelas células anteriores
            if (j + 1 < COL && mapa[i][j + 1] == '#') {
                uf_une(u, i * COL + j, i * COL + j + 1);
            }
            if (i + 1 < LIN && mapa[i + 1][j] == '#') {
                uf_une(u, i * COL + j, (i + 1) * COL + j);
            }
        }
    }
    // os grupos do union-find contam também as células de água (sozinhas)
    int agua = LIN * COL - terra;
    printf("Ilhas: %d\n", uf_grupos(u) - agua);

    int maior = 0, onde = 0;
    for (int c = 0; c < LIN * COL; c++) {
        if (mapa[c / COL][c % COL] == '#' && uf_tamanho(u, c) > maior) {
            maior = uf_tamanho(u, c);
            onde = c;
        }
    }
    printf("Maior ilha: %d células, uma delas na linha %d, coluna %d\n",
           maior, onde / COL, onde % COL);
    printf("(0, 4) e (2, 5) na mesma ilha? %s\n",
           uf_juntos(u, 0 * COL + 4, 2 * COL + 5) ? "sim" : "não");
    printf("(2, 2) e (4, 4) na mesma ilha? %s\n",
           uf_juntos(u, 2 * COL + 2, 4 * COL + 4) ? "sim" : "não");

    uf_libera(u);
    return 0;
}
// Saída:
// Ilhas: 5
// Maior ilha: 4 células, uma delas na linha 0, coluna 4
// (0, 4) e (2, 5) na mesma ilha? sim
// (2, 2) e (4, 4) na mesma ilha? não
