// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0504 · ★☆☆ · O estoque das duas lojas
//
// Uma rede de açaí tem duas lojas. Cada matriz 2x3 guarda os litros em
// estoque (linhas: polpa pura e com guaraná; colunas: tamanhos P, M e G):
//
//   int centro[2][3] = {{12, 20, 8}, {5, 9, 14}};
//   int bairro[2][3] = {{7, 3, 10}, {11, 6, 2}};
//
// Monte a matriz total[2][3] com a soma das duas (posição por posição) e
// mostre as três matrizes, cada número com %4d:
//
//   Saída esperada:
//   Centro:
//     12  20   8
//      5   9  14
//   Bairro:
//      7   3  10
//     11   6   2
//   Total:
//     19  23  18
//     16  15  16
//
// Dicas:
// 1. Soma de matrizes é feita casa a casa: total[i][j] = centro[i][j] +
//    bairro[i][j], com dois for aninhados.
// 2. Escreva void mostrar(const char titulo[], int m[2][3]) para não repetir
//    o laço de impressão três vezes.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int centro[2][3] = {{12, 20, 8}, {5, 9, 14}};
    int bairro[2][3] = {{7, 3, 10}, {11, 6, 2}};
    (void) centro, (void) bairro; // apague esta linha quando escrever

    return 0;
}
