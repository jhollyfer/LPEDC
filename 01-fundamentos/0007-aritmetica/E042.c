// 0007 · Aritmética
// Exercício E042 · ★★★
//
// Leia um número de 3 dígitos e mostre ao contrário, usando só / e %
// (nada de texto). Depois teste com 120: o que aparece? Como mostrar 021?
//
//   Exemplo de execução:
//   Número: 472
//   Ao contrário: 274
//
// Teste: printf '472\n' | ~/LPEDC/rodar E042.c
//
// Dicas:
// 1. n % 10 é o último dígito; n / 10 % 10 é o do meio; n / 100 é o
//    primeiro.
// 2. Monte o novo número: unidade * 100 + dezena * 10 + centena.
// 3. Resposta esperada: 472 vira 274. Com 120, o número invertido vale 21
//    (zero à esquerda não existe num int); para mostrar 021, use %03d.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
