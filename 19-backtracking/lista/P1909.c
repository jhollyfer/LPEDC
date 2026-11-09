// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1909 · ★☆☆ · Rainhas de 1 a 9
//
// O clube de xadrez vai pendurar um cartaz com o número de soluções das
// N-rainhas para cada tamanho de tabuleiro, de 1 a 9. O programa abaixo
// já tem os vetores de coluna e das duas diagonais e o laço do main. Falta
// o corpo de coloca(lin, n): para cada coluna livre, marque, desça para a
// próxima linha e desmarque. Monte a tabela.
//
//   Saída esperada:
//    N  soluções
//    1  1
//    2  0
//    3  0
//    4  2
//    5  10
//    6  4
//    7  40
//    8  92
//    9  352
//
// Dicas:
// 1. A diagonal "\" de (lin, col) é lin - col + n - 1; a "/" é lin + col.
//    Os dois índices cabem em 0..2n-2.
// 2. if (lin == n) { solucoes++; return; } e, no laço, pule a coluna se
//    col_ocup, d1 ou d2 estiver marcado.
// 3. Resposta esperada: 1, 0, 0, 2, 10, 4, 40, 92, 352. O 6 tem
//    menos soluções que o 5.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdbool.h>
#include <stdio.h>

#define MAX 9

bool col_ocup[MAX], d1[2 * MAX], d2[2 * MAX];
long solucoes;

void coloca(int lin, int n) {
    (void)lin;
    (void)n;
    // COMPLETE AQUI
}

int main(void) {
    printf(" N  soluções\n");
    for (int n = 1; n <= MAX; n++) {
        solucoes = 0;
        coloca(0, n);
        printf("%2d  %ld\n", n, solucoes);
    }
    return 0;
}
