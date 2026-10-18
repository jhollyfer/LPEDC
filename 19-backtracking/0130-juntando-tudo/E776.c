// 0130 · Juntando tudo
// Exercício E776 · ★☆☆
//
// Um aplicativo de sudoku mostra, em letra miúda, os candidatos de cada
// casa vazia: os dígitos que ainda podem entrar ali. O programa abaixo tem
// o jogo do texto e a função candidatos, que deve marcar em usado[] os
// dígitos que já aparecem na linha, na coluna e na caixa da casa (l, c).
// Falta o laço que faz essa marcação. Complete.
//
//   Saída esperada:
//   (0, 1): 5 7
//   (3, 1): 2 8
//   (4, 0): 3
//   (6, 0): 7 8 9
//   (8, 8): 4 7 9
//   (3, 8): 1 2 3 4 7 8 9
//
// Dicas:
// 1. Um laço só, com i de 0 a 8, marca três casas por volta: g[l][i] (a
//    linha), g[i][c] (a coluna) e uma casa da caixa.
// 2. A caixa começa em (l / 3 * 3, c / 3 * 3); a i-ésima casa dela fica i / 3
//    linhas abaixo e i % 3 colunas à direita.
// 3. Casas vazias valem 0 e marcam usado[0], que ninguém olha.
// 4. Resposta esperada: as 6 linhas acima. A casa (4, 0) tem candidato
//    único: um humano escreveria o 3 sem chutar nada.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdbool.h>
#include <stdio.h>

int g[9][9];

void candidatos(int l, int c) {
    bool usado[10] = {false};
    // complete: marque os dígitos da linha l, da coluna c e da caixa

    printf("(%d, %d):", l, c);
    for (int d = 1; d <= 9; d++) {
        if (!usado[d]) {
            printf(" %d", d);
        }
    }
    printf("\n");
}

int main(void) {
    const char *jogo[9] = {
        "2.3.8....", "6......7.", ".412.3.86",
        "5........", ".97.28...", "164.9...5",
        ".3...6...", "4.....2..", ".1.832.5.",
    };
    for (int l = 0; l < 9; l++) {
        for (int c = 0; c < 9; c++) {
            g[l][c] = jogo[l][c] == '.' ? 0 : jogo[l][c] - '0';
        }
    }
    int casas[6][2] = {{0, 1}, {3, 1}, {4, 0}, {6, 0}, {8, 8}, {3, 8}};
    for (int k = 0; k < 6; k++) {
        candidatos(casas[k][0], casas[k][1]);
    }
    return 0;
}
