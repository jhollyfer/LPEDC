// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2624 · ★★★ · Laço que dobra dentro do laço
//
// Conte exatamente quantas vezes o x++ executa:
//
//   for (long i = 1; i < n; i++)
//       for (long j = 1; j <= i; j *= 2)
//           x++;
//
// O laço de dentro roda floor(log2 i) + 1 vezes. Para n potência de 2,
// n = 2^k, a soma dá (k - 1) * 2^k + 1. Escreva o programa com o contador e
// compare com a fórmula para k = 4, 10 e 16. Mostre também a razão
// x / (n log2 n):
//
//   Saída esperada:
//   n =     16: x =      49, fórmula      49, razão 0.766
//   n =   1024: x =    9217, fórmula    9217, razão 0.900
//   n =  65536: x =  983041, fórmula  983041, razão 0.938
//
// Dicas:
// 1. Agrupe os i que têm o mesmo floor(log2 i) = m: são 2^m valores, cada um
//    com m + 1 voltas.
// 2. Σ (m + 1) 2^m para m de 0 a k - 1 dá (k - 1) 2^k + 1. É Θ(n log n): a
//    razão vai para 1.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
