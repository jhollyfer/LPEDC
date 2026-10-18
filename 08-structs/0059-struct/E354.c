// 0059 · Struct
// Exercício E354 · ★★★
//
// As quatro structs abaixo guardam quase os mesmos campos, só que em ordens
// diferentes. Escreva um programa que mostre o sizeof de cada uma e o
// offsetof de cada campo de struct a. Depois crie a struct a_enxuta, com os
// MESMOS três campos de struct a numa ordem que ocupe o mínimo possível, e
// mostre o sizeof dela.
//
//   struct a { char ativo; int id; char nivel; };
//   struct b { int id; char ativo; char nivel; };
//   struct c { char ativo; double saldo; char nivel; };
//   struct d { double saldo; int id; char ativo; char nivel; };
//
//   Saída esperada (num PC de 64 bits):
//   sizeof: a = 12, b = 8, c = 24, d = 16
//   struct a: ativo em 0, id em 4, nivel em 8
//   struct a_enxuta: 8 bytes
//
// Dicas:
// 1. Cada campo começa num endereço múltiplo do próprio tamanho (char: 1,
//    int: 4, double: 8). O tamanho total é arredondado para um múltiplo do
//    maior campo.
// 2. offsetof(struct a, id) está em <stddef.h> e se mostra com %zu.
// 3. Regra prática para a versão enxuta: do maior campo para o menor.
// 4. Resposta esperada: a saída acima; a_enxuta = { int id; char ativo;
//    char nivel; } (é a struct b com outro nome).
//
// Escreva sua resposta abaixo:

#include <stddef.h>
#include <stdio.h>

int main(void) {

    return 0;
}
