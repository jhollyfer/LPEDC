// Lista · Módulo 16 · Grafos
// Exercício P1604 · ★☆☆ · O grupo de estudos é completo?
//
// Cinco colegas que vão fazer a prova do mestrado montaram um grupo de estudos.
// A matriz do esqueleto diz quem já estudou junto com quem (não dirigido). O
// grupo só fica "completo" quando TODO par de pessoas já estudou junto: é o
// grafo completo K5, com 5·4/2 = 10 arestas.
//
// Escreva:
//
//   int arestas(int m[V][V]);
//   bool completo(int m[V][V]);
//
// e um main que mostre quantas arestas há, quantas o K5 teria, os pares que
// ainda faltam e, depois de marcar esses pares na matriz (as sessões que
// faltam), se o grupo ficou completo.
//
//   Saída esperada:
//   Arestas: 7 de 10
//   completo: não
//   Falta: Iara-Luana
//   Falta: Joao-Moacir
//   Falta: Kaue-Luana
//   Depois das sessões: 10 arestas
//   completo: sim
//
// Dicas:
// 1. Conte só a metade de cima da matriz (i < j): cada aresta uma vez.
// 2. Um grafo simples com n vértices é completo quando tem n(n - 1)/2 arestas,
//    ou, do jeito direto, quando m[i][j] == 1 para todo i != j.
// 3. Ao marcar um par que falta, marque os dois sentidos: m[i][j] = m[j][i] = 1.
// 4. Resposta esperada: 7 arestas de 10, faltam Iara-Luana, Joao-Moacir e
//    Kaue-Luana; depois, "completo: sim".
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define V 5

const char *nomes[V] = {"Iara", "Joao", "Kaue", "Luana", "Moacir"};
int m[V][V] = {
    {0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {1, 0, 1, 1, 0},
};

int main(void) {

    return 0;
}
