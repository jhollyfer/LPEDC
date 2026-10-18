// 0140 · Mochila 0/1
// Exercício E835 · ★☆☆

#include <stdio.h>

#define N 5
#define ORC 10 // orçamento, em milhares de reais

int main(void) {
    int custo[N + 1] = {0, 4, 3, 2, 5, 1};     // mil reais
    int retorno[N + 1] = {0, 9, 7, 4, 11, 2};  // mil reais por ano
    int t[N + 1][ORC + 1];

    for (int c = 0; c <= ORC; c++) {
        t[0][c] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int c = 0; c <= ORC; c++) {
            t[i][c] = t[i - 1][c];                             // não faz o projeto i
            if (custo[i] <= c && retorno[i] + t[i - 1][c - custo[i]] > t[i][c]) {
                t[i][c] = retorno[i] + t[i - 1][c - custo[i]]; // faz o projeto i
            }
        }
    }

    printf("última linha:");
    for (int c = 0; c <= ORC; c++) {
        printf(" %d", t[N][c]);
    }
    printf("\nRetorno máximo com R$ %d mil: R$ %d mil por ano\n", ORC, t[N][ORC]);
    return 0;
}
