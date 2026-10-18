// 0130 · Juntando tudo
// Exercício E780 · ★★★

#include <stdbool.h>
#include <stdio.h>

int g[9][9];
bool na_linha[9][10], na_coluna[9][10], na_caixa[9][10];
bool na_principal[10]; // diagonal l == c
bool na_secundaria[10]; // diagonal l + c == 8
long chamadas = 0;

int caixa(int l, int c) {
    return (l / 3) * 3 + c / 3;
}

bool livre(int l, int c, int d) {
    if (na_linha[l][d] || na_coluna[c][d] || na_caixa[caixa(l, c)][d]) {
        return false;
    }
    if (l == c && na_principal[d]) {
        return false;
    }
    if (l + c == 8 && na_secundaria[d]) {
        return false;
    }
    return true;
}

void marca(int l, int c, int d, bool valor) {
    na_linha[l][d] = na_coluna[c][d] = na_caixa[caixa(l, c)][d] = valor;
    if (l == c) {
        na_principal[d] = valor;
    }
    if (l + c == 8) {
        na_secundaria[d] = valor;   // a casa do centro está nas duas
    }
}

bool resolve(int k) {
    chamadas++;
    while (k < 81 && g[k / 9][k % 9] != 0) {
        k++;
    }
    if (k == 81) {
        return true;
    }
    int l = k / 9, c = k % 9;
    for (int d = 1; d <= 9; d++) {
        if (!livre(l, c, d)) {
            continue;
        }
        g[l][c] = d;
        marca(l, c, d, true);
        if (resolve(k + 1)) {
            return true;
        }
        marca(l, c, d, false);
        g[l][c] = 0;
    }
    return false;
}

int main(void) {
    const char *jogo[9] = {
        "24.3..7.5", "....7..2.", "...54..3.",
        "....8.49.", "....9.2.3", "8........",
        "...6...5.", "675.3.1..", ".......68",
    };
    for (int l = 0; l < 9; l++) {
        for (int c = 0; c < 9; c++) {
            g[l][c] = jogo[l][c] == '.' ? 0 : jogo[l][c] - '0';
            if (g[l][c] != 0) {
                marca(l, c, g[l][c], true);
            }
        }
    }
    if (resolve(0)) {
        for (int l = 0; l < 9; l++) {
            for (int c = 0; c < 9; c++) {
                printf("%d", g[l][c]);
            }
            printf("\n");
        }
        printf("diagonais: ");
        for (int i = 0; i < 9; i++) {
            printf("%d", g[i][i]);
        }
        printf(" e ");
        for (int i = 0; i < 9; i++) {
            printf("%d", g[i][8 - i]);
        }
        printf("\n%ld chamadas\n", chamadas);
    }
    return 0;
}
