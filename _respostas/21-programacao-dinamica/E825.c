// 0138 · Memoização
// Exercício E825 · ★★☆

#include <stdio.h>

#define LIN 4
#define COL 5

int main(void) {
    int pedagio[LIN][COL] = {
        {3, 1, 4, 2, 5},
        {2, 7, 1, 8, 2},
        {6, 1, 3, 2, 4},
        {5, 2, 9, 1, 3},
    };
    int custo[LIN][COL]; // custo[i][j] = menor gasto da saída até (i, j), inclusive

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == 0 && j == 0) {
                custo[i][j] = pedagio[i][j];
            } else if (i == 0) {
                custo[i][j] = custo[i][j - 1] + pedagio[i][j]; // só dá para vir da esquerda
            } else if (j == 0) {
                custo[i][j] = custo[i - 1][j] + pedagio[i][j]; // só dá para vir de cima
            } else {
                int cima = custo[i - 1][j];
                int esq = custo[i][j - 1];
                custo[i][j] = (cima < esq ? cima : esq) + pedagio[i][j];
            }
        }
    }
    printf("Menor custo: R$ %d\n", custo[LIN - 1][COL - 1]);

    // volta do fim para o começo, sempre pelo vizinho mais barato
    char passos[LIN + COL];
    int n = 0, i = LIN - 1, j = COL - 1;
    while (i > 0 || j > 0) {
        if (i == 0) {
            passos[n++] = 'D';
            j--;
        } else if (j == 0) {
            passos[n++] = 'B';
            i--;
        } else if (custo[i - 1][j] <= custo[i][j - 1]) {
            passos[n++] = 'B'; // cheguei aqui descendo
            i--;
        } else {
            passos[n++] = 'D'; // cheguei aqui indo para a direita
            j--;
        }
    }
    printf("Caminho: ");
    for (int k = n - 1; k >= 0; k--) {
        printf("%c", passos[k]);
    }
    printf("\n");
    return 0;
}
