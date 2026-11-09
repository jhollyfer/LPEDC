// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2329 · ★★★ · Johnson em miniatura
//
// O Dijkstra não aceita peso negativo, e rodar Bellman-Ford de cada origem
// custa O(V² E). O algoritmo de Johnson faz um Bellman-Ford só e depois
// V Dijkstras:
//
//   1. calcule h[v], a menor distância de uma origem imaginária q (ligada
//      a todos com peso 0) até v: é o Bellman-Ford com h[] começando em 0;
//   2. troque cada peso por w'(u, v) = w(u, v) + h[u] - h[v], que nunca é
//      negativo;
//   3. rode o Dijkstra com w' de cada origem e desfaça a troca:
//      d(u, v) = d'(u, v) - h[u] + h[v].
//
// O programa já tem dijkstra(o, peso, dist) e floyd(d) para conferir.
// Complete o main com os três passos: mostre h, os pesos novos (na ordem
// u, v de 0 a 4), a tabela final e se ela bate com a do Floyd-Warshall.
//
//   Saída esperada:
//   h: A=0 B=0 C=-2 D=0 E=-1
//   Pesos novos: AB=3 AC=6 AE=6 BC=0 CD=0 DB=1 DE=0 EC=4
//         A   B   C   D   E
//   A     0   3   1   3   2
//   B     -   0  -2   0  -1
//   C     -   3   0   2   1
//   D     -   1  -1   0  -1
//   E     -   6   3   5   0
//   Floyd-Warshall confere
//
// Dicas:
// 1. Para o passo 1, V rodadas sobre a matriz inteira bastam (são V + 1
//    vértices contando o q). Aqui não há ciclo negativo.
// 2. w' >= 0 sai da desigualdade triangular: h[v] <= h[u] + w(u, v).
// 3. Resposta esperada: h = 0, 0, -2, 0, -1; a linha de A fica
//    0 3 1 3 2 e o Floyd-Warshall confere.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INF 1000000

const char *siglas[V] = {"A", "B", "C", "D", "E"};
int tem[V][V], w[V][V];

void dijkstra(int o, int peso[V][V], int dist[]) {
    bool feito[V] = {false};
    for (int v = 0; v < V; v++) dist[v] = INF;
    dist[o] = 0;
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!feito[v] && dist[v] < INF && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break;
        feito[u] = true;
        for (int v = 0; v < V; v++)
            if (tem[u][v] && dist[u] + peso[u][v] < dist[v]) dist[v] = dist[u] + peso[u][v];
    }
}

void floyd(int d[V][V]) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = i == j ? 0 : tem[i][j] ? w[i][j] : INF;
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] < INF && d[k][j] < INF && d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
}

int main(void) {
    int arestas[][3] = {{0, 1, 3}, {1, 2, -2}, {0, 2, 4}, {2, 3, 2}, {3, 1, 1}, {3, 4, -1}, {0, 4, 5}, {4, 2, 3}};
    for (int k = 0; k < 8; k++) {
        tem[arestas[k][0]][arestas[k][1]] = 1;
        w[arestas[k][0]][arestas[k][1]] = arestas[k][2];
    }
    int f[V][V];
    floyd(f);
    printf("Floyd: de A até C = %d\n", f[0][2]);
    return 0;
}
