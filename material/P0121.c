// Lista · Módulo 01 · Fundamentos de C
// Exercício P0121 · ★★★ · Os dígitos verificadores do CPF
//
// O CPF tem 9 dígitos e 2 verificadores. O 1º verificador: multiplique os 9
// dígitos pelos pesos 10, 9, 8, ..., 2, some e pegue o resto r da divisão por
// 11; se r < 2 o dígito é 0, senão é 11 − r. O 2º usa os 9 dígitos mais o 1º
// verificador, com pesos 11, 10, ..., 2, e a mesma regra. Escreva um programa
// que, sem if, calcule os verificadores de 123456789 e mostre o CPF formatado:
//
//   Saída esperada:
//   Soma 1: 210, resto 1, dígito 0
//   Soma 2: 255, resto 2, dígito 9
//   CPF: 123.456.789-09
//
// Dicas:
// 1. Separe os dígitos com / e % (d1 = n / 100000000, d2 = n / 10000000 % 10,
//    ... d9 = n % 10).
// 2. Truque sem if: (11 - r) % 11 % 10. Com r = 0 dá 0, com r = 1 dá 10 % 10 =
//    0, e com r de 2 a 10 dá 11 − r.
// 3. Para formatar: n / 1000000, n / 1000 % 1000 e n % 1000, com %03d.
// 4. Resposta esperada: CPF: 123.456.789-09.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
