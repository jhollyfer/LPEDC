// Lista · Módulo 16 · Grafos
// Exercício P1618 · ★★☆ · O caminho do entregador desenhado na grade

#include <stdio.h>

#define L 5
#define C 8

char mapa[L][C + 1] = {
    "S..#....",
    ".#.#.##.",
    ".#...#..",
    ".##.#..#",
    "....#.E.",
};

int main(void) {
    int dl[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    int dist[L * C], pai[L * C], fila[L * C], ini = 0, fim = 0;
    int s = -1, e = -1;
    for (int x = 0; x < L * C; x++) {
        dist[x] = pai[x] = -1;
        if (mapa[x / C][x % C] == 'S') s = x;
        if (mapa[x / C][x % C] == 'E') e = x;
    }
    dist[s] = 0;
    fila[fim++] = s;
    while (ini < fim) {
        int u = fila[ini++], l = u / C, c = u % C;
        for (int k = 0; k < 4; k++) {
            int nl = l + dl[k], nc = c + dc[k];
            if (nl < 0 || nl >= L || nc < 0 || nc >= C) continue; // fora da grade
            int v = nl * C + nc;
            if (mapa[nl][nc] == '#' || dist[v] != -1) continue;    // muro ou já visto
            dist[v] = dist[u] + 1;
            pai[v] = u;
            fila[fim++] = v;
        }
    }
    if (dist[e] == -1) {
        printf("Sem caminho\n");
        return 0;
    }
    printf("Passos: %d\n", dist[e]);
    for (int x = pai[e]; x != s; x = pai[x]) mapa[x / C][x % C] = '*';
    for (int l = 0; l < L; l++) printf("%s\n", mapa[l]);
    return 0;
}
