// 0172 · Vetor de tamanho variável (VLA)
// Exercício E1031 · ★★★

#include <stdio.h>

void multiplicar(int l, int m, int c, int a[l][m], int b[m][c], int r[l][c]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            r[i][j] = 0;
            for (int k = 0; k < m; k++) {
                r[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(void) {
    int quantidades[2][3] = {{10, 0, 5}, {2, 8, 4}};
    int precos[3][2] = {{3, 4}, {6, 5}, {2, 1}};
    int lojas = 2, produtos = 3, fornecedores = 2;
    int custo[lojas][fornecedores];

    multiplicar(lojas, produtos, fornecedores, quantidades, precos, custo);
    for (int i = 0; i < lojas; i++) {
        printf("loja %d: A = R$ %d, B = R$ %d -> melhor %c\n", i + 1, custo[i][0], custo[i][1],
               custo[i][0] <= custo[i][1] ? 'A' : 'B');
    }
    return 0;
}
