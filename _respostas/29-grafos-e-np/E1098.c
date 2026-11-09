// 0183 · Hamiltoniano
// Exercício E1098 · ★★★

#include <stdbool.h>
#include <stdio.h>

#define N 5

int casa[N][N]; // 0 = livre; k = k-ésima casa visitada
long chamadas = 0;
const int dl[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool passeio(int l, int c, int k) {
    chamadas++;
    casa[l][c] = k;
    if (k == N * N) return true;
    for (int m = 0; m < 8; m++) {
        int nl = l + dl[m], nc = c + dc[m];
        if (nl < 0 || nl >= N || nc < 0 || nc >= N || casa[nl][nc] != 0) continue;
        if (passeio(nl, nc, k + 1)) return true;
    }
    casa[l][c] = 0; // desfaz
    return false;
}

int main(void) {
    if (passeio(0, 0, 1)) {
        for (int l = 0; l < N; l++) {
            for (int c = 0; c < N; c++) printf("%3d", casa[l][c]);
            printf("\n");
        }
    } else {
        printf("Sem passeio\n");
    }
    printf("Chamadas: %ld\n", chamadas);
    return 0;
}
