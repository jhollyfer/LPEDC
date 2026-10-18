// 0140 · Mochila 0/1
// Exercício E839 · ★★★
//
// Resposta: a recuperação lia t[i - 1][c - peso[i]] sem conferir se o item
// cabe. Depois de levar o micro-ondas e a bicicleta, c fica 3, e o violão
// (4 kg) faz o índice virar -1: t[2][-1] sai da linha (o UBSan acusa) e,
// mais adiante, a TV com c = 0 leria t[0][-6], fora do bloco da tabela (o
// ASan para o programa). O conserto é testar peso[i] <= c antes, como na
// montagem da tabela.

#include <stdio.h>

#define N 5
#define W 10

int main(void) {
    const char *nome[N + 1] = {"", "TV", "notebook", "violão", "bicicleta", "micro-ondas"};
    int peso[N + 1] = {0, 6, 3, 4, 2, 5};
    int valor[N + 1] = {0, 50, 40, 30, 22, 35};
    int t[N + 1][W + 1];

    for (int c = 0; c <= W; c++) {
        t[0][c] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int c = 0; c <= W; c++) {
            t[i][c] = t[i - 1][c];
            if (peso[i] <= c && valor[i] + t[i - 1][c - peso[i]] > t[i][c]) {
                t[i][c] = valor[i] + t[i - 1][c - peso[i]];
            }
        }
    }
    printf("Valor máximo: R$ %d\n", t[N][W]);

    printf("Leva:");
    int c = W;
    for (int i = N; i >= 1; i--) {
        // o item i entrou se o valor da célula é "valor[i] + o resto"
        if (peso[i] <= c && t[i][c] == valor[i] + t[i - 1][c - peso[i]]) {
            printf(" %s", nome[i]);
            c -= peso[i];
        }
    }
    printf("\nSobrou: %d kg\n", c);
    return 0;
}
