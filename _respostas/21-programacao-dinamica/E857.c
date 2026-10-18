// 0143 · Juntando tudo: um mini-diff
// Exercício E857 · ★★★
//
// Resposta: o malloc reservava m * n = 30 int (120 bytes), mas a tabela dos
// sufixos tem uma linha e uma coluna a mais, (m + 1) x (n + 1) = 42
// células, e o índice i * w + j chega a 41. A primeira escrita, em
// c[5 * 7 + 6], já caía fora do bloco. Conserto: reservar (m + 1) * w int.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// diff de dois vetores de linhas, com a tabela dos sufixos num bloco do malloc
int compara_versoes(const char *a[], int m, const char *b[], int n) {
    int w = n + 1;
    int *c = malloc((size_t) (m + 1) * w * sizeof *c);
    if (c == NULL) {
        return 1;
    }
    for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            if (i == m || j == n) {
                c[i * w + j] = 0;
            } else if (strcmp(a[i], b[j]) == 0) {
                c[i * w + j] = c[(i + 1) * w + j + 1] + 1;
            } else {
                int baixo = c[(i + 1) * w + j], dir = c[i * w + j + 1];
                c[i * w + j] = baixo >= dir ? baixo : dir;
            }
        }
    }
    int i = 0, j = 0;
    while (i < m || j < n) {
        if (i < m && j < n && strcmp(a[i], b[j]) == 0) {
            printf("  %s\n", a[i]);
            i++;
            j++;
        } else if (j == n || (i < m && c[(i + 1) * w + j] >= c[i * w + j + 1])) {
            printf("- %s\n", a[i++]);
        } else {
            printf("+ %s\n", b[j++]);
        }
    }
    free(c);
    return 0;
}

int main(void) {
    const char *ida[] = {"Terminal", "Centro", "Hospital", "Universidade", "Praia"};
    const char *nova[] = {"Terminal", "Mercado", "Centro", "Universidade",
                          "Praia", "Aeroporto"};
    printf("Itinerário da linha 42:\n");
    return compara_versoes(ida, 5, nova, 6);
}
