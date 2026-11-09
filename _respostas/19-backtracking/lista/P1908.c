// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1908 · ★☆☆ · O fogo que pula na diagonal

#include <stdio.h>

#define L 5
#define C 7

char mapa[L][C + 1] = {
    "..#....",
    "..#.#..",
    "##.##..",
    "###..#.",
    "..#.#..",
};
int queimadas = 0;

void queima(int l, int c) {
    if (l < 0 || l >= L || c < 0 || c >= C || mapa[l][c] != '.') {
        return;
    }
    mapa[l][c] = '*';
    queimadas++;
    for (int dl = -1; dl <= 1; dl++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dl != 0 || dc != 0) {
                queima(l + dl, c + dc);
            }
        }
    }
}

int main(void) {
    queima(0, 0);
    for (int l = 0; l < L; l++) {
        printf("%s\n", mapa[l]);
    }
    printf("Queimadas: %d casas\n", queimadas);
    return 0;
}
