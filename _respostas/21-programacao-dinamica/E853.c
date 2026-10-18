// 0143 · Juntando tudo: um mini-diff
// Exercício E853 · ★☆☆

#include <stdio.h>
#include <string.h>

#define MAX 20

int lcs_linhas(const char *a[], int m, const char *b[], int n) {
    int c[MAX + 1][MAX + 1];
    for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            if (i == m || j == n) {
                c[i][j] = 0;
            } else if (strcmp(a[i], b[j]) == 0) {
                c[i][j] = c[i + 1][j + 1] + 1;
            } else {
                c[i][j] = c[i + 1][j] >= c[i][j + 1] ? c[i + 1][j] : c[i][j + 1];
            }
        }
    }
    return c[0][0];
}

int main(void) {
    const char *ontem[] = {"Ana", "Bruno", "Carla", "Davi", "Elisa", "Fábio",
                           "Gabi", "Hugo"};
    const char *hoje[] = {"Ana", "Carla", "Davi", "Igor", "Elisa", "Gabi",
                          "Hugo", "Júlia", "Kátia"};
    int m = 8, n = 9;

    int l = lcs_linhas(ontem, m, hoje, n);
    printf("%d iguais, %d removidas, %d adicionadas\n", l, m - l, n - l);
    printf("semelhança: %.1f%%\n", 100.0 * 2 * l / (m + n));
    return 0;
}
