// 0182 · Caminhos e ciclos
// Exercício E1087 · ★☆☆
//
// A ciclovia do parque liga seis pontos: Bosque, Lago, Mirante, Ponte,
// Quiosque e Trilha (índices 0 a 5). Os trechos, todos de mão dupla, são:
//
//   Bosque-Lago, Bosque-Mirante, Lago-Mirante, Lago-Ponte,
//   Mirante-Quiosque, Ponte-Quiosque, Quiosque-Trilha
//
// Escreva o programa do zero: monte a matriz de adjacência, mostre o grau de
// cada ponto, a soma dos graus (confira o lema do aperto de mãos) e quantos
// pontos têm grau ímpar.
//
//   Saída esperada:
//   Bosque: 2
//   Lago: 3
//   Mirante: 3
//   Ponte: 2
//   Quiosque: 3
//   Trilha: 1
//   Soma dos graus: 14 (2 x 7 trechos)
//   Pontos de grau ímpar: 4
//
// Dicas:
// 1. Cada trecho {a, b} acende duas casas: ciclovia[a][b] e ciclovia[b][a].
// 2. O grau de u é a soma da linha u da matriz.
// 3. Resposta esperada: a saída acima. A soma é sempre o dobro dos trechos, e
//    o número de pontos de grau ímpar é sempre par (aqui, 4).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
