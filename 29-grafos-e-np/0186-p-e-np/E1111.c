// 0186 · P e NP
// Exercício E1111 · ★☆☆
//
// A padaria decide o fim de semana com três variáveis: x1 = abrir sábado,
// x2 = abrir domingo, x3 = contratar um folguista. As regras, em FNC:
//
//   (x1 ou x2)                     abre pelo menos um dia
//   (não x1 ou x3)                 abrir sábado exige folguista
//   (não x2 ou x3)                 abrir domingo também
//   (não x1 ou não x2 ou não x3)   o caixa não fecha com os três
//
// Escreva o verificador int primeira_falsa(const bool x[]), que devolve 0
// se a atribuição satisfaz a fórmula ou o número (1 a 4) da primeira
// cláusula falsa, e a função testa(numero, x), que mostra o resultado.
// Guarde a fórmula como int formula[4][3] no formato +v / -v, com 0
// sobrando nas cláusulas de dois literais. Teste três atribuições
// (x1, x2, x3): (sim, não, sim), (sim, sim, sim) e (não, sim, não).
//
//   Saída esperada:
//   Atribuição 1: satisfaz
//   Atribuição 2: não satisfaz (cláusula 4 falsa)
//   Atribuição 3: não satisfaz (cláusula 3 falsa)
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
