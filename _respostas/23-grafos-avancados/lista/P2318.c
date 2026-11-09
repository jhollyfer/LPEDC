// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2318 · ★★☆ · Dijkstra e Bellman-Ford na mesma balança

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 6
#define INF INT_MAX

const char *siglas[V] = {"BEL", "CAS", "BRA", "CAP", "SAL", "ABA"}; // Belém, Castanhal, Bragança, Capanema, Salinas, Abaetetuba
int km[V][V]; // mão única; 0 = não tem estrada
int olhadas_dij = 0, olhadas_bf = 0;

void dijkstra(int origem, int dist[]) {
    bool feito[V] = {false};
    for (int v = 0; v < V; v++) dist[v] = INF;
    dist[origem] = 0;
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!feito[v] && dist[v] != INF && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break;
        feito[u] = true;
        for (int v = 0; v < V; v++) {
            if (!km[u][v]) continue;
            olhadas_dij++;
            if (dist[u] + km[u][v] < dist[v]) dist[v] = dist[u] + km[u][v];
        }
    }
}

void bellman_ford(int origem, int dist[]) {
    for (int v = 0; v < V; v++) dist[v] = INF;
    dist[origem] = 0;
    for (int r = 1; r <= V - 1; r++) {
        bool mudou = false;
        for (int u = 0; u < V; u++)
            for (int v = 0; v < V; v++) {
                if (!km[u][v]) continue;
                olhadas_bf++;
                if (dist[u] != INF && dist[u] + km[u][v] < dist[v]) {
                    dist[v] = dist[u] + km[u][v];
                    mudou = true;
                }
            }
        if (!mudou) break;
    }
}

int main(void) {
    int estradas[][3] = {{0, 1, 70}, {1, 3, 90}, {3, 2, 30}, {3, 4, 60}, {0, 5, 60},
                         {5, 1, 50}, {2, 4, 50}, {4, 0, 220}, {1, 2, 140}, {5, 3, 150}};
    for (int k = 0; k < 10; k++) km[estradas[k][0]][estradas[k][1]] = estradas[k][2];

    int iguais = 1;
    printf("   ");
    for (int v = 0; v < V; v++) printf("  %s", siglas[v]);
    printf("\n");
    for (int o = 0; o < V; o++) {
        int a[V], b[V];
        dijkstra(o, a);
        bellman_ford(o, b);
        printf("%s", siglas[o]);
        for (int v = 0; v < V; v++) {
            if (a[v] != b[v]) iguais = 0;
            if (a[v] == INF) printf("    -");
            else printf(" %4d", a[v]);
        }
        printf("\n");
    }
    printf("As duas tabelas %s\n", iguais ? "conferem" : "NÃO conferem");
    printf("Arestas olhadas: Dijkstra %d, Bellman-Ford %d\n", olhadas_dij, olhadas_bf);
    return 0;
}
