// Lista · Módulo 25 · Estruturas especiais
// Exercício P2516 · ★★☆ · Mover para a frente contra a melhor ordem fixa
//
// O app do mercadinho mostra cinco produtos numa lista e procura do
// começo. Os 14 pedidos do dia estão no esqueleto. Compare três jeitos:
// - a ordem do cadastro, fixa: arroz feijao cafe leite pao;
// - a MELHOR ordem fixa, que só dá para montar sabendo o futuro: os mais
//   pedidos na frente (empate: a ordem do cadastro);
// - mover para a frente, que não sabe nada do futuro.
// Escreva do zero: mostre as frequências, a ordem ótima e o custo total
// (comparações) de cada jeito.
//
//   Saída esperada:
//   Frequências: arroz=3 feijao=3 cafe=1 leite=2 pao=5
//   Ordem ótima fixa: pao arroz feijao leite cafe
//   Ordem do cadastro: 45
//   Ordem ótima fixa: 33
//   Mover para a frente: 39
//
// Dicas:
// 1. Custo de achar x numa ordem = posição de x + 1. Some para os 14.
// 2. Para a ordem ótima, escolha 5 vezes o de maior frequência ainda não
//    usado (o primeiro, no empate).
// 3. Resposta esperada: cadastro 45, ótima 33, mover para a frente 39. O
//    MTF não ganha da ótima, mas se aproxima dela sem saber o futuro (o
//    Sleator e o Tarjan provaram: nunca passa do dobro).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define N 5
#define R 14

const char *nomes[N] = {"arroz", "feijao", "cafe", "leite", "pao"};
const char *pedidos[R] = {"pao", "pao", "pao", "leite", "leite", "cafe", "pao", "pao",
                          "arroz", "feijao", "arroz", "feijao", "arroz", "feijao"};

int main(void) {
    printf("%s %s\n", nomes[0], pedidos[0]);
    return 0;
}
