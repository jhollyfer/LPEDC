// Lista · Módulo 07 · Memória dinâmica
// Exercício P0729 · ★★★ · Quantas ilhas tem o mapa do rio

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int inundar(const char **mapa, bool **vis, int l, int c, int i, int j) {
    if (i < 0 || i >= l || j < 0 || j >= c || mapa[i][j] != '#' || vis[i][j]) {
        return 0;
    }
    vis[i][j] = true;
    return 1 + inundar(mapa, vis, l, c, i - 1, j) + inundar(mapa, vis, l, c, i + 1, j)
             + inundar(mapa, vis, l, c, i, j - 1) + inundar(mapa, vis, l, c, i, j + 1);
}

void liberar(bool **v, int l) {
    if (v == NULL) {
        return;
    }
    for (int i = 0; i < l; i++) {
        free(v[i]);
    }
    free(v);
}

int main(void) {
    const char *mapa[6] = {"##....#...",
                           "##...###..",
                           "......#...",
                           "..#.......",
                           ".###..##.#",
                           "..#...##.#"};
    int l = 6, c = 10;

    bool **vis = malloc(l * sizeof *vis);
    if (vis == NULL) {
        return 1;
    }
    for (int i = 0; i < l; i++) {
        vis[i] = calloc(c, sizeof *vis[i]); // tudo false
        if (vis[i] == NULL) {
            liberar(vis, i);
            return 1;
        }
    }

    int ilhas = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (mapa[i][j] == '#' && !vis[i][j]) {
                ilhas++;
                int tam = inundar(mapa, vis, l, c, i, j);
                printf("Ilha %d: começa em (%d, %d), %d casas\n", ilhas, i, j, tam);
            }
        }
    }
    printf("Total: %d ilhas\n", ilhas);
    liberar(vis, l);
    return 0;
}
