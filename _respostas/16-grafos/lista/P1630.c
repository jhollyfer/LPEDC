// Lista · Módulo 16 · Grafos
// Exercício P1630 · ★★★ · Fuga do incêndio no galpão

#include <limits.h>
#include <stdio.h>

#define L 5
#define C 9

char galpao1[L][C + 1] = {
    "###.#####",
    "#F..#...#",
    "#.#.#.#.#",
    "#...P.#..",
    "#########",
};
char galpao2[L][C + 1] = {
    "#########",
    "#P.....F#",
    "#.#####.#",
    "#......F.",
    "#########",
};

int dl[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
int fogo[L * C];

// BFS com várias origens: todas as casas F começam no tempo 0
void espalha(char mapa[][C + 1]) {
    int fila[L * C], ini = 0, fim = 0;
    for (int x = 0; x < L * C; x++) {
        fogo[x] = INT_MAX;
        if (mapa[x / C][x % C] == 'F') {
            fogo[x] = 0; // todas as origens no tempo 0
            fila[fim++] = x;
        }
    }
    while (ini < fim) {
        int u = fila[ini++];
        for (int k = 0; k < 4; k++) {
            int nl = u / C + dl[k], nc = u % C + dc[k];
            if (nl < 0 || nl >= L || nc < 0 || nc >= C || mapa[nl][nc] == '#') continue;
            int v = nl * C + nc;
            if (fogo[v] != INT_MAX) continue;
            fogo[v] = fogo[u] + 1;
            fila[fim++] = v;
        }
    }
}

int fuga(char mapa[][C + 1]) {
    int passo[L * C], fila[L * C], ini = 0, fim = 0;
    espalha(mapa);
    for (int x = 0; x < L * C; x++) {
        passo[x] = -1;
        if (mapa[x / C][x % C] == 'P') {
            passo[x] = 0;
            fila[fim++] = x;
        }
    }
    while (ini < fim) {
        int u = fila[ini++], l = u / C, c = u % C;
        if (l == 0 || l == L - 1 || c == 0 || c == C - 1) return passo[u] + 1; // sai pela borda
        for (int k = 0; k < 4; k++) {
            int nl = l + dl[k], nc = c + dc[k];
            if (mapa[nl][nc] == '#') continue; // u não é borda: nl, nc estão dentro
            int v = nl * C + nc;
            if (passo[v] != -1 || passo[u] + 1 >= fogo[v]) continue; // visto ou o fogo chega antes
            passo[v] = passo[u] + 1;
            fila[fim++] = v;
        }
    }
    return -1;
}

int main(void) {
    int r1 = fuga(galpao1);
    printf("Fogo no galpão 1 (minuto em que chega):\n");
    for (int l = 0; l < L; l++) {
        for (int c = 0; c < C; c++) {
            int x = l * C + c;
            if (galpao1[l][c] == '#') printf("  #");
            else printf("%3d", fogo[x]);
        }
        printf("\n");
    }
    printf("Galpão 1: %d minutos\n", r1);
    printf("Galpão 2: %d\n", fuga(galpao2));
    return 0;
}
