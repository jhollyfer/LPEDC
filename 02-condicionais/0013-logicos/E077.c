// 0013 · Lógicos: E, OU, NÃO
// Exercício E077 · ★★★
//
// Curto-circuito com efeito colateral. Preveja os cinco números que este
// trecho mostra. Atenção: a++ entrega o valor ANTIGO e só depois soma 1
// (assunto 0009), mas só se aquela parte da expressão for avaliada!
//
//   int a = 0, b = 0;
//   bool r1 = (a++ > 0) && (b++ > 0);
//   bool r2 = (a++ > 0) || (b++ > 0);
//   bool r3 = (b++ > 0) || (a++ > 5);
//   printf("%d %d %d %d %d\n", r1, r2, r3, a, b);
//
// Dicas:
// 1. Faça um teste de mesa com as colunas a, b, r1, r2, r3.
// 2. Em r1, a primeira parte é 0 > 0. Precisa olhar a segunda? Em r2, a
//    primeira parte é 1 > 0. Precisa olhar a segunda?
// 3. Resposta esperada: 0 1 0 3 1 (o b++ de r1 e o de r2 nunca rodam).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
