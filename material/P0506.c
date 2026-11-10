// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0506 · ★☆☆ · É identidade?
//
// A matriz identidade tem 1 na diagonal principal e 0 em todo o resto.
// Escreva:
//
//   void montar_identidade(int m[4][4]);
//   bool eh_identidade(int m[4][4]);
//
// No main, monte a identidade 4x4 e mostre-a. Depois teste eh_identidade com
// ela e com a matriz abaixo (que tem um 1 fora do lugar), e mostre o
// resultado de cada teste:
//
//   int quase[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 1}, {0, 0, 1, 0}, {0, 0, 0, 1}};
//
//   Saída esperada:
//   1 0 0 0
//   0 1 0 0
//   0 0 1 0
//   0 0 0 1
//   id é identidade? sim
//   quase é identidade? não
//
// Dicas:
// 1. Na diagonal principal, a linha é igual à coluna: m[i][j] = (i == j).
// 2. Em eh_identidade, o valor esperado em cada casa também é (i == j): se
//    alguma casa for diferente disso, return false na hora.
// 3. Para mostrar o bool, use um operador ternário: ok ? "sim" : "não".
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
