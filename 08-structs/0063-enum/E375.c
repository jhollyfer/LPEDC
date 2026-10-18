// 0063 · Enum
// Exercício E375 · ★★☆
//
// Jokenpô! Crie os enums Jogada { PEDRA, PAPEL, TESOURA } e
// Resultado { EMPATE, VITORIA, DERROTA }. Escreva
// Resultado jogar(Jogada voce, Jogada outro) e rode as 5 partidas abaixo,
// mostrando o placar no fim.
//
//   voce     x outro
//   pedra    x tesoura
//   papel    x tesoura
//   tesoura  x tesoura
//   papel    x pedra
//   pedra    x papel
//
//   Saída esperada:
//   pedra x tesoura: vitória
//   papel x tesoura: derrota
//   tesoura x tesoura: empate
//   papel x pedra: vitória
//   pedra x papel: derrota
//   Placar: 2 vitórias, 1 empate, 2 derrotas
//
// Dicas:
// 1. Guarde as partidas num vetor de structs: { Jogada voce; Jogada outro; }.
// 2. Truque: com PEDRA = 0, PAPEL = 1 e TESOURA = 2, a conta
//    (voce - outro + 3) % 3 dá 0 no empate, 1 quando você vence e 2 quando
//    perde. É por isso que a ordem do enum Resultado foi escolhida assim.
// 3. Um vetor int placar[3] indexado pelo Resultado conta tudo sem if.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
