// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2022 · ★★★ · Strassen numa matriz 4 × 4
//
// O produto de matrizes n × n pela definição custa n³ multiplicações. Em
// 1969, Strassen dividiu cada matriz em quatro blocos n/2 × n/2 e mostrou
// que bastam SETE produtos de blocos, e não oito:
//
//   M1 = (A11 + A22)(B11 + B22)   M5 = (A11 + A12) B22
//   M2 = (A21 + A22) B11          M6 = (A21 - A11)(B11 + B12)
//   M3 = A11 (B12 - B22)          M7 = (A12 - A22)(B21 + B22)
//   M4 = A22 (B21 - B11)
//   C11 = M1 + M4 - M5 + M7       C12 = M3 + M5
//   C21 = M2 + M4                 C22 = M1 - M2 + M3 + M6
//
// Escreva do zero strassen(n, A, B, C) recursiva, com matrizes de tamanho
// variável (VLA: int a[n][n] como parâmetro), caso base n == 1, e conte as
// multiplicações de números. Multiplique as matrizes 4 × 4 do main pelos
// dois métodos e confira que dão o mesmo resultado.
//
//   Saída esperada:
//     14  10   5   5
//     10   7   5  12
//      9  11   7   9
//     12   3   9  14
//   Definição: 64 multiplicações
//   Strassen: 49 multiplicações
//   Resultados iguais
//
// Dicas:
// 1. Escreva auxiliares soma(n, x, y, r), subtrai(n, x, y, r), pega(n, m,
//    l0, c0, bloco) (copia um bloco) e poe(n, bloco, m, l0, c0).
// 2. Os blocos são VLAs locais int a11[h][h], com h = n / 2. Com n = 4 a
//    pilha aguenta folgada.
// 3. Resposta esperada: o produto de cima, 64 multiplicações na definição
//    e 49 no Strassen (7 · 7). Para n = 2^k, são 7^k contra 8^k: O(n^2,81).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
