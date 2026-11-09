// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1901 · ★☆☆ · Três sabores no pote
//
// A sorveteria da praça tem 5 sabores: açaí, cupuaçu, tapioca, graviola e
// buriti. O pote médio leva 3 sabores diferentes, e a ordem não importa
// (açaí + cupuaçu + tapioca é o mesmo pote que tapioca + açaí + cupuaçu).
// Escreva do zero a função recursiva combina(ini, k), que escolhe os
// sabores em ordem crescente de índice: cada chamada só olha sabores a
// partir de ini. Mostre todos os potes, numerados, e o total.
//
//   Saída esperada:
//    1: açaí cupuaçu tapioca
//    2: açaí cupuaçu graviola
//    3: açaí cupuaçu buriti
//    4: açaí tapioca graviola
//    5: açaí tapioca buriti
//    6: açaí graviola buriti
//    7: cupuaçu tapioca graviola
//    8: cupuaçu tapioca buriti
//    9: cupuaçu graviola buriti
//   10: tapioca graviola buriti
//   Total: 10 potes
//
// Dicas:
// 1. Guarde os índices escolhidos num vetor esc[3]. Quando já escolheu 3,
//    mostre e volte.
// 2. for (int i = ini; i < 5; i++) { esc[k] = i; combina(i + 1, k + 1); }.
//    Começar em i + 1 é o que impede repetir o mesmo pote em outra ordem.
// 3. Resposta esperada: 10 potes, que é C(5, 3) = 5! / (3! 2!).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
