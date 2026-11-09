// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1912 · ★★☆ · Quantos horários de prova?
//
// A coordenação do curso vai marcar as provas finais de 6 disciplinas.
// Duas disciplinas com algum aluno em comum não podem ter prova no mesmo
// horário. Os conflitos são:
//
//   Cálculo - Física      Cálculo - Álgebra     Cálculo - Programação
//   Física - Química      Física - Programação  Álgebra - Programação
//   Química - Inglês      Programação - Inglês
//
// Qual é o MENOR número de horários que resolve? Escreva do zero: para k =
// 1, 2, 3..., tente colorir o grafo com k cores por backtracking (a cor é o
// horário) e pare no primeiro k que dá certo. Mostre cada tentativa e, no
// fim, a grade de horários achada.
//
//   Saída esperada:
//   1 horário(s): não dá
//   2 horário(s): não dá
//   3 horários: dá
//   Horário 1: Cálculo Química
//   Horário 2: Física Álgebra Inglês
//   Horário 3: Programação
//
// Dicas:
// 1. colore(v, k) devolve 1 se conseguiu pintar de v até o fim com cores 0
//    a k - 1. Na primeira coloração que fecha, devolva 1 sem desfazer: a cor[]
//    fica com a resposta.
// 2. Cálculo, Física e Programação são vizinhas duas a duas (um triângulo):
//    com 2 cores não dá, e o programa tem que descobrir isso sozinho.
// 3. Resposta esperada: 3 horários (o número cromático do grafo é 3).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
