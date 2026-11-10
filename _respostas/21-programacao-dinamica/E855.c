// 0143 · Juntando tudo: um mini-diff
// Exercício E855 · ★★☆

#include <stdio.h>
#include <string.h>

#define MAX 20

int main(void) {
    const char *antiga[] = {"#include <stdio.h>", "// versão 1", "int main(void) {",
                            "    printf(\"oi\\n\");", "    return 0;", "}"};
    const char *nova[] = {"#include <stdio.h>", "// versão 2", "int main(void) {",
                          "    int x = 2;", "    printf(\"%d\\n\", x);",
                          "    return 0;", "}"};
    int m = 6, n = 7;

    // c[i][j] = LCS de antiga[i..m-1] e nova[j..n-1] (sufixos, para a volta
    // andar do começo ao fim)
    int c[MAX + 1][MAX + 1];
    for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            if (i == m || j == n) {
                c[i][j] = 0;
            } else if (strcmp(antiga[i], nova[j]) == 0) {
                c[i][j] = c[i + 1][j + 1] + 1;
            } else {
                c[i][j] = c[i + 1][j] >= c[i][j + 1] ? c[i + 1][j] : c[i][j + 1];
            }
        }
    }

    int i = 0, j = 0, iguais = 0, menos = 0, mais = 0;
    while (i < m || j < n) {
        if (i < m && j < n && strcmp(antiga[i], nova[j]) == 0) {
            printf("%3d %3d   %s\n", i + 1, j + 1, antiga[i]);
            i++;
            j++;
            iguais++;
        } else if (j == n || (i < m && c[i + 1][j] >= c[i][j + 1])) {
            printf("%3d     - %s\n", i + 1, antiga[i]);
            i++;
            menos++;
        } else {
            printf("    %3d + %s\n", j + 1, nova[j]);
            j++;
            mais++;
        }
    }
    printf("(%d iguais, %d removidas, %d adicionadas)\n", iguais, menos, mais);
    return 0;
}
