// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2326 · ★★★ · Onde o ciclo negativo contamina
//
// Num jogo, atravessar portais (mão única) custa energia; alguns devolvem
// energia (custo negativo). A volta Ponte -> Torre -> Mina -> Ponte custa
// 3 - 4 - 1 = -2: quem entra nela fica girando e a energia "mínima" de
// tudo o que vem depois é -infinito. O programa abaixo já faz as V - 1
// rodadas do Bellman-Ford e só mostra números. Estenda-o:
// - na rodada extra, cada aresta que ainda melhora marca o destino;
// - a partir de cada marcado, uma DFS espalha a marca por tudo o que ele
//   alcança (essas salas ficam em -infinito);
// - mostre "-infinito", "inalcançável" ou o número de cada sala.
//
//   Saída esperada:
//   Base   0
//   Ponte  -infinito
//   Torre  -infinito
//   Mina   -infinito
//   Vale   -infinito
//   Lago   6
//   Bosque 7
//   Ilha   inalcançável
//
// Dicas:
// 1. espalha(u) marca infinito[u] e desce por todo portal u -> v com v
//    ainda não marcado.
// 2. A Ilha tem um ciclo negativo próprio (o portal Ilha -> Ilha), mas
//    ninguém da Base chega nela: ciclo inalcançável não contamina nada.
//    O Bosque também não: a Ilha chega nele, mas a Base não chega na Ilha.
// 3. Resposta esperada: Ponte, Torre, Mina e Vale em -infinito; Lago 6,
//    Bosque 7, Ilha inalcançável.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 8
#define E 9
#define INF INT_MAX

typedef struct {
    int de, para, custo;
} Portal;

const char *salas[V] = {"Base", "Ponte", "Torre", "Mina", "Vale", "Lago", "Bosque", "Ilha"};
Portal p[E] = {{0, 1, 2}, {1, 2, 3}, {2, 3, -4}, {3, 1, -1}, {3, 4, 2},
               {0, 5, 6}, {5, 6, 1}, {7, 7, -5}, {7, 6, -3}};

int main(void) {
    int dist[V];
    for (int v = 0; v < V; v++) dist[v] = INF;
    dist[0] = 0;
    for (int r = 1; r <= V - 1; r++)
        for (int i = 0; i < E; i++)
            if (dist[p[i].de] != INF && dist[p[i].de] + p[i].custo < dist[p[i].para])
                dist[p[i].para] = dist[p[i].de] + p[i].custo;

    for (int v = 0; v < V; v++) {
        printf("%-6s ", salas[v]);
        if (dist[v] == INF) printf("inalcançável\n");
        else printf("%d\n", dist[v]);
    }
    return 0;
}
