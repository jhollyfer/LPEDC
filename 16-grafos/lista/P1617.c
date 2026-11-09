// Lista · Módulo 16 · Grafos
// Exercício P1617 · ★★☆ · Amigos de amigos: o quadrado do grafo
//
// A sugestão de amizade de uma rede social mostra "amigos de amigos". Em
// grafos, isso é o QUADRADO do grafo: G² tem a aresta i-j (i != j) quando G
// tem um caminho de uma ou duas arestas entre i e j.
//
// Escreva void quadrado(int g[V][V], int q[V][V]), que monta G² pela matriz em
// O(V³), e um main que mostre as arestas de G, as de G² e as SUGESTÕES (as
// arestas de G² que não estão em G), cada par uma vez.
//
//   Saída esperada:
//   Arestas em G: 5 | em G²: 10
//   Sugestões:
//     Aline-Caua
//     Aline-Flora
//     Bento-Dora
//     Caua-Edson
//     Caua-Flora
//
// Dicas:
// 1. q[i][j] = 1 se g[i][j] == 1 ou se existe k com g[i][k] && g[k][j].
// 2. É o produto de matrizes trocando "soma" por "ou" e "vezes" por "e":
//    por isso custa O(V³).
// 3. Não esqueça de deixar a diagonal em 0: i é vizinho de vizinho de si
//    mesmo, mas ninguém recebe sugestão de amizade consigo.
// 4. Resposta esperada: 5 arestas em G, 10 em G², e 5 sugestões, começando
//    por Aline-Caua e Aline-Flora.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 6

const char *nomes[V] = {"Aline", "Bento", "Caua", "Dora", "Edson", "Flora"};
int g[V][V];

int main(void) {
    int amizades[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {1, 5}};
    for (int k = 0; k < 5; k++) g[amizades[k][0]][amizades[k][1]] = g[amizades[k][1]][amizades[k][0]] = 1;

    return 0;
}
