// 0130 · Juntando tudo
// Exercício E777 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define N 6
#define BL 2 // linhas de cada bloco
#define BC 3 // colunas de cada bloco

int g[N][N];
bool na_linha[N][N + 1];
bool na_coluna[N][N + 1];
bool no_bloco[N][N + 1];
long chamadas = 0;

int bloco(int l, int c) {
    return (l / BL) * (N / BC) + c / BC;
}

void marca(int l, int c, int d, bool valor) {
    na_linha[l][d] = na_coluna[c][d] = no_bloco[bloco(l, c)][d] = valor;
}

bool resolve(int k) {
    chamadas++;
    while (k < N * N && g[k / N][k % N] != 0) {
        k++;
    }
    if (k == N * N) {
        return true;
    }
    int l = k / N, c = k % N;
    for (int d = 1; d <= N; d++) {
        if (na_linha[l][d] || na_coluna[c][d] || no_bloco[bloco(l, c)][d]) {
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
    const char *jogo[N] = {"..2..3", "1..2..", ".1....", "6..3..", "24.6..", ".6.5.."};
    for (int l = 0; l < N; l++) {
        for (int c = 0; c < N; c++) {
            if (jogo[l][c] != '.') {
                g[l][c] = jogo[l][c] - '0';
                marca(l, c, g[l][c], true);
            }
        }
    }
    if (resolve(0)) {
        for (int l = 0; l < N; l++) {
            for (int c = 0; c < N; c++) {
                printf("%d%s", g[l][c], c == N - 1 ? "\n" : (c == BC - 1 ? " | " : " "));
            }
            if (l % BL == BL - 1 && l < N - 1) {
                printf("------+------\n");
            }
        }
    }
    printf("%ld chamadas\n", chamadas);
    return 0;
}
