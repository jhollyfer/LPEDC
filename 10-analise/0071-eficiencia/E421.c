// 0071 · Eficiência: contar passos
// Exercício E421 · ★☆☆
//
// Escreva um programa que monta cada trecho abaixo, conta com uma variável
// "passos" quantas vezes o passos++ roda e mostra o resultado. Zere o
// contador antes de cada trecho.
//
//   a) for (i = 0; i < 6; i++)  for (j = 0; j < 4; j++)  passos++;
//   b) for (i = 0; i < 6; i++)  for (j = i; j < 6; j++)  passos++;
//   c) for (i = 1; i < 100; i = i * 2)  passos++;
//   d) for (i = 0; i < 10; i++)  if (i % 3 == 0) passos++;
//
// No d), conte também as voltas do laço numa segunda variável, "voltas", e
// mostre as duas.
//
//   Saída esperada:
//   a) 24
//   b) 21
//   c) 7
//   d) 4 passos em 10 voltas
//
// Dicas:
// 1. Em a), o laço de dentro roda inteiro a cada volta do de fora: 6 * 4.
// 2. Em b), o laço de dentro encolhe porque começa em i: 6 + 5 + ... + 1.
// 3. Em c), os valores de i são 1, 2, 4, 8, 16, 32, 64.
// 4. Resposta esperada: a saída acima. O d) mostra que o número depende do
//    que você escolhe contar: 10 voltas, mas só 4 passam no if.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
