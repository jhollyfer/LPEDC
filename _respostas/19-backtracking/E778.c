// 0130 · Juntando tudo
// Exercício E778 · ★★☆

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int g[9][9];
bool na_linha[9][10], na_coluna[9][10], na_caixa[9][10];

int caixa(int l, int c) {
    return (l / 3) * 3 + c / 3;
}

void marca(int l, int c, int d, bool valor) {
    na_linha[l][d] = na_coluna[c][d] = na_caixa[caixa(l, c)][d] = valor;
}

void prepara(const char *jogo[9]) {
    memset(na_linha, 0, sizeof na_linha);
    memset(na_coluna, 0, sizeof na_coluna);
    memset(na_caixa, 0, sizeof na_caixa);
    for (int l = 0; l < 9; l++) {
        for (int c = 0; c < 9; c++) {
            g[l][c] = jogo[l][c] == '.' ? 0 : jogo[l][c] - '0';
            if (g[l][c] != 0) {
                marca(l, c, g[l][c], true);
            }
        }
    }
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
        marca(l, c, d, false);
        g[l][c] = 0;
    }
    return false;
}

// conta as soluções a partir da casa k, parando ao chegar a limite
int conta(int k, int limite) {
    while (k < 81 && g[k / 9][k % 9] != 0) {
        k++;
    }
    if (k == 81) {
        return 1;
    }
    int l = k / 9, c = k % 9;
    int total = 0;
    for (int d = 1; d <= 9; d++) {
        if (na_linha[l][d] || na_coluna[c][d] || na_caixa[caixa(l, c)][d]) {
            continue;
        }
        g[l][c] = d;
        marca(l, c, d, true);
        total += conta(k + 1, limite - total);
        marca(l, c, d, false);      // desfaz sempre, antes de qualquer return
        g[l][c] = 0;
        if (total >= limite) {
            return total;
        }
    }
    return total;
}

const char *veredito(int n) {
    return n == 0 ? "sem solução" : (n == 1 ? "solução única" : "mais de uma solução");
}

int main(void) {
    const char *jogo1[9] = {
        "2.3.8....", "6......7.", ".412.3.86",
        "5........", ".97.28...", "164.9...5",
        ".3...6...", "4.....2..", ".1.832.5.",
    };
    const char *jogo2[9] = {
        "2.3.8....", "6......7.", ".412.3.86",
        "5........", ".97.28...", "164.9....",
        ".3...6...", "4.....2..", ".1.832.5.",
    };
    prepara(jogo1);
    printf("jogo 1: %s\n", veredito(conta(0, 2)));
    prepara(jogo2);
    printf("jogo 2: %s\n", veredito(conta(0, 2)));
    return 0;
}
