// 0048 · Juntando tudo
// Exercício E286 · ★★☆
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
//   Exemplo de execução 1:
//   CPF: 529.982.247-25
//   CPF válido.
//
//   Exemplo de execução 2:
//   CPF: 529.982.247-26
//   CPF inválido.
//
// Dicas:
// 1. Guarde os dígitos como números num int d[11], usando c - '0'. Só guarde
//    enquanto houver lugar (contador < 11), mas continue contando.
// 2. Faça uma função int verificador(const int d[], int n) que usa os n
//    primeiros dígitos com pesos n + 1, n, ..., 2. Chame com n = 9 e n = 10.
// 3. Para o 529.982.247: a primeira soma dá 295, 295 % 11 = 9, e o dígito é 2.
// 4. Resposta esperada: as duas execuções acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
