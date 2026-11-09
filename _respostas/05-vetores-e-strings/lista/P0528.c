// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0528 · ★★★ · O sudoku 4x4 está certo?

#include <stdio.h>
#include <stdbool.h>

bool tem_1_a_4(const int g[4]) {
    bool visto[5] = {false};
    for (int i = 0; i < 4; i++) {
        if (g[i] < 1 || g[i] > 4 || visto[g[i]]) {
            return false;
        }
        visto[g[i]] = true;
    }
    return true;
}

bool valido(int s[4][4]) {
    int g[4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            g[j] = s[i][j];
        }
        if (!tem_1_a_4(g)) {
            printf("  erro na linha %d\n", i);
            return false;
        }
    }
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            g[i] = s[i][j];
        }
        if (!tem_1_a_4(g)) {
            printf("  erro na coluna %d\n", j);
            return false;
        }
    }
    for (int q = 0; q < 4; q++) {
        int l0 = (q / 2) * 2;
        int c0 = (q % 2) * 2;
        g[0] = s[l0][c0];
        g[1] = s[l0][c0 + 1];
        g[2] = s[l0 + 1][c0];
        g[3] = s[l0 + 1][c0 + 1];
        if (!tem_1_a_4(g)) {
            printf("  erro no quadrado %d\n", q);
            return false;
        }
    }
    return true;
}

int main(void) {
    int a[4][4] = {{1, 2, 3, 4}, {3, 4, 1, 2}, {2, 1, 4, 3}, {4, 3, 2, 1}};
    int b[4][4] = {{1, 2, 3, 4}, {3, 4, 1, 2}, {2, 1, 4, 3}, {4, 2, 3, 1}};
    int c[4][4] = {{1, 2, 3, 4}, {2, 1, 4, 3}, {3, 4, 1, 2}, {4, 3, 2, 1}};

    printf("a:\n");
    printf("  %s\n", valido(a) ? "certo" : "errado");
    printf("b:\n");
    printf("  %s\n", valido(b) ? "certo" : "errado");
    printf("c:\n");
    printf("  %s\n", valido(c) ? "certo" : "errado");
    return 0;
}
