// 0128 · N-rainhas
// Exercício E763 · ★☆☆
//
// Antes de resolver o tabuleiro inteiro, o clube quer um juiz: uma função
//
//   bool ataca(int l1, int c1, int l2, int c2)
//
// que diz se duas rainhas, nas casas (l1, c1) e (l2, c2) de um tabuleiro
// 8 × 8, se atacam (mesma linha, mesma coluna ou mesma diagonal). Escreva a
// função do zero e teste com os seis pares do programa.
//
//   Saída esperada:
//   (0, 0) e (3, 3): ataca
//   (1, 2) e (3, 1): não ataca
//   (2, 5) e (2, 0): ataca
//   (4, 1) e (1, 4): ataca
//   (0, 3) e (5, 3): ataca
//   (6, 2) e (3, 0): não ataca
//
// Dicas:
// 1. Linha e coluna são comparações diretas.
// 2. Nas diagonais, a distância entre as linhas é igual à distância entre
//    as colunas: abs(l1 - l2) == abs(c1 - c2) (abs vem de stdlib.h).
// 3. Outro jeito: mesma diagonal ↗ quando l1 + c1 == l2 + c2, e mesma ↘
//    quando l1 - c1 == l2 - c2. Os dois jeitos dão o mesmo resultado.
// 4. Resposta esperada: as 6 linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int pares[6][4] = {
        {0, 0, 3, 3}, {1, 2, 3, 1}, {2, 5, 2, 0},
        {4, 1, 1, 4}, {0, 3, 5, 3}, {6, 2, 3, 0},
    };
    (void)pares; // apague esta linha quando usar o vetor

    return 0;
}
