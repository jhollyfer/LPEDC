// Lista · Módulo 16 · Grafos
// Exercício P1612 · ★★☆ · Os links do site: os quatro tipos de aresta
//
// O site de uma loja de açaí tem sete páginas, e cada link é uma seta
// (grafo DIRIGIDO), guardada na matriz do esqueleto. Rode uma DFS (laço
// principal e vizinhos em ordem de índice) e classifique cada link no momento
// em que ele é examinado, de u para v:
//
// - ÁRVORE: v é branco (a DFS desce por ele);
// - RETORNO: v é cinza (v é ancestral de u: ciclo);
// - AVANÇO: v é preto e d[u] < d[v] (v é descendente de u já terminado);
// - CRUZAMENTO: v é preto e d[u] > d[v] (outro ramo ou outra árvore).
//
// Mostre cada link com o tipo, na ordem em que a DFS os examina, e a contagem
// de cada tipo.
//
//   Saída esperada:
//   Home     -> Blog     árvore
//   Blog     -> Post     árvore
//   Post     -> Home     retorno
//   Post     -> Contato  árvore
//   Home     -> Loja     árvore
//   Loja     -> Contato  cruzamento
//   Loja     -> Carrinho árvore
//   Carrinho -> Loja     retorno
//   Home     -> Post     avanço
//   Ajuda    -> Home     cruzamento
//   Ajuda    -> Contato  cruzamento
//   árvore 5, retorno 2, avanço 1, cruzamento 3
//
// Dicas:
// 1. Use enum { BRANCO, CINZA, PRETO }, d[] e um relógio, como no Cormen.
// 2. Classifique ANTES da chamada recursiva: depois dela, v já virou preto.
// 3. Avanço e cruzamento só existem em grafo dirigido; num não dirigido toda
//    aresta é de árvore ou de retorno.
// 4. Resposta esperada: 5 de árvore, 2 de retorno, 1 de avanço e 3 de
//    cruzamento (11 links).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 7

const char *nomes[V] = {"Home", "Blog", "Loja", "Contato", "Post", "Carrinho", "Ajuda"};
int adj[V][V];

int main(void) {
    int links[][2] = {{0, 1}, {0, 2}, {0, 4}, {1, 4}, {4, 0}, {4, 3},
                      {2, 3}, {2, 5}, {5, 2}, {6, 3}, {6, 0}};
    for (int k = 0; k < 11; k++) adj[links[k][0]][links[k][1]] = 1;

    return 0;
}
