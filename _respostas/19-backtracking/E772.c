// 0129 · Labirinto
// Exercício E772 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define L 5
#define C 6

char planta[L][C + 1] = {
    "S.#...",
    "..#.#.",
    "....#.",
    "###...",
    "....#F",
};
int cl[L * C], cc[L * C]; // as casas do caminho, na ordem
int tamanho = 0;          // quantas casas o caminho tem

bool anda(int l, int c, int k) {
    if (l < 0 || l >= L || c < 0 || c >= C) {
        return false;
    }
    if (planta[l][c] == 'F') {
        cl[k] = l;
        cc[k] = c;
        tamanho = k + 1;
        return true;
    }
    if (planta[l][c] != '.' && planta[l][c] != 'S') {
        return false;
    }
    planta[l][c] = '*';
    cl[k] = l;            // a casa (l, c) é a k-ésima do caminho
    cc[k] = c;
    if (anda(l, c + 1, k + 1) || anda(l + 1, c, k + 1) || anda(l, c - 1, k + 1) ||
        anda(l - 1, c, k + 1)) {
        return true;
    }
    planta[l][c] = 'x';
    return false;
}

int main(void) {
    if (anda(0, 0, 0)) {
        for (int l = 0; l < L; l++) {
            for (int c = 0; c < C; c++) {
                printf(c == 0 ? "%c" : " %c", planta[l][c]);
            }
            printf("\n");
        }
        printf("caminho:");
        for (int k = 0; k < tamanho; k++) {
            printf(" (%d,%d)", cl[k], cc[k]);
        }
        printf("\n%d passos\n", tamanho - 1);
    }
    return 0;
}
