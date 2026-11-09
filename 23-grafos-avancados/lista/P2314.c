// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2314 · ★★☆ · A descida do rio
//
// Descendo o rio de caiaque, cada trecho gasta energia, mas as corredeiras
// a favor EMPURRAM o caiaque e devolvem energia (custo negativo). Como o
// rio só desce, o grafo é um DAG. O programa já calcula o gasto mínimo
// com Bellman-Ford e conta quantas relaxações ele tenta.
//
// Estenda: escreva dag(dist), que faz a ordem topológica (Kahn) e relaxa
// as arestas que saem de cada vértice uma vez só, na ordem topológica,
// contando as tentativas. Mostre as duas respostas lado a lado e as duas
// contagens.
//
//   Saída esperada:
//   Ponto        BF  DAG
//   Cabeceira     0    0
//   Pedral        4    4
//   Remanso       1    1
//   Cachoeira    -1   -1
//   Praia         0    0
//   Foz          -4   -4
//   Relaxações tentadas: Bellman-Ford 45, DAG 9
//
// Dicas:
// 1. Com a lista de trechos, o grau de entrada é grau[t[i].para]++. Para
//    os vizinhos de u, percorra a lista e pegue os t[i].de == u.
// 2. Cada aresta é relaxada exatamente uma vez: o DAG custa O(V + E), sem
//    nenhuma rodada extra, e aceita peso negativo (num DAG não há ciclo).
// 3. Resposta esperada: as duas colunas iguais (a Foz fica em -4) e 9
//    tentativas contra 45 do Bellman-Ford.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdio.h>

#define V 6
#define E 9
#define INF INT_MAX

typedef struct {
    int de, para, custo;
} Trecho;

const char *pontos[V] = {"Cabeceira", "Pedral", "Remanso", "Cachoeira", "Praia", "Foz"};
// a lista vem do fim do rio para o começo
Trecho t[E] = {{4, 5, -4}, {3, 5, 6}, {3, 4, 1}, {2, 4, 7}, {2, 3, -2},
               {1, 3, 5}, {1, 2, -3}, {0, 2, 6}, {0, 1, 4}};

int bellman_ford(int dist[]) {
    int tentativas = 0;
    for (int v = 0; v < V; v++) dist[v] = INF;
    dist[0] = 0;
    for (int r = 1; r <= V - 1; r++) {
        int mudou = 0;
        for (int i = 0; i < E; i++) {
            tentativas++;
            if (dist[t[i].de] != INF && dist[t[i].de] + t[i].custo < dist[t[i].para]) {
                dist[t[i].para] = dist[t[i].de] + t[i].custo;
                mudou = 1;
            }
        }
        if (!mudou) break;
    }
    return tentativas;
}

int main(void) {
    int d1[V];
    int bf = bellman_ford(d1);
    printf("%-10s %4s\n", "Ponto", "BF");
    for (int v = 0; v < V; v++) printf("%-10s %4d\n", pontos[v], d1[v]);
    printf("Relaxações tentadas: Bellman-Ford %d\n", bf);
    return 0;
}
