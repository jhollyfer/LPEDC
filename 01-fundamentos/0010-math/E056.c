// 0010 · math.h
// Exercício E056 · ★☆☆
//
// Para cada situação, escolha a função do math.h que resolve e escreva um
// printf que mostre a linha com o resultado. Os números da conta vão como
// argumento da função (quem calcula é o programa). Mostre os resultados com
// %.0f, menos o saldo, com %.2f.
//
//   a) 13 pessoas, 4 por viagem do elevador: quantas viagens?
//   b) quem tem 34.9 anos tem quantos anos completos?
//   c) a nota 6.5 arredondada para o inteiro mais perto
//   d) o saldo de -42.75, sem o sinal
//   e) o lado de um quadrado de 144 m²
//   f) 2 elevado a 10
//   g) -3.2 graus, arredondado para baixo
//
//   Saída esperada:
//   a) 4 viagens
//   b) 34 anos
//   c) nota 7
//   d) R$ 42.75
//   e) 12 m
//   f) 1024
//   g) -4 graus
//
// Dicas:
// 1. floor desce na reta numérica; ceil sobe. Com negativo, "descer" é ir
//    para mais longe do zero.
// 2. round leva o meio (x.5) para longe do zero. Em a), cuidado: 13 / 4
//    entre dois int já sai cortado; use 13.0 / 4.
// 3. Resposta esperada: a) ceil(13.0 / 4); b) floor(34.9); c) round(6.5);
//    d) fabs(-42.75); e) sqrt(144); f) pow(2, 10); g) floor(-3.2). E as
//    sete linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <math.h>

int main(void) {

    return 0;
}
