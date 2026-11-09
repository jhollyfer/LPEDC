// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1029 · ★★★ · O lado do terreno por busca binária
//
// Um terreno quadrado tem área A m². Qual o maior lado inteiro L com
// L · L <= A (a raiz quadrada inteira)? Sem math.h, escreva:
//
//   long long raiz_linear(long long a, long *passos)
//     testa L = 0, 1, 2, ... enquanto (L + 1)² <= a; 1 passo por teste;
//   long long raiz_binaria(long long a, long *passos)
//     com lo = 0 e hi = a + 1 e o invariante lo² <= a < hi², enquanto
//     hi - lo > 1: meio = lo + (hi - lo) / 2; se meio² <= a, lo = meio;
//     senão, hi = meio. 1 passo por volta. A resposta é lo.
//
// Ponha o invariante num assert no começo de cada volta da binária. Teste
// com A = 50, 1000000 e 2000000000.
//
//   Saída esperada:
//   A = 50: lado 7 | linear 8 passos | binária 6 passos
//   A = 1000000: lado 1000 | linear 1001 passos | binária 20 passos
//   A = 2000000000: lado 44721 | linear 44722 passos | binária 31 passos
//
// Dicas:
// 1. Use long long em tudo: com a = 2 bilhões, hi² passa de 4 · 10¹⁸, que
//    ainda cabe (o limite é cerca de 9,2 · 10¹⁸). Para conferir o
//    invariante no assert sem estourar, escreva hi > a / hi no lugar de
//    hi * hi > a.
// 2. O invariante no fim (hi - lo == 1) diz lo² <= a < (lo + 1)²: lo é
//    exatamente a raiz inteira.
// 3. A linear é O(√A); a binária é O(log A).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <assert.h>
#include <stdio.h>

int main(void) {

    return 0;
}
