// 0007 · Aritmética
// Exercício E042 · ★★★
//
// Leia um número de 3 dígitos e mostre ao contrário, usando só / e %
// (nada de texto). O programa tem de funcionar também quando o número
// termina em zero: com 120, a saída é 021, sempre com três dígitos.
//
//   Exemplo de execução:
//   Número: 472
//   Ao contrário: 274
//
//   Exemplo de execução:
//   Número: 120
//   Ao contrário: 021
//
// Teste: printf '472\n' | ~/LPEDC/rodar E042.c e depois com '120\n'.
//
// Dicas:
// 1. n % 10 é o último dígito; n / 10 % 10 é o do meio; n / 100 é o
//    primeiro.
// 2. Monte o novo número: unidade * 100 + dezena * 10 + centena.
// 3. Com 120, o número invertido vale 21: zero à esquerda não existe num
//    int. Quem põe o zero é o printf: %03d.
// 4. Resposta esperada: 472 vira 274 e 120 vira 021.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
