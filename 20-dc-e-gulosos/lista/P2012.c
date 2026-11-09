// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2012 · ★★☆ · As duas antenas mais próximas
//
// A operadora tem 8 antenas de celular num bairro, em coordenadas (em
// centenas de metros): (2, 3) (12, 30) (40, 50) (5, 1) (12, 10) (3, 4)
// (31, 33) (18, 21). Duas antenas muito perto se atrapalham. Qual é o PAR
// MAIS PRÓXIMO? A força bruta testa os 28 pares. Escreva do zero a divisão
// e conquista simples: ordene por x, divida ao meio, resolva cada metade,
// e depois olhe só os pontos da FAIXA a menos de d da linha do meio (d é a
// menor distância das metades), comparando cada um com os da faixa. Use
// força bruta quando houver 3 pontos ou menos. Mostre o par, a distância e
// quantas distâncias cada método calculou.
//
//   Saída esperada:
//   Força bruta: (2, 3) e (3, 4), 1.41, 28 distâncias
//   Divisão e conquista: (2, 3) e (3, 4), 1.41, 6 distâncias
//
// Dicas:
// 1. Ordene uma cópia com qsort por x. Trabalhe com a distância ao
//    quadrado (inteira) e tire a raiz só no fim, com sqrt de <math.h>.
// 2. Na faixa, monte um vetor com os pontos em que (x - xmeio)^2 < d e
//    compare-os dois a dois (com poucos pontos, a força bruta na faixa
//    basta; com muitos, ordene a faixa por y).
// 3. Resposta esperada: (2, 3) e (3, 4), distância 1.41 (raiz de 2).
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
