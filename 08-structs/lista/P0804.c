// Lista · Módulo 08 · Tipos compostos
// Exercício P0804 · ★☆☆ · O carro e o tanque
//
// Crie typedef struct { char modelo[16]; double tanque, capacidade,
// km_por_litro, odometro; } Carro; e escreva duas funções que recebem um
// PONTEIRO para o carro e mexem nele com ->:
//
//   double abastecer(Carro *c, double litros);  // devolve quanto entrou
//   double rodar(Carro *c, double km);          // devolve quanto rodou
//
// abastecer não passa da capacidade; rodar gasta km / km_por_litro litros
// e, se o combustível acabar antes, roda só o que der. Comece com um Mobi
// (tanque 5 L, capacidade 47 L, 13.5 km/L, odômetro 10230) e faça: abastecer
// 50 L, rodar 300 km, rodar 400 km, abastecer 20 L.
//
//   Saída esperada:
//   Abasteceu 42.00 L
//     Mobi: tanque 47.00 L, odômetro 10230.0 km
//   Rodou 300.0 km
//     Mobi: tanque 24.78 L, odômetro 10530.0 km
//   Rodou 334.5 km
//     Mobi: tanque 0.00 L, odômetro 10864.5 km
//   Abasteceu 20.00 L
//     Mobi: tanque 20.00 L, odômetro 10864.5 km
//
// Dicas:
// 1. c->tanque é o mesmo que (*c).tanque.
// 2. Em abastecer: cabe = c->capacidade - c->tanque; entra o menor entre
//    litros e cabe.
// 3. Em rodar: o máximo possível é c->tanque * c->km_por_litro.
// 4. Escreva void painel(const Carro *c) para mostrar o estado depois de
//    cada operação.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
