// Lista · Módulo 16 · Grafos
// Exercício P1624 · ★★★ · Mesmo tempo, menos baldeações

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *nomes[V] = {"Terminal 1", "Cachoeirinha", "Sao Jorge", "Dom Pedro",
                        "Alvorada", "Ponta Negra", "Compensa"};
int w[V][V];

bool melhor(int t1, int b1, int t2, int b2, bool desempata) {
    if (t1 != t2) return t1 < t2;
    return desempata && b1 < b2; // empate no tempo: menos trechos ganha
}

void dijkstra(int s, int dist[], int trechos[], int pi[], bool desempata) {
    bool fechado[V] = {false};
    for (int v = 0; v < V; v++) {
        dist[v] = INT_MAX;
        trechos[v] = INT_MAX;
        pi[v] = -1;
    }
    dist[s] = trechos[s] = 0;
    for (int r = 0; r < V; r++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!fechado[v] && dist[v] != INT_MAX &&
                (u == -1 || melhor(dist[v], trechos[v], dist[u], trechos[u], desempata)))
                u = v;
        if (u == -1) break;
        fechado[u] = true;
        for (int v = 0; v < V; v++)
            if (w[u][v] && !fechado[v] &&
                melhor(dist[u] + w[u][v], trechos[u] + 1, dist[v], trechos[v], desempata)) {
                dist[v] = dist[u] + w[u][v];
                trechos[v] = trechos[u] + 1;
                pi[v] = u;
            }
    }
}

void mostra(const int pi[], int v) {
    if (pi[v] != -1) {
        mostra(pi, pi[v]);
        printf(" -> ");
    }
    printf("%s", nomes[v]);
}

int main(void) {
    int trechos[][3] = {{0, 1, 8}, {1, 2, 8}, {2, 3, 8}, {3, 5, 16},
                        {0, 4, 30}, {4, 5, 10}, {0, 6, 12}, {6, 5, 35}};
    for (int k = 0; k < 8; k++) w[trechos[k][0]][trechos[k][1]] = w[trechos[k][1]][trechos[k][0]] = trechos[k][2];

    int dist[V], tr[V], pi[V];
    for (int k = 0; k < 2; k++) {
        bool desempata = k == 1;
        dijkstra(0, dist, tr, pi, desempata);
        printf("%s: ", desempata ? "Com desempate" : "Comum");
        mostra(pi, 5);
        printf(" (%d min, %d trechos)\n", dist[5], tr[5]);
    }
    return 0;
}
