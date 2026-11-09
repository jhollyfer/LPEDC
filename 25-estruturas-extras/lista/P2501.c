// Lista · Módulo 25 · Estruturas especiais
// Exercício P2501 · ★☆☆ · As poltronas ocupadas do cinema
//
// A sessão das 14h tem 6 fileiras de 10 poltronas. A matriz sala guarda a
// idade de quem comprou cada poltrona (0 = vazia), e quase tudo é zero.
// Escreva o programa: percorra a matriz e monte o vetor de triplas
// (linha, coluna, valor), em ordem, só com as poltronas ocupadas. Mostre
// as triplas, quantas estão ocupadas, quantos números cada formato guarda
// e até quantas ocupadas as triplas compensam.
//
//   Saída esperada:
//   (1, 2, 34)
//   (1, 3, 31)
//   (3, 4, 12)
//   (3, 5, 40)
//   (3, 6, 41)
//   (5, 0, 70)
//   (5, 9, 68)
//   Ocupadas: 7 de 60
//   Números guardados: matriz 60, triplas 21
//   As triplas compensam enquanto houver menos de 20 ocupadas
//
// Dicas:
// 1. typedef struct { int lin, col, valor; } Tripla; e um vetor de L * C
//    triplas (o pior caso).
// 2. A matriz guarda L × C números; as triplas, 3 por ocupada. Compensa
//    enquanto 3n < L × C.
// 3. Resposta esperada: 7 ocupadas, 21 números contra 60; compensa com
//    menos de 20 ocupadas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define L 6
#define C 10

int main(void) {
    int sala[L][C] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 34, 31, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 12, 40, 41, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {70, 0, 0, 0, 0, 0, 0, 0, 0, 68},
    };
    printf("%d\n", sala[1][2]);
    return 0;
}
