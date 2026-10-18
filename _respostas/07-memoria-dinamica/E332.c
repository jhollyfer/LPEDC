// 0056 · Matriz dinâmica
// Exercício E332 · ★☆☆

#include <stdio.h>
#include <stdlib.h>

int indice(int i, int j, int colunas) {
    return i * colunas + j;
}

void posicao(int k, int colunas, int *i, int *j) {
    *i = k / colunas;
    *j = k % colunas;
}

int main(void) {
    int linhas = 5;
    int colunas = 8;
    int *v = malloc(linhas * colunas * sizeof *v);
    if (v == NULL) {
        return 1;
    }
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            v[indice(i, j, colunas)] = i * 10 + j;
        }
    }

    int casos[3][2] = {{2, 3}, {4, 7}, {0, 5}};
    for (int c = 0; c < 3; c++) {
        int k = indice(casos[c][0], casos[c][1], colunas);
        printf("(%d, %d) -> índice %d, valor %d\n", casos[c][0], casos[c][1], k, v[k]);
    }
    int i, j;
    posicao(26, colunas, &i, &j);
    printf("índice 26 -> (%d, %d), valor %d\n", i, j, v[26]);

    free(v);
    return 0;
}
// Saída:
// (2, 3) -> índice 19, valor 23
// (4, 7) -> índice 39, valor 47
// (0, 5) -> índice 5, valor 5
// índice 26 -> (3, 2), valor 32
