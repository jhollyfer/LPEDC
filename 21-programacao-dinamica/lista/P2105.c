// Lista · Módulo 21 · Programação dinâmica
// Exercício P2105 · ★☆☆ · As fatias do bolo de rolo
//
// A doceira vende bolo de rolo em fatias, e o preço depende do comprimento
// da fatia (fatias maiores saem mais em conta por cm):
//
//   cm     1   2   3   4   5   6
//   R$     3   7  11  13  16  20
//
// Um rolo de 10 cm pode ser cortado como ela quiser (ou não cortado, se
// coubesse na tabela). Quanto ela ganha, no máximo? Este é o CORTE DE
// HASTE do Cormen (15.1). Complete o laço de baixo para cima: melhor[j] é o
// maior valor de um pedaço de j cm, testando a primeira fatia de cada
// tamanho i e somando melhor[j - i].
//
//   Saída esperada:
//    1 cm: R$ 3
//    2 cm: R$ 7
//    3 cm: R$ 11
//    4 cm: R$ 14
//    5 cm: R$ 18
//    6 cm: R$ 22
//    7 cm: R$ 25
//    8 cm: R$ 29
//    9 cm: R$ 33
//   10 cm: R$ 36
//   Fatias: 1 3 3 3
//
// Dicas:
// 1. melhor[0] = 0. Para cada j de 1 a 10, teste i de 1 até o menor entre j
//    e 6: preco[i] + melhor[j - i].
// 2. Guarde em corte[j] o i que deu o máximo; para listar as fatias, ande
//    de j = 10 tirando corte[j].
// 3. Resposta esperada: R$ 37, com fatias de 3, 3 e 4 cm... ou outra
//    combinação de mesmo valor, dependendo do desempate. Confira na saída.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define TAM 10
#define MAXF 6

int main(void) {
    const int preco[MAXF + 1] = {0, 3, 7, 11, 13, 16, 20};
    int melhor[TAM + 1], corte[TAM + 1];
    melhor[0] = 0;
    corte[0] = 0;
    for (int j = 1; j <= TAM; j++) {
        melhor[j] = 0;
        corte[j] = 0;
        (void)preco;
        // COMPLETE AQUI
    }
    for (int j = 1; j <= TAM; j++) {
        printf("%2d cm: R$ %d\n", j, melhor[j]);
    }
    printf("Fatias:");
    for (int j = TAM; j > 0 && corte[j] > 0; j -= corte[j]) {
        printf(" %d", corte[j]);
    }
    printf("\n");
    return 0;
}
