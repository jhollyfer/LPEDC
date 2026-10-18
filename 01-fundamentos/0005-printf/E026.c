// 0005 · printf
// Exercício E026 · ★☆☆
//
// Escreva os printf que produzem exatamente as quatro linhas abaixo. Os
// argumentos são dados: na linha 1, o 42 quatro vezes; na 2, o 3.14159 três
// vezes; na 3, o 'R' e três vezes o "Rio"; na 4, o 26 três vezes. Os
// colchetes vão fixos no formato, mas nenhum espaço e nenhum zero dentro
// deles pode ser digitado à mão: quem põe é o especificador.
//
//   Saída esperada:
//   [   42][42   ][00042][+42]
//   [3.1][3.142][    3.14]
//   [R][Rio][   Rio][Rio   ]
//   [1a][1A][32]
//
// Dicas:
// 1. Largura é o mínimo de casas; sem o -, o valor encosta na direita. O 0
//    completa com zeros e o + mostra o sinal.
// 2. Conte as casas de cada colchete: [    3.14] tem 8.
// 3. 26 = 16 + 10: em hexa, 1 e A (minúsculo com %x, maiúsculo com %X). Em
//    octal (%o), 26 = 3 * 8 + 2.
// 4. Resposta esperada: printf("[%5d][%-5d][%05d][%+d]\n", 42, 42, 42, 42);
//    e, nas outras, %.1f %.3f %8.2f; %c %s %6s %-6s; %x %X %o.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
