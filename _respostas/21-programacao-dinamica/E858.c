// 0143 · Juntando tudo: um mini-diff
// Exercício E858 · ★★★

#include <stdio.h>
#include <string.h>

#define MAX 30
#define CONTEXTO 1

int main(void) {
    const char *a[] = {"1. Pré-aqueça o forno a 180 graus.",
                       "2. Unte a forma com manteiga.",
                       "3. Bata 3 ovos com 2 xícaras de açúcar.",
                       "4. Junte 1 xícara de leite.",
                       "5. Acrescente 3 xícaras de farinha.",
                       "6. Misture até ficar liso.",
                       "7. Coloque 1 colher de fermento.",
                       "8. Despeje na forma.",
                       "9. Asse por 40 minutos.",
                       "10. Espere esfriar.",
                       "11. Desenforme.",
                       "12. Sirva."};
    const char *b[] = {"1. Pré-aqueça o forno a 180 graus.",
                       "2. Unte a forma com manteiga.",
                       "3. Bata 3 ovos com 1 xícara de açúcar.",
                       "4. Junte 1 xícara de leite.",
                       "5. Acrescente 3 xícaras de farinha.",
                       "6. Misture até ficar liso.",
                       "7. Coloque 1 colher de fermento.",
                       "8. Despeje na forma.",
                       "9. Asse por 40 minutos.",
                       "10. Espere esfriar.",
                       "11. Desenforme.",
                       "12. Cubra com calda de chocolate.",
                       "13. Sirva."};
    int m = 12, n = 13;

    int c[MAX + 1][MAX + 1]; // LCS dos sufixos
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

    // 1ª passada: a lista de operações (' ', '-', '+') e o texto de cada uma
    char op[2 * MAX];
    const char *texto[2 * MAX];
    int k = 0, i = 0, j = 0;
    while (i < m || j < n) {
        if (i < m && j < n && strcmp(a[i], b[j]) == 0) {
            op[k] = ' ';
            texto[k++] = a[i];
            i++;
            j++;
        } else if (j == n || (i < m && c[i + 1][j] >= c[i][j + 1])) {
            op[k] = '-';
            texto[k++] = a[i++];
        } else {
            op[k] = '+';
            texto[k++] = b[j++];
        }
    }

    // 2ª passada: mostra só as mudanças e CONTEXTO linhas iguais em volta
    int ultimo = -1; // índice da última operação mostrada
    for (int t = 0; t < k; t++) {
        int perto = 0;
        for (int d = t - CONTEXTO; d <= t + CONTEXTO; d++) {
            if (d >= 0 && d < k && op[d] != ' ') {
                perto = 1;
            }
        }
        if (!perto) {
            continue;
        }
        if (t > ultimo + 1) {
            printf("...\n"); // pulou linhas iguais
        }
        printf("%c %s\n", op[t], texto[t]);
        ultimo = t;
    }
    if (ultimo < k - 1) {
        printf("...\n");
    }
    return 0;
}
