// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2314 · ★★☆ · A descida do rio

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

// num DAG: ordem topológica e UMA passada pelas arestas de cada vértice
int dag(int dist[]) {
    int grau[V] = {0}, ordem[V], ini = 0, fim = 0, tentativas = 0;
    for (int i = 0; i < E; i++) grau[t[i].para]++;
    for (int u = 0; u < V; u++)
        if (grau[u] == 0) ordem[fim++] = u;
    while (ini < fim) {
        int u = ordem[ini++];
        for (int i = 0; i < E; i++)
            if (t[i].de == u && --grau[t[i].para] == 0) ordem[fim++] = t[i].para;
    }
    for (int v = 0; v < V; v++) dist[v] = INF;
    dist[0] = 0;
    for (int k = 0; k < V; k++) {
        int u = ordem[k];
        for (int i = 0; i < E; i++) {
            if (t[i].de != u) continue;
            tentativas++;
            if (dist[u] != INF && dist[u] + t[i].custo < dist[t[i].para]) dist[t[i].para] = dist[u] + t[i].custo;
        }
    }
    return tentativas;
}

int main(void) {
    int d1[V], d2[V];
    int bf = bellman_ford(d1);
    int ot = dag(d2);
    printf("%-10s %4s %4s\n", "Ponto", "BF", "DAG");
    for (int v = 0; v < V; v++) printf("%-10s %4d %4d\n", pontos[v], d1[v], d2[v]);
    printf("Relaxações tentadas: Bellman-Ford %d, DAG %d\n", bf, ot);
    return 0;
}
