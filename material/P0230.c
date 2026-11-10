// Lista · Módulo 02 · Decisões
// Exercício P0230 · ★★★ · A senha de 4 dígitos do app
//
// O app do banco recusa senhas fracas de 4 dígitos (0000 a 9999). A senha é
// fraca se tiver os quatro dígitos iguais (7777), se for uma sequência
// crescente (1234, 3456) ou decrescente (9876), ou se parecer um ano entre
// 1950 e 2026. Escreva um programa que leia a senha como int, separe os
// dígitos com / e % e diga se ela é aceita ou qual regra ela quebrou (a
// primeira que falhar, nessa ordem). Três interações:
//
//   Saída esperada:
//   Senha: 1234
//   Senha fraca: sequência crescente
//
//   Senha: 1987
//   Senha fraca: parece um ano
//
//   Senha: 4071
//   Senha aceita
//
// Dicas:
// 1. d1 = s / 1000, d2 = s / 100 % 10, d3 = s / 10 % 10, d4 = s % 10.
// 2. Crescente: d2 == d1 + 1 && d3 == d2 + 1 && d4 == d3 + 1.
// 3. Confira primeiro se o scanf leu e se a senha está entre 0 e 9999.
// 4. Resposta esperada: as três saídas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
