// 0178 · Hash: divisão e multiplicação
// Exercício E1064 · ★☆☆
//
// Escreva do zero, sem o espalha.h, mult(k, m), o método da multiplicação
// em ponto flutuante: h(k) = floor(m * (k*A mod 1)), com A = (raiz de 5 - 1)
// / 2 calculado com sqrt. Para k de 1 a 8 e m = 10, mostre k*A, a parte
// fracionária e o balde, com 4 casas.
//
//   Saída esperada:
//   k = 1: k*A = 0.6180 | fração 0.6180 | balde 6
//   k = 2: k*A = 1.2361 | fração 0.2361 | balde 2
//   k = 3: k*A = 1.8541 | fração 0.8541 | balde 8
//   k = 4: k*A = 2.4721 | fração 0.4721 | balde 4
//   k = 5: k*A = 3.0902 | fração 0.0902 | balde 0
//   k = 6: k*A = 3.7082 | fração 0.7082 | balde 7
//   k = 7: k*A = 4.3262 | fração 0.3262 | balde 3
//   k = 8: k*A = 4.9443 | fração 0.9443 | balde 9
//
// Dicas:
// 1. "mod 1" é tirar a parte inteira: produto - floor(produto).
// 2. A conversão (int) do m * fração já faz o floor (o valor é positivo).
// 3. Resposta esperada: a saída acima. Repare como chaves seguidas pulam
//    pela tabela inteira.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

int main(void) {

    return 0;
}
