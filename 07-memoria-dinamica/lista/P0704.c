// Lista · Módulo 07 · Memória dinâmica
// Exercício P0704 · ★☆☆ · A identidade do tamanho que pedirem
//
// Escreva int **identidade(int n), que monta no heap uma matriz n x n (um
// vetor de n ponteiros, cada um apontando para uma linha alocada com calloc)
// com 1 na diagonal e 0 no resto, e void liberar(int **m, int n). No main,
// monte e mostre as identidades de tamanho 2 e 4 e libere as duas:
//
//   Saída esperada:
//   Identidade 2x2:
//   1 0
//   0 1
//   Identidade 4x4:
//   1 0 0 0
//   0 1 0 0
//   0 0 1 0
//   0 0 0 1
//
// Dicas:
// 1. int **m = malloc(n * sizeof *m); e, para cada linha, m[i] =
//    calloc(n, sizeof *m[i]); — o calloc já entrega a linha zerada.
// 2. Com a linha zerada, basta m[i][i] = 1.
// 3. Se o calloc de uma linha falhar, libere as linhas que já deram certo
//    e o vetor de ponteiros, e devolva NULL.
// 4. Ordem do free: primeiro cada linha, depois o vetor de ponteiros.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
