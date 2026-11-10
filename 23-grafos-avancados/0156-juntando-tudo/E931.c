// 0156 · Juntando tudo: o assistente do calouro
// Exercício E931 · ★☆☆
//
// O campus tem seis prédios (índices 0 a 5: Portaria, Biblioteca, Lab,
// Bandejão, Ginásio e Reitoria), ligados por caminhos de mão dupla, em minutos:
//
//   Portaria-Biblioteca 4  Portaria-Bandejão 7   Biblioteca-Lab 3
//   Biblioteca-Bandejão 2  Bandejão-Ginásio 5    Lab-Reitoria 6
//   Ginásio-Reitoria 2
//
// Escreva o programa: guarde o grafo numa matriz, rode o Floyd-Warshall e
// mostre a tabela (uma linha por prédio, com o índice e cada número em %3d) e o
// par de prédios mais distante um do outro, o "diâmetro" do campus (o primeiro
// par com a maior distância, percorrendo a tabela linha por linha).
//
//   Saída esperada:
//   0:  0  4  7  6 11 13
//   1:  4  0  3  2  7  9
//   2:  7  3  0  5  8  6
//   3:  6  2  5  0  5  7
//   4: 11  7  8  5  0  2
//   5: 13  9  6  7  2  0
//   Mais longe: Portaria e Reitoria, 13 min
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define INFINITO 1000000000

int main(void) {

    return 0;
}
