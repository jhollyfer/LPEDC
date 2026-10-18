// 0152 · Kruskal: árvore geradora mínima
// Exercício E909 · ★★☆
//
// Voltando às seis vilas do texto: o prefeito prometeu na campanha
// asfaltar a estrada Sede-Ponte (R$ 6 mil), que o Kruskal descartou. Ela
// vai entrar de qualquer jeito. Escreva o programa (pode partir do código
// do texto) que monte a árvore mais barata que CONTENHA essa estrada e
// mostre quanto a promessa custou a mais.
//
//   Saída esperada:
//   Sede-Ponte (6) obrigatória
//   Serra-Lagoa (2)
//   Ponte-Brejo (3)
//   Ponte-Serra (5)
//   Serra-Vale (7)
//   Total: R$ 23 mil
//   Custo extra da exigência: R$ 2 mil
//
// Dicas:
// 1. Antes do laço do Kruskal, já una Sede e Ponte e some os 6 mil. O
//    resto do algoritmo não muda: ele só vai descartar o que fecha ciclo
//    com as arestas aceitas, incluindo a obrigatória.
// 2. Para saber o custo extra, rode também o Kruskal sem exigência (dá 21)
//    e subtraia. Uma função kruskal(estradas, obrigatoria) que devolve o
//    total ajuda; lembre de reiniciar pai[] e tamanho[] a cada chamada.
// 3. Resposta esperada: a saída acima. Agora quem fecha ciclo é Sede-Brejo
//    (4): Sede e Brejo já estão ligados pela Ponte.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define V 6
#define E 9

typedef struct {
    int a, b, custo;
} Aresta;

const char *vilas[V] = {"Sede", "Ponte", "Brejo", "Serra", "Lagoa", "Vale"};

int main(void) {
    Aresta estradas[E] = {{0, 2, 4}, {1, 2, 3}, {0, 1, 6}, {2, 3, 8}, {1, 3, 5},
                          {1, 4, 9}, {3, 4, 2}, {3, 5, 7}, {4, 5, 7}};
    (void)estradas; // apague esta linha

    return 0;
}
