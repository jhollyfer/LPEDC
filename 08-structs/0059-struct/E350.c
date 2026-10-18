// 0059 · Struct
// Exercício E350 · ★☆☆
//
// Copiar uma struct com = cria um placar novo, independente do original.
// Escreva um programa que prove isso. Crie a struct placar (campos casa e
// fora, int) e faça, nesta ordem:
//
//   1. a começa 2 x 1, e b é uma cópia de a (struct placar b = a;);
//   2. mude b.fora para 3 e some b.fora em a.casa;
//   3. mostre a e b;
//   4. crie c como cópia de b, zere os dois campos de c e mostre c e b.
//
//   Saída esperada:
//   a: 5 x 1
//   b: 2 x 3
//   c: 0 x 0
//   b: 2 x 3
//
// Dicas:
// 1. A cópia leva todos os campos de uma vez: struct placar b = a;
// 2. Depois da cópia, mudar b não muda a (e mudar c não muda b).
// 3. a.casa = a.casa + b.fora dá 2 + 3 = 5.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
