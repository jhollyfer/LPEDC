// 0034 · Parâmetros e passagem por valor
// Exercício E202 · ★★☆
//
// Você aplica R$ 1000.00 num investimento que rende 1% ao mês. Escreva
// "double montante(double capital, double taxa, int meses)" que usa o próprio
// parâmetro capital como acumulador: a cada mês, capital = capital * (1 + taxa / 100).
// No main, mostre o montante depois de 12 e de 24 meses e prove que a
// variável do main não mudou.
//
//   Saída esperada:
//   12 meses: R$ 1126.83
//   24 meses: R$ 1269.73
//   No main, capital continua R$ 1000.00
//
// Dicas:
// 1. O parâmetro é uma variável local como outra qualquer: pode mudar à vontade.
// 2. Um for de 1 até meses, multiplicando, e no fim return capital.
// 3. Resposta esperada: 1126.83 e 1269.73; o capital do main continua 1000.00,
//    porque a função mexeu só na cópia.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
