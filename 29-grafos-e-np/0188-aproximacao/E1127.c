// 0188 · Aproximação
// Exercício E1127 · ★★★
//
// Escreva a 2-aproximação do caixeiro viajante métrico para um passeio
// turístico com sete pontos (coordenadas em quarteirões; a distância é
// |dx| + |dy|). O programa deve:
//
//   - montar a matriz d de distâncias;
//   - rodar o Prim O(N²) a partir da Base, guardando pai[] (no empate,
//     vale o menor índice);
//   - void preordem(int u): a rota é a pré-ordem da árvore (u primeiro,
//     depois os filhos de u em ordem de índice);
//   - int custo(const int r[]): o tamanho da rota fechada;
//   - achar o ótimo por força bruta, fixando a Base no começo.
//
//   Saída esperada:
//   Árvore mínima: 21 quarteirões
//   Rota aproximada: Base Feira Igreja Zoo Museu Teatro Praia Base = 34 quarteirões
//   Ótimo (força bruta): 30 quarteirões
//   Garantia: rota <= 2 x árvore = 42
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 7

const char *pontos[N] = {"Base", "Feira", "Igreja", "Museu", "Praia", "Teatro", "Zoo"};
const int px[N] = {0, 3, 6, 6, 2, 8, 4};
const int py[N] = {0, 1, 0, 4, 5, 3, 3};

int main(void) {

    return 0;
}
