// Lista · Módulo 16 · Grafos
// Exercício P1625 · ★★★ · Entrega com parada obrigatória na farmácia

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *nomes[V] = {"Loja", "Praca", "Igreja", "Farmacia", "Escola", "Mercado", "Cliente"};
int w[V][V]; // w[u][v] = minutos de u para v; 0 = não há rua nesse sentido

void dijkstra(int s, int dist[], int pi[]) {
    bool fechado[V] = {false};
    for (int v = 0; v < V; v++) {
        dist[v] = INT_MAX;
        pi[v] = -1;
    }
    dist[s] = 0;
    for (int r = 0; r < V; r++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!fechado[v] && dist[v] != INT_MAX && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break;
        fechado[u] = true;
        for (int v = 0; v < V; v++)
            if (w[u][v] && !fechado[v] && dist[u] + w[u][v] < dist[v]) {
                dist[v] = dist[u] + w[u][v];
                pi[v] = u;
            }
    }
}

void caminho(const int pi[], int v) { // da origem até v
    if (pi[v] != -1) {
        caminho(pi, pi[v]);
        printf(" -> ");
    }
    printf("%s", nomes[v]);
}

void continua(const int pi[], int v) { // o mesmo, mas sem imprimir a origem
    if (pi[v] == -1) return;
    continua(pi, pi[v]);
    printf(" -> %s", nomes[v]);
}

int main(void) {
    int ruas[][3] = {{0, 1, 4}, {1, 2, 3}, {2, 6, 7}, {1, 3, 5}, {3, 4, 6}, {4, 6, 7},
                     {3, 5, 2}, {5, 6, 11}, {3, 2, 9}, {4, 0, 7}, {5, 0, 11}, {0, 5, 20}};
    for (int k = 0; k < 12; k++) w[ruas[k][0]][ruas[k][1]] = ruas[k][2];

    int loja = 0, farmacia = 3, cliente = 6;
    int d1[V], p1[V], d2[V], p2[V];
    dijkstra(loja, d1, p1);
    dijkstra(farmacia, d2, p2);

    printf("Direto: ");
    caminho(p1, cliente);
    printf(" (%d min)\n", d1[cliente]);

    printf("Com a parada: ");
    caminho(p1, farmacia); // Loja ... Farmacia
    continua(p2, cliente); // ... Cliente, sem repetir a Farmacia
    int total = d1[farmacia] + d2[cliente];
    printf(" (%d + %d = %d min)\n", d1[farmacia], d2[cliente], total);
    printf("A parada custou %d min a mais\n", total - d1[cliente]);
    printf("Loja -> Farmacia: %d min | Farmacia -> Loja: %d min\n", d1[farmacia], d2[loja]);
    return 0;
}
