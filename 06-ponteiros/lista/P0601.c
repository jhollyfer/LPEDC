// Lista · Módulo 06 · Ponteiros
// Exercício P0601 · ★☆☆ · O placar pelo ponteiro
//
// O narrador anotou os gols de Remo x Paysandu numa string, na ordem em que
// saíram: 'R' é gol do Remo e 'P' é gol do Paysandu.
//
//   char gols[] = "RPPRRPR";
//
// Declare int remo = 0, paysandu = 0; e, para cada letra, faça um ponteiro
// int *alvo apontar para a variável do time que marcou e some o gol com
// (*alvo)++. A soma é feita SEMPRE pelo ponteiro, numa linha só. Mostre o
// placar parcial a cada gol:
//
//   Saída esperada:
//   Gol 1 (Remo): Remo 1 x 0 Paysandu
//   Gol 2 (Paysandu): Remo 1 x 1 Paysandu
//   Gol 3 (Paysandu): Remo 1 x 2 Paysandu
//   Gol 4 (Remo): Remo 2 x 2 Paysandu
//   Gol 5 (Remo): Remo 3 x 2 Paysandu
//   Gol 6 (Paysandu): Remo 3 x 3 Paysandu
//   Gol 7 (Remo): Remo 4 x 3 Paysandu
//
// Dicas:
// 1. alvo = (gols[i] == 'R') ? &remo : &paysandu; escolhe o endereço.
// 2. Os parênteses em (*alvo)++ importam: *alvo++ anda o PONTEIRO e não mexe
//    no placar (o ++ vale para alvo, e o * lê o valor antigo).
// 3. Resposta esperada: a saída acima (4 x 3 para o Remo).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    char gols[] = "RPPRRPR";
    int remo = 0, paysandu = 0;
    (void) gols, (void) remo, (void) paysandu; // apague esta linha quando escrever

    return 0;
}
