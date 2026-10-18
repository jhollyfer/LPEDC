// 0040 · Caracteres
// Exercício E236 · ★☆☆
//
// Escreva um programa que chegue a cada resultado abaixo fazendo a CONTA com
// os caracteres. Vale usar 'a', 'C', '7' e companhia; não vale escrever o
// resultado pronto (nada de printf("b") ou do número 32 digitado).
//
//   1. A letra que vem depois de 'a'.
//   2. O valor numérico do caractere '7'.
//   3. O 'C' em minúscula, somando a distância entre 'a' e 'A' (sem tolower).
//   4. Se 'B' vem antes de 'a' na tabela: mostre "sim" ou "não".
//   5. toupper('5') e tolower('Q').
//   6. Quantas letras existem de 'a' até 'z'.
//
//   Saída esperada:
//   Depois de a: b
//   '7' vale 7
//   C em minúscula: c
//   'B' antes de 'a'? sim
//   toupper('5') = 5, tolower('Q') = q
//   Letras de a a z: 26
//
// Dicas:
// 1. 'a' é 97, 'A' é 65, '0' é 48. Um char entra em conta como qualquer int.
// 2. 'a' + 1 com %c mostra a letra; '7' - '0' com %d mostra o número.
// 3. Toda maiúscula vem ANTES de toda minúscula na tabela: 'B' < 'a' é
//    verdadeiro.
// 4. toupper de algo que não é letra devolve o mesmo caractere.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <ctype.h>

int main(void) {

    return 0;
}
