// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0522 · ★★★ · A matriz esparsa do estacionamento

#include <stdio.h>

#define L 5
#define C 6

int compactar(int m[L][C], int t[][3]) {
    int k = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (m[i][j] != 0) {
                t[k][0] = i;
                t[k][1] = j;
                t[k][2] = m[i][j];
                k++;
            }
        }
    }
    return k;
}

int transpor(int t[][3], int k, int tt[][3]) {
    int n = 0;
    for (int c = 0; c < C; c++) {       // cada coluna da original...
        for (int p = 0; p < k; p++) {   // ...vira uma linha da transposta
            if (t[p][1] == c) {
                tt[n][0] = t[p][1];
                tt[n][1] = t[p][0];
                tt[n][2] = t[p][2];
                n++;
            }
        }
    }
    return n;
}

void mostrar_triplas(const char titulo[], int t[][3], int k) {
    printf("%s:", titulo);
    for (int p = 0; p < k; p++) {
        printf(" (%d,%d,%d)", t[p][0], t[p][1], t[p][2]);
    }
    printf("\n");
}

void mostrar_cheia(int t[][3], int k, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int v = 0;
            for (int p = 0; p < k; p++) {
                if (t[p][0] == i && t[p][1] == j) {
                    v = t[p][2];
                }
            }
            printf("%d%s", v, j < colunas - 1 ? " " : "\n");
        }
    }
}

int main(void) {
    int m[L][C] = {{0, 0, 3, 0, 0, 0},
                   {0, 0, 0, 0, 0, 7},
                   {1, 0, 0, 0, 0, 0},
                   {0, 0, 4, 0, 0, 0},
                   {0, 2, 0, 0, 0, 0}};
    int t[L * C][3];
    int tt[L * C][3];

    int k = compactar(m, t);
    printf("%d de %d casas guardadas\n", k, L * C);
    mostrar_triplas("Triplas", t, k);
    int n = transpor(t, k, tt);
    mostrar_triplas("Transposta", tt, n);
    printf("Transposta cheia (%dx%d):\n", C, L);
    mostrar_cheia(tt, n, C, L);
    return 0;
}
