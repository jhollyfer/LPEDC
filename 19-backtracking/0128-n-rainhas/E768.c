// 0128 · N-rainhas
// Exercício E768 · ★★★
//
// O passeio do cavalo: num tabuleiro 5 × 5, o cavalo começa no canto (0, 0)
// e precisa visitar as 25 casas, cada uma uma vez só, saltando em L. Escreva
// do zero um backtracking que ache o primeiro passeio, numerando as casas na
// ordem da visita (o canto é 1), e conte as chamadas da função recursiva.
// Tente os 8 saltos sempre nesta ordem (linha, coluna):
//
//   (+2, +1) (+1, +2) (-1, +2) (-2, +1) (-2, -1) (-1, -2) (+1, -2) (+2, -1)
//
//   Saída esperada:
//     1  6 15 10 21
//    14  9 20  5 16
//    19  2  7 22 11
//     8 13 24 17  4
//    25 18  3 12 23
//   8840 chamadas
//
// Dicas:
// 1. Guarde os saltos em dois vetores, dl[8] e dc[8]. A matriz casa[5][5]
//    começa com 0 (livre) e recebe o número do salto.
// 2. salta(l, c, k): o cavalo está em (l, c), a casa de número k. Se k é 25,
//    achou. Senão, para cada salto que cai dentro do tabuleiro numa casa
//    livre: numere com k + 1, desça, e se não deu certo, volte a casa para 0.
// 3. Pare na primeira solução devolvendo bool, como no exemplo A256. Cada
//    número sai com printf("%3d", ...).
// 4. Resposta esperada: o tabuleiro e a contagem acima. Confira no papel
//    que cada passo de k para k + 1 é mesmo um L.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
