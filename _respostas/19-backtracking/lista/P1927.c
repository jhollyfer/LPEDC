// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1927 · ★★★ · Futoshiki 4 × 4

#include <stdbool.h>
#include <stdio.h>

#define N 4
#define NS 6

typedef struct {
    int la, ca, lb, cb;
} Sinal;

const Sinal sinal[NS] = {
    {0, 1, 0, 0}, {2, 2, 2, 3}, {1, 2, 0, 2},
    {1, 3, 0, 3}, {3, 2, 2, 2}, {2, 3, 3, 3},
};
int g[N][N], sol[N][N];
bool na_lin[N][N + 1], na_col[N][N + 1];
int solucoes = 0;

bool ok_sinais(void) {
    for (int s = 0; s < NS; s++) {
        int a = g[sinal[s].la][sinal[s].ca], b = g[sinal[s].lb][sinal[s].cb];
        if (a != 0 && b != 0 && a >= b) {
            return false;
        }
    }
    return true;
}

void resolve(int k) {
    if (k == N * N) {
        solucoes++;
        for (int l = 0; l < N; l++) {
            for (int c = 0; c < N; c++) {
                sol[l][c] = g[l][c];
            }
        }
        return;
    }
    int l = k / N, c = k % N;
    for (int x = 1; x <= N; x++) {
        if (na_lin[l][x] || na_col[c][x]) {
            continue;
        }
        g[l][c] = x;
        if (ok_sinais()) {
            na_lin[l][x] = na_col[c][x] = true;
            resolve(k + 1);
            na_lin[l][x] = na_col[c][x] = false;
        }
        g[l][c] = 0;
    }
}

int main(void) {
    resolve(0);
    printf("Soluções: %d\n", solucoes);
    if (solucoes > 0) {
        for (int l = 0; l < N; l++) {
            printf("%d %d %d %d\n", sol[l][0], sol[l][1], sol[l][2], sol[l][3]);
        }
    }
    return 0;
}
