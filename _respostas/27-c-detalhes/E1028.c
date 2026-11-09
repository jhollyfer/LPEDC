// 0172 · Vetor de tamanho variável (VLA)
// Exercício E1028 · ★☆☆

#include <stdio.h>

int soma_linha(int l, int c, int m[l][c], int i) {
    int soma = 0;
    for (int j = 0; j < c; j++) {
        soma += m[i][j];
    }
    return soma;
}

int soma_coluna(int l, int c, int m[l][c], int j) {
    int soma = 0;
    for (int i = 0; i < l; i++) {
        soma += m[i][j];
    }
    return soma;
}

int main(void) {
    int vendas[3][4] = {
        {10, 20, 30, 40},
        {5, 15, 25, 35},
        {8, 8, 8, 8},
    };
    for (int i = 0; i < 3; i++) {
        printf("loja %d: %d\n", i + 1, soma_linha(3, 4, vendas, i));
    }
    for (int j = 0; j < 4; j++) {
        printf("trimestre %d: %d\n", j + 1, soma_coluna(3, 4, vendas, j));
    }
    return 0;
}
