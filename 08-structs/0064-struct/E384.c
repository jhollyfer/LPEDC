// 0064 · Struct
// Exercício E384 · ★★★
//
// As quatro structs abaixo guardam quase os mesmos campos, só que em ordens
// diferentes. Num PC de 64 bits (int com 4 bytes, double com 8), preveja o
// sizeof de cada uma, desenhando os bytes no papel. Depois escreva um
// programa que mostre o sizeof de cada uma e o offsetof de cada campo de
// struct a.
//
//   struct a { char ativo; int id; char nivel; };
//   struct b { int id; char ativo; char nivel; };
//   struct c { char ativo; double saldo; char nivel; };
//   struct d { double saldo; int id; char ativo; char nivel; };
//
// Dicas:
// 1. Cada campo começa num endereço múltiplo do próprio tamanho (char: 1,
//    int: 4, double: 8).
// 2. O tamanho total também é arredondado para um múltiplo do maior campo,
//    para que um vetor dessas structs continue alinhado.
// 3. offsetof(struct a, id) está em <stddef.h> e se mostra com %zu.
// 4. Resposta esperada: a = 12 (ativo 0, id 4, nivel 8), b = 8, c = 24 e
//    d = 16. Regra prática: declare do maior campo para o menor.
//
// Escreva sua resposta abaixo:

#include <stddef.h>
#include <stdio.h>

int main(void) {

    return 0;
}
