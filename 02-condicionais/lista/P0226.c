// Lista · Módulo 02 · Decisões
// Exercício P0226 · ★★★ · O caixa eletrônico com poucas notas
//
// O caixa eletrônico tem só 2 notas de R$ 50, 10 de R$ 20 e 3 de R$ 10.
// Escreva um programa que leia o valor do saque e pague com as notas maiores
// primeiro, sem passar do que existe de cada uma. Se não der para pagar o
// valor exato, mostre "Sem notas para esse valor." Sem laço: para cada nota,
// use = menor entre (resto / nota) e as notas que existem. Duas interações:
//
//   Saída esperada:
//   Saque: 290
//   2 x R$ 50
//   9 x R$ 20
//   1 x R$ 10
//
//   Saque: 380
//   Sem notas para esse valor.
//
// Dicas:
// 1. int usa50 = resto / 50 < 2 ? resto / 50 : 2; e depois resto -= usa50 * 50.
// 2. No fim, se o resto não for 0, faltaram notas.
// 3. Mostre só as notas que forem usadas (quantidade maior que 0).
// 4. Resposta esperada: 2 x 50, 9 x 20 e 1 x 10 para 290; sem notas para 380.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
