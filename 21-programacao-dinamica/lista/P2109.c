// Lista · Módulo 21 · Programação dinâmica
// Exercício P2109 · ★☆☆ · O maior trecho igual
//
// A LCS deixa pular letras. Às vezes você quer o maior trecho CONTÍGUO que
// aparece nas duas sequências: a MAIOR SUBSTRING COMUM. O laboratório
// comparou dois pedaços de DNA:
//
//   A: GATTACAGGT
//   B: TTACCAGGTA
//
// Escreva do zero a PD: s[i][j] é o tamanho do maior trecho comum que
// TERMINA em A[i - 1] e B[j - 1]. Se as letras são iguais, s[i][j] =
// s[i - 1][j - 1] + 1; se são diferentes, o trecho quebra: s[i][j] = 0.
// Guarde o maior valor e onde ele termina, e mostre o trecho.
//
//   Saída esperada:
//   Maior trecho comum: CAGGT (5 letras)
//
// Dicas:
// 1. A diferença para a LCS está só no "diferentes": aqui é 0, não o
//    máximo dos vizinhos.
// 2. Se o maior termina em A[fim - 1] com tamanho t, o trecho é A[fim - t ..
//    fim - 1]: printf("%.*s", t, a + fim - t).
// 3. Resposta esperada: CAGGT, com 5 letras (a LCS das duas é maior).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
