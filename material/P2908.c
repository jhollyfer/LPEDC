// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2908 · ★☆☆ · Custo de uma ordem de multiplicação
//
// Cinco matrizes têm dimensões p = 6, 2, 9, 4, 7, 3 (Ai é p[i-1] x p[i]).
// Calcule, com uma função long custo_esq(int i, int j) e outra
// long custo_dir(int i, int j), o número de multiplicações das duas ordens
// "ingênuas": da esquerda para a direita, ((((A1 A2) A3) A4) A5), e da
// direita para a esquerda, (A1 (A2 (A3 (A4 A5)))). Mostre também as
// dimensões do resultado.
//
//   Saída esperada:
//   Resultado: 6 x 3
//   Da esquerda: 618
//   Da direita: 282
//
// Dicas:
// 1. Da esquerda: o acumulado é sempre p[0] x p[k]; juntar com A(k+1) custa
//    p[0] · p[k] · p[k+1].
// 2. Da direita: o acumulado é p[k-1] x p[5]; juntar A(k-1) na frente custa
//    p[k-2] · p[k-1] · p[5].
// 3. Resposta esperada: a saída acima. Nenhuma das duas é a ótima: a PD do
//    0185 acha uma ordem com 206 multiplicações.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
