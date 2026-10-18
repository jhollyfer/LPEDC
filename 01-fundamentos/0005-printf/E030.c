// 0005 · printf
// Exercício E030 · ★★★
//
// Seis linhas, seis pegadinhas. Escreva um programa que mostre exatamente a
// saída abaixo usando, como argumento de cada printf, o valor indicado (e
// não o texto pronto):
//
//   linha 1: 3456.78
//   linha 2: "Brasília"
//   linha 3: 2.675, duas vezes
//   linha 4: 123456.0
//   linha 5: 0.0001 e 0.00001, com o mesmo especificador nos dois
//   linhas 6 e 7: "Pão" e o número que o printf do "Pão" devolveu
//
//   Saída esperada:
//   [3456.8]
//   [Bra]
//   [2.67] [2.67499999999999982236]
//   [1.234560e+05]
//   [0.0001] [1e-05]
//   Pão
//   [5]
//
// Dicas:
// 1. A largura é mínima, nunca corta: [3456.8] sai de %.1f, de %5.1f e até
//    de %1.1f. Já a precisão de um %s corta o texto.
// 2. 2.675 não existe exato em binário: o double guarda 2.67499999...,
//    por isso o %.2f mostra 2.67, e não 2.68. Com %.20f você vê o número
//    guardado.
// 3. O %g escolhe o formato mais curto e passa para o científico quando o
//    expoente fica menor que -4. O científico de sempre é o %e.
// 4. O printf devolve quantos BYTES escreveu: int n = printf("Pão\n");
//    O ã ocupa 2 bytes no UTF-8.
// 5. Resposta esperada: as sete linhas acima. A última vem de
//    printf("[%d]\n", n): P, ã (2 bytes), o e o \n somam 5.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
