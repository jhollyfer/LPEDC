// 0128 · N-rainhas
// Exercício E768 · ★★★

#include <stdbool.h>
#include <stdio.h>

#define N 5

const int dl[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int casa[N][N];       // 0 = livre; k = o cavalo chegou ali no salto k
long chamadas = 0;

// o cavalo está em (l, c), que acabou de receber o número k
bool salta(int l, int c, int k) {
    chamadas++;
    if (k == N * N) {
        return true;                       // visitou as 25 casas
    }
    for (int m = 0; m < 8; m++) {
        int nl = l + dl[m], nc = c + dc[m];
        if (nl < 0 || nl >= N || nc < 0 || nc >= N || casa[nl][nc] != 0) {
            continue;                      // poda: fora ou já visitada
        }
        casa[nl][nc] = k + 1;              // escolhe
        if (salta(nl, nc, k + 1)) {
            return true;
        }
        casa[nl][nc] = 0;                  // desfaz
    }
    return false;
}

int main(void) {
    casa[0][0] = 1;
    if (salta(0, 0, 1)) {
        for (int l = 0; l < N; l++) {
            for (int c = 0; c < N; c++) {
                printf("%3d", casa[l][c]);
            }
            printf("\n");
        }
    }
    printf("%ld chamadas\n", chamadas);
    return 0;
}
