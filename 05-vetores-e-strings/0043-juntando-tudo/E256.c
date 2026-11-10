// 0043 · Juntando tudo
// Exercício E256 · ★★☆
//
// Valide um CPF digitado com fgets, com ou sem pontuação ("529.982.247-25"
// ou "52998224725"). Os dois últimos dígitos são verificadores, calculados a
// partir dos 9 primeiros:
//
//   1º verificador: multiplique os 9 primeiros dígitos por 10, 9, 8, ..., 2
//   e some. Seja r o resto da soma por 11. Se r < 2, o dígito é 0; senão,
//   é 11 - r.
//   2º verificador: o mesmo com os 10 primeiros dígitos (os 9 + o 1º
//   verificador), multiplicados por 11, 10, ..., 2.
//
// O CPF é válido se tiver exatamente 11 dígitos (ignore '.' e '-'; qualquer
// outro caractere invalida), se os verificadores baterem e se os 11 dígitos
// NÃO forem todos iguais (111.111.111-11 passa na conta, mas não vale).
//
//   Entrada:
//   529.982.247-25
//
//   Saída esperada:
//   CPF válido.
//
//   Entrada:
//   529.982.247-26
//
//   Saída esperada:
//   CPF inválido.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
