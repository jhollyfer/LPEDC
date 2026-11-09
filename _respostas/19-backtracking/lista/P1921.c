// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1921 · ★★★ · O cavalo com a regra de Warnsdorff

#include <stdio.h>

#define N 6

const int dl[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int tab[N][N];
long voltas = 0;

int livre(int l, int c) {
    return l >= 0 && l < N && c >= 0 && c < N && tab[l][c] == 0;
}

int saidas(int l, int c) {
    int s = 0;
    for (int k = 0; k < 8; k++) {
        if (livre(l + dl[k], c + dc[k])) {
            s++;
        }
    }
    return s;
}

int passeia(int l, int c, int passo) {
    tab[l][c] = passo;
    if (passo == N * N) {
        return 1;
    }
    int cand[8], grau[8], n = 0;
    for (int k = 0; k < 8; k++) {
        int nl = l + dl[k], nc = c + dc[k];
        if (livre(nl, nc)) {
            int g = saidas(nl, nc);
            int j = n;
            while (j > 0 && grau[j - 1] > g) {
                cand[j] = cand[j - 1];
                grau[j] = grau[j - 1];
                j--;
            }
            cand[j] = k;
            grau[j] = g;
            n++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (passeia(l + dl[cand[i]], c + dc[cand[i]], passo + 1)) {
            return 1;
        }
    }
    tab[l][c] = 0;
    voltas++;
    return 0;
}

int main(void) {
    if (passeia(0, 0, 1)) {
        for (int l = 0; l < N; l++) {
            for (int c = 0; c < N; c++) {
                printf("%3d", tab[l][c]);
            }
            printf("\n");
        }
    } else {
        printf("Sem passeio\n");
    }
    printf("Voltas: %ld\n", voltas);
    return 0;
}
