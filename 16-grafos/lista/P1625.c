// Lista · Módulo 16 · Grafos
// Exercício P1625 · ★★★ · Entrega com parada obrigatória na farmácia
//
// Um motoboy sai da Loja, precisa PASSAR na Farmácia para pegar um remédio e
// só então ir à casa do Cliente. As ruas do centro são de mão única (grafo
// DIRIGIDO), com o tempo em minutos na matriz do esqueleto.
//
// O caminho mínimo com parada obrigatória é o mínimo de Loja até Farmácia
// emendado no mínimo de Farmácia até Cliente: rode o Dijkstra duas vezes, com
// origens diferentes. Escreva um programa que mostre:
//
// - o trajeto e o tempo direto Loja -> Cliente (sem a parada);
// - o trajeto completo Loja -> ... -> Farmácia -> ... -> Cliente e o tempo;
// - quantos minutos a parada custou a mais;
// - o tempo de volta da Farmácia para a Loja, que NÃO é igual ao de ida
// (mão única).
//
//   Saída esperada:
//   Direto: Loja -> Praca -> Igreja -> Cliente (14 min)
//   Com a parada: Loja -> Praca -> Farmacia -> Mercado -> Cliente (9 + 13 = 22 min)
//   A parada custou 8 min a mais
//   Loja -> Farmacia: 9 min | Farmacia -> Loja: 13 min
//
// Dicas:
// 1. Escreva dijkstra(s, dist, pi) e chame com s = Loja e com s = Farmacia.
//    Guarde os resultados em vetores diferentes.
// 2. Para emendar, imprima o caminho até a Farmácia com o primeiro pi[] e o
//    resto com o segundo, sem repetir a Farmácia.
// 3. Num grafo dirigido, dist(a, b) e dist(b, a) podem ser diferentes. A
//    matriz não é simétrica.
// 4. Resposta esperada: direto 14 min; com a parada, 22 min (8 a mais); a
//    volta Farmácia -> Loja leva 13 min, contra 9 da ida.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *nomes[V] = {"Loja", "Praca", "Igreja", "Farmacia", "Escola", "Mercado", "Cliente"};
int w[V][V]; // w[u][v] = minutos de u para v; 0 = não há rua nesse sentido

int main(void) {
    int ruas[][3] = {{0, 1, 4}, {1, 2, 3}, {2, 6, 7}, {1, 3, 5}, {3, 4, 6}, {4, 6, 7},
                     {3, 5, 2}, {5, 6, 11}, {3, 2, 9}, {4, 0, 7}, {5, 0, 11}, {0, 5, 20}};
    for (int k = 0; k < 12; k++) w[ruas[k][0]][ruas[k][1]] = ruas[k][2];

    return 0;
}
