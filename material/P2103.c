// Lista · Módulo 21 · Programação dinâmica
// Exercício P2103 · ★☆☆ · O carteiro e as ruas em obra
//
// O carteiro sai da agência no canto de cima à esquerda de um bairro em
// grade 5 × 6 e vai até a última casa, no canto de baixo à direita,
// andando só para a direita ou para baixo. As esquinas com X estão em
// obra e não dá para passar. Quantos caminhos ele tem? Complete o laço que
// preenche a tabela: cam[l][c] = cam[l - 1][c] + cam[l][c - 1], com 0 nas
// esquinas em obra. O programa mostra a tabela inteira.
//
//   . . . . . .
//   . X . . X .
//   . . . X . .
//   X . . . . .
//   . . X . . .
//
//   Saída esperada:
//      1   1   1   1   1   1
//      1   0   1   2   0   1
//      1   1   2   0   0   1
//      0   1   3   3   3   4
//      0   1   0   3   6  10
//   Caminhos: 10
//
// Dicas:
// 1. A partida vale 1 (se não estiver em obra). Na primeira linha e na
//    primeira coluna, só há um vizinho de onde vir.
// 2. Trate fora da grade como 0: if (l > 0) soma o de cima; if (c > 0)
//    soma o da esquerda.
// 3. Resposta esperada: 10 caminhos. A esquina (3, 0) em obra zera toda a
//    coluna 0 abaixo dela.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define L 5
#define C 6

const char mapa[L][C + 1] = {
    "......",
    ".X..X.",
    "...X..",
    "X.....",
    "..X...",
};

int main(void) {
    long cam[L][C];
    for (int l = 0; l < L; l++) {
        for (int c = 0; c < C; c++) {
            cam[l][c] = 0; // COMPLETE AQUI
        }
    }
    for (int l = 0; l < L; l++) {
        for (int c = 0; c < C; c++) {
            printf("%4ld", cam[l][c]);
        }
        printf("\n");
    }
    printf("Caminhos: %ld\n", cam[L - 1][C - 1]);
    return 0;
}
