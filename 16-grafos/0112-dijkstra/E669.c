// 0112 · Dijkstra: caminho mínimo
// Exercício E669 · ★★☆
//
// Um motoboy sai do restaurante (R) para entregar em cinco clientes. As
// ruas são de mão dupla e os pesos são km:
//
//   R-Ana 2, R-Beto 6, Ana-Beto 3, Ana-Caio 7, Beto-Caio 2, Beto-Dani 9,
//   Caio-Dani 3, Caio-Eva 8, Dani-Eva 1
//
// Escreva o programa completo: Dijkstra a partir do R guardando anterior[],
// e mostre, para cada cliente, a distância e a rota (com uma função
// recursiva). No fim, diga qual cliente fica mais longe.
//
//   Saída esperada:
//   Ana: 2 km  R -> Ana
//   Beto: 5 km  R -> Ana -> Beto
//   Caio: 7 km  R -> Ana -> Beto -> Caio
//   Dani: 10 km  R -> Ana -> Beto -> Caio -> Dani
//   Eva: 11 km  R -> Ana -> Beto -> Caio -> Dani -> Eva
//   Mais longe: Eva (11 km)
//
// Dicas:
// 1. Índices: R 0, Ana 1, Beto 2, Caio 3, Dani 4, Eva 5. Matriz de pesos com
//    0 para "sem rua".
// 2. A rota recursiva é a do A224: imprime primeiro a rota até anterior[v],
//    depois " -> " e o nome de v.
// 3. Resposta esperada: a saída acima. Repare que todas as rotas formam uma
//    linha só: a árvore de caminhos mínimos deste mapa é um caminho.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
