// 0130 · Juntando tudo
// Exercício E779 · ★★★
//
// Resposta: o programa apagava o dígito da grade, mas não desmarcava os
// vetores. Cada dígito abandonado continuava contando como presente na
// linha, na coluna e na caixa, e a poda passava a cortar a resposta certa.
// Tudo o que é feito antes da chamada recursiva precisa ser desfeito depois.

#include <stdbool.h>
#include <stdio.h>

int g[9][9];
bool na_linha[9][10], na_coluna[9][10], na_caixa[9][10];

int caixa(int l, int c) {
    return (l / 3) * 3 + c / 3;
}

void marca(int l, int c, int d, bool valor) {
    na_linha[l][d] = na_coluna[c][d] = na_caixa[caixa(l, c)][d] = valor;
}

bool resolve(int k) {
    while (k < 81 && g[k / 9][k % 9] != 0) {
        k++;
    }
    if (k == 81) {
        return true;
    }
    int l = k / 9, c = k % 9;
    for (int d = 1; d <= 9; d++) {
        if (na_linha[l][d] || na_coluna[c][d] || na_caixa[caixa(l, c)][d]) {
            continue;
        }
        g[l][c] = d;
        marca(l, c, d, true);
        if (resolve(k + 1)) {
            return true;
        }
        marca(l, c, d, false); // a linha que faltava: desfaz a marcação
        g[l][c] = 0;
    }
    return false;
}

int main(void) {
    const char *jogo[9] = {
        "..46.789.", "9.....1.6", ".....4..3",
        "4.....2.8", ".........", ".1.279..5",
        ".....2..1", "..19..587", "87.3...24",
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
    } else {
        printf("sem solução\n");
    }
    return 0;
}
