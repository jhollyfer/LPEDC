// A275 · Quantas rotas o entregador tem até o cliente

#include <stdio.h>

#define LIN 5
#define COL 6

// O entregador sai do cruzamento do canto de cima à esquerda e vai até o de
// baixo à direita, andando só para a direita (leste) ou para baixo (sul).
// Dois cruzamentos estão fechados por obra (marcados com 1).
int main(void) {
    int obra[LIN][COL] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
    };
    long long rotas[LIN][COL];

    // rotas[i][j] = de quantos jeitos se chega no cruzamento (i, j):
    // ou vindo de cima (i - 1, j), ou vindo da esquerda (i, j - 1)
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if (obra[i][j]) {
                rotas[i][j] = 0;              // ninguém passa por aqui
            } else if (i == 0 && j == 0) {
                rotas[i][j] = 1;              // a saída: um jeito, ficar parado
            } else {
                long long de_cima = (i > 0) ? rotas[i - 1][j] : 0;
                long long da_esquerda = (j > 0) ? rotas[i][j - 1] : 0;
                rotas[i][j] = de_cima + da_esquerda;
            }
        }
    }

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if (obra[i][j]) {
                printf("   X");
            } else {
                printf("%4lld", rotas[i][j]);
            }
        }
        printf("\n");
    }
    printf("Rotas até o cliente: %lld (sem as obras seriam 126)\n", rotas[LIN - 1][COL - 1]);
    return 0;
}
// Saída:
//    1   1   1   1   1   1
//    1   2   X   1   2   3
//    1   3   3   4   X   3
//    1   4   7  11  11  14
//    1   5  12  23  34  48
// Rotas até o cliente: 48 (sem as obras seriam 126)
