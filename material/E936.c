// 0156 · Juntando tudo: o assistente do calouro
// Exercício E936 · ★★★
//
// O entregador sai da Loja, visita os três clientes do dia (Ana, Bruno e Carla)
// em alguma ordem e volta para a Loja. Os pontos (índices 0 a 5) são Loja, Ana,
// Bruno, Carla, Praça e Ponte; Praça e Ponte servem só de passagem. As ruas, de
// mão dupla, em minutos:
//
//   Loja-Praça 4, Loja-Ponte 6, Praça-Ana 3, Praça-Bruno 5, Ponte-Carla 2,
//   Ana-Bruno 4, Bruno-Carla 3, Ana-Ponte 7, Loja-Carla 12
//
// Rode o Floyd-Warshall para ter o tempo entre quaisquer dois pontos e depois
// teste TODAS as ordens de visita (as permutações por troca do assunto 0126),
// mostrando cada roteiro com o tempo total e, no fim, o melhor (o primeiro de
// menor tempo).
//
//   Saída esperada:
//   Loja -> Ana -> Bruno -> Carla -> Loja: 22 min
//   Loja -> Ana -> Carla -> Bruno -> Loja: 26 min
//   Loja -> Bruno -> Ana -> Carla -> Loja: 28 min
//   Loja -> Bruno -> Carla -> Ana -> Loja: 26 min
//   Loja -> Carla -> Bruno -> Ana -> Loja: 22 min
//   Loja -> Carla -> Ana -> Bruno -> Loja: 28 min
//   Melhor roteiro (22 min): Loja -> Ana -> Bruno -> Carla -> Loja
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define INFINITO 1000000000

int main(void) {

    return 0;
}
