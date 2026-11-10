// Lista · Módulo 03 · Laços
// Exercício P0321 · ★★★ · O calendário de qualquer mês
//
// Escreva um programa que leia o mês e o ano e mostre o calendário daquele mês,
// com a semana começando no domingo e cada dia em 3 posições (%3d). O programa
// descobre sozinho em que dia da semana cai o dia 1, com a fórmula (a = (14 −
// mês) / 12, y = ano − a, m = mês + 12a − 2, semana = (1 + y + y/4 − y/100 +
// y/400 + 31m/12) % 7), e quantos dias o mês tem, com bissexto para fevereiro.
// Repita a leitura até o mês valer de 1 a 12. No fim, mostre quantos sábados e
// domingos o mês tem:
//
//   Saída esperada:
//   Mês e ano: 2 2028
//     D  S  T  Q  Q  S  S
//             1  2  3  4  5
//     6  7  8  9 10 11 12
//    13 14 15 16 17 18 19
//    20 21 22 23 24 25 26
//    27 28 29
//   Fins de semana: 8 dias
//
// Dicas:
// 1. Dias do mês: 31 por padrão; 30 em abril, junho, setembro e novembro;
//    fevereiro tem 28 ou 29. Um switch com case empilhados resolve.
// 2. Antes do dia 1, um laço mostra "primeiro" vezes três espaços. Depois, um
//    for nos dias; quebre a linha quando (primeiro + dia) % 7 == 0, e no fim só
//    se a última linha não terminou num sábado.
// 3. O dia da semana de cada dia é (primeiro + dia - 1) % 7: 0 é domingo, 6 é
//    sábado.
// 4. Resposta esperada: fevereiro de 2028 começa na terça e tem 29 dias; 8 dias
//    de fim de semana.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
