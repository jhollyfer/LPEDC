// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0528 · ★★★ · O sudoku 4x4 está certo?
//
// Um sudoku 4x4 está certo quando cada linha, cada coluna e cada um dos
// quatro quadrados 2x2 tem os números 1, 2, 3 e 4, sem repetir. Escreva
// bool valido(int s[4][4]), que mostra a PRIMEIRA regra quebrada (no formato
// da saída) e devolve false, ou devolve true se tudo estiver certo. Teste:
//
//   int a[4][4] = {{1, 2, 3, 4}, {3, 4, 1, 2}, {2, 1, 4, 3}, {4, 3, 2, 1}};
//   int b[4][4] = {{1, 2, 3, 4}, {3, 4, 1, 2}, {2, 1, 4, 3}, {4, 2, 3, 1}};
//   int c[4][4] = {{1, 2, 3, 4}, {2, 1, 4, 3}, {3, 4, 1, 2}, {4, 3, 2, 1}};
//
//   Saída esperada:
//   a:
//     certo
//   b:
//     erro na coluna 1
//     errado
//   c:
//     erro no quadrado 0
//     errado
//
// Dicas:
// 1. Escreva bool tem_1_a_4(int g[4]): marca num vetor bool visto[5] cada
//    número; se aparecer um fora de 1..4 ou repetido, false.
// 2. Para cada linha i, copie s[i][0..3] num vetor g e teste. Para cada
//    coluna j, copie s[0..3][j]. Para cada quadrado (q de 0 a 3), o canto é
//    linha (q / 2) * 2 e coluna (q % 2) * 2.
// 3. Teste nessa ordem (linhas, colunas, quadrados) e pare no primeiro erro.
// 4. Resposta esperada: a saída acima (b quebra a coluna 1; c só quebra um
//    quadrado, apesar das linhas e colunas certas).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int a[4][4] = {{1, 2, 3, 4}, {3, 4, 1, 2}, {2, 1, 4, 3}, {4, 3, 2, 1}};
    int b[4][4] = {{1, 2, 3, 4}, {3, 4, 1, 2}, {2, 1, 4, 3}, {4, 2, 3, 1}};
    int c[4][4] = {{1, 2, 3, 4}, {2, 1, 4, 3}, {3, 4, 1, 2}, {4, 3, 2, 1}};
    (void) a, (void) b, (void) c; // apague esta linha quando escrever

    return 0;
}
