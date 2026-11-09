// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2019 · ★★☆ · Rotas de ônibus com potência de matriz
//
// Quatro terminais de ônibus (T0 a T3) são ligados por linhas diretas,
// dadas pela matriz de adjacência A (A[i][j] = 1 se há linha de Ti para
// Tj). Um fato bonito: o elemento (i, j) de A^k conta quantas rotas de
// EXATAMENTE k trechos vão de Ti a Tj. Calcule A^k pela potência rápida
// (assunto 0131), trocando a multiplicação de números pela de matrizes 4 ×
// 4, e mostre quantas rotas de T0 a T3 existem com 3, 6 e 12 trechos, e
// quantos produtos de matriz cada potência custou.
//
//   A = | 0 1 1 0 |
//       | 1 0 1 1 |
//       | 1 1 0 1 |
//       | 0 1 1 0 |
//
//   Saída esperada:
//    3 trechos: 2 rotas de T0 a T3 (4 produtos)
//    6 trechos: 58 rotas de T0 a T3 (5 produtos)
//   12 trechos: 15178 rotas de T0 a T3 (6 produtos)
//
// Dicas:
// 1. Um typedef struct { long long m[4][4]; } Mat; facilita devolver
//    matriz de função. A identidade é o caso base (k = 0).
// 2. potencia(A, k): meia = potencia(A, k / 2); r = meia · meia; se k é
//    ímpar, r = r · A. Conte cada chamada de multiplica.
// 3. Resposta esperada: com 3 trechos são 5 rotas (por exemplo, T0 T1 T2
//    T3); os outros valores estão na saída.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
