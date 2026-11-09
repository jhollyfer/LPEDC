// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2916 · ★★☆ · Tabela de cortes e parênteses
//
// Seis matrizes têm dimensões p = 20, 40, 10, 6, 15, 30, 12 (Ai é
// p[i-1] x p[i]). Preencha m e s pela PD do 0185 (laço externo pelo
// tamanho da cadeia) e mostre a tabela s (só i < j; "-" no resto, cada
// casa com %3s ou %3d), o custo mínimo e a parentização ótima.
//
//   Saída esperada:
//   Tabela s:
//     -  1  1  3  3  3
//     -  -  2  3  3  3
//     -  -  -  3  3  3
//     -  -  -  -  4  5
//     -  -  -  -  -  5
//     -  -  -  -  -  -
//   Custo mínimo: 13500
//   Ordem: ((A1 (A2 A3)) ((A4 A5) A6))
//
// Dicas:
// 1. s[i][j] é o k do melhor corte entre Ak e Ak+1.
// 2. A parentização sai de uma função recursiva: se i == j mostre Ai; senão,
//    "(" + metade da esquerda + " " + metade da direita + ")".
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdio.h>

int main(void) {

    return 0;
}
