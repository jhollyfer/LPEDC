// 0109 · Grafos
// Exercício E650 · ★☆☆
//
// Depois do churrasco, a turma anotou quem ficou devendo Pix para quem num
// grafo DIRIGIDO: deve[i][j] == 1 quer dizer que i deve para j. A matriz já
// está no esqueleto. Complete o programa: para cada pessoa, mostre para
// quantos ela deve (setas que saem) e de quantos ela recebe (setas que
// chegam). No fim, mostre quem não deve para ninguém e quem não recebe de
// ninguém.
//
//   Saída esperada:
//   Leo deve para 2 e recebe de 1
//   Mia deve para 1 e recebe de 2
//   Rui deve para 0 e recebe de 3
//   Sol deve para 3 e recebe de 0
//   Sem dívidas: Rui
//   Ninguém deve para: Sol
//
// Dicas:
// 1. Somar a LINHA i conta as setas que saem de i: para quantos i deve.
// 2. Somar a COLUNA i (deve[j][i], com j variando) conta as setas que
//    chegam em i: de quantos i recebe.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 4

int main(void) {
    const char *nomes[V] = {"Leo", "Mia", "Rui", "Sol"};
    int deve[V][V] = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 0},
    };
    (void)nomes; // apague esta linha quando usar nomes
    (void)deve;  // apague esta linha quando usar deve

    return 0;
}
