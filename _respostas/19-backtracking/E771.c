// 0129 · Labirinto
// Exercício E771 · ★★☆

#include <stdio.h>

#define L 6
#define C 12

char mapa[L][C + 1] = {
    "~~..........",
    "~~~...~~....",
    "......~~..~.",
    ".~.......~~~",
    ".~~~.....~..",
    "......~.....",
};

// apaga (troca por '.') o lago que contém (l, c) e devolve o tamanho dele
int seca(int l, int c) {
    if (l < 0 || l >= L || c < 0 || c >= C || mapa[l][c] != '~') {
        return 0;
    }
    mapa[l][c] = '.';
    return 1 + seca(l, c + 1) + seca(l + 1, c) + seca(l, c - 1) + seca(l - 1, c);
}

int main(void) {
    int lagos = 0;
    for (int l = 0; l < L; l++) {
        for (int c = 0; c < C; c++) {
            if (mapa[l][c] == '~') {
                lagos++;
                int tamanho = seca(l, c);
                printf("lago %d: começa em (%d, %d), tamanho %d\n", lagos, l, c, tamanho);
            }
        }
    }
    printf("%d lagos\n", lagos);
    return 0;
}
