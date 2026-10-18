// 0032 · Juntando tudo
// Exercício E192 · ★★★
//
// Imprima o calendário de outubro de 2026. O mês tem 31 dias e o dia 1 cai
// numa quinta-feira. A semana começa no domingo, e cada dia ocupa 3 posições
// (%3d):
//
//     D  S  T  Q  Q  S  S
//                 1  2  3
//     4  5  6  7  8  9 10
//    11 12 13 14 15 16 17
//    18 19 20 21 22 23 24
//    25 26 27 28 29 30 31
//
// Depois mude para fevereiro de 2026 (28 dias, começa num domingo) mexendo só
// em duas variáveis.
//
// Dicas:
// 1. Duas variáveis bastam: dias_no_mes = 31 e primeiro = 4 (domingo = 0,
//    segunda = 1, ..., quinta = 4).
// 2. Antes do dia 1, um laço imprime "primeiro" vezes três espaços. Depois,
//    um for de 1 a 31; pule linha quando a coluna chegar no sábado:
//    (primeiro + dia) % 7 == 0.
// 3. Resposta esperada: o desenho acima, 5 semanas, terminando no sábado 31.
//    Fevereiro de 2026 (primeiro = 0, 28 dias) fica com 4 linhas cheias.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
