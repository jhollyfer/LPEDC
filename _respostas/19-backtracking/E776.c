// 0130 · Juntando tudo
// Exercício E776 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

int g[9][9];

void candidatos(int l, int c) {
    bool usado[10] = {false};
    int bl = l / 3 * 3, bc = c / 3 * 3;
    for (int i = 0; i < 9; i++) {
        usado[g[l][i]] = true;                    // linha
        usado[g[i][c]] = true;                    // coluna
        usado[g[bl + i / 3][bc + i % 3]] = true;  // caixa
    }

    printf("(%d, %d):", l, c);
    for (int d = 1; d <= 9; d++) {
        if (!usado[d]) {
            printf(" %d", d);
        }
    }
    printf("\n");
}

int main(void) {
    const char *jogo[9] = {
        "2.3.8....", "6......7.", ".412.3.86",
        "5........", ".97.28...", "164.9...5",
        ".3...6...", "4.....2..", ".1.832.5.",
    };
    for (int l = 0; l < 9; l++) {
        for (int c = 0; c < 9; c++) {
            g[l][c] = jogo[l][c] == '.' ? 0 : jogo[l][c] - '0';
        }
    }
    int casas[6][2] = {{0, 1}, {3, 1}, {4, 0}, {6, 0}, {8, 8}, {3, 8}};
    for (int k = 0; k < 6; k++) {
        candidatos(casas[k][0], casas[k][1]);
    }
    return 0;
}
