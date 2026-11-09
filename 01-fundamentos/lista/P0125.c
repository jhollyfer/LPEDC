// Lista · Módulo 01 · Fundamentos de C
// Exercício P0125 · ★★★ · O byte escrito com zeros e uns
//
// O manual do sensor diz que o registro de configuração deve receber o byte
// 10110110. Guarde isso num int como se fosse decimal (int bits = 10110110;),
// separe cada "dígito" com / e % por 10, monte o valor de verdade com os pesos
// 128, 64, ..., 1 e mostre em decimal, hexadecimal e octal:
//
//   Saída esperada:
//   Bits: 10110110
//   Decimal: 182
//   Hexadecimal: 0xB6
//   Octal: 0266
//
// Dicas:
// 1. O bit mais à esquerda é bits / 10000000 % 10 e vale 128; o mais à direita
//    é bits % 10 e vale 1.
// 2. %X mostra em hexadecimal maiúsculo e %o em octal.
// 3. Resposta esperada: 182, 0xB6 e 0266.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
