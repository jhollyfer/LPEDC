// 0041 · Strings
// Exercício E242 · ★☆☆
//
// Escreva um programa que mostre as seis linhas abaixo. Os números saem de
// strlen e sizeof, nunca digitados à mão.
//
//   1. Declare char s[10] = "pastel"; e mostre strlen e sizeof de s.
//   2. Mostre quantos bytes o literal "verde" ocupa (sizeof("verde")).
//   3. Faça s[4] = '\0'; e mostre s e o novo strlen.
//   4. Escreva void ordem(const char a[], const char b[]), que usa strcmp
//      para mostrar qual das duas vem antes, e chame com os três pares:
//      "abc" e "abd", "Zebra" e "abelha", "casa" e "casamento".
//
//   Saída esperada:
//   pastel: strlen 6, sizeof 10
//   "verde" ocupa 6 bytes
//   cortada: past (4)
//   abc vem antes de abd
//   Zebra vem antes de abelha
//   casa vem antes de casamento
//
// Dicas:
// 1. sizeof de um literal conta o '\0'; strlen não. Os dois devolvem size_t:
//    use %zu.
// 2. Para mostrar aspas dentro do printf, use \".
// 3. Em ordem, olhe só o sinal: strcmp(a, b) < 0 quer dizer que a vem antes.
//    'Z' é 90 e 'a' é 97; quando uma string acaba antes, o '\0' (0) é menor
//    que qualquer letra.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
