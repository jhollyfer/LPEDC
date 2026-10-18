// 0110 · BFS: busca em largura
// Exercício E659 · ★★★

#include <stdio.h>

#define L 5
#define C 8

int main(void) {
    char mapa[L][C + 1] = {
        "P...#...",
        ".##.#.#.",
        "....#.#P",
        ".#......",
        "...#..#.",
    };
    int dl[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int dist[L][C];
    int fila[L * C], inicio = 0, fim = 0;

    // todas as origens entram juntas, com distância 0
    for (int l = 0; l < L; l++) {
        for (int c = 0; c < C; c++) {
            dist[l][c] = -1;
            if (mapa[l][c] == 'P') {
                dist[l][c] = 0;
                fila[fim++] = l * C + c;
            }
        }
    }

    int pior = 0;
    while (inicio < fim) {
        int u = fila[inicio++];
        int l = u / C, c = u % C;
        if (dist[l][c] > pior) pior = dist[l][c];
        for (int k = 0; k < 4; k++) {
            int nl = l + dl[k], nc = c + dc[k];
            if (nl < 0 || nl >= L || nc < 0 || nc >= C) continue;
            if (mapa[nl][nc] == '#' || dist[nl][nc] != -1) continue;
            dist[nl][nc] = dist[l][c] + 1;
            fila[fim++] = nl * C + nc;
        }
    }

    for (int l = 0; l < L; l++) {
        for (int c = 0; c < C; c++) putchar(mapa[l][c] == '#' ? '#' : '0' + dist[l][c]);
        putchar('\n');
    }
    printf("Pior distância: %d\n", pior);
    return 0;
}
