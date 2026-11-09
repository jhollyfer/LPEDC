// Lista · Módulo 16 · Grafos
// Exercício P1613 · ★★☆ · Dois turnos de prova e a aresta que estraga

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *nomes[V] = {"Calculo", "Algoritmos", "Fisica", "Discreta", "Ingles", "Estatistica"};
int adj[V][V];

bool bipartido(int adj[V][V], int turno[]) {
    for (int v = 0; v < V; v++) turno[v] = -1;
    for (int r = 0; r < V; r++) {
        if (turno[r] != -1) continue; // componente novo: BFS nova
        int fila[V], ini = 0, fim = 0;
        turno[r] = 0;
        fila[fim++] = r;
        while (ini < fim) {
            int u = fila[ini++];
            for (int v = 0; v < V; v++) {
                if (!adj[u][v]) continue;
                if (turno[v] == -1) {
                    turno[v] = 1 - turno[u]; // o turno oposto
                    fila[fim++] = v;
                } else if (turno[v] == turno[u]) {
                    printf("Conflito: %s-%s no mesmo turno\n", nomes[u], nomes[v]);
                    return false;
                }
            }
        }
    }
    return true;
}

void testa(void) {
    int turno[V];
    if (bipartido(adj, turno)) {
        printf("Bipartido:\n");
        for (int v = 0; v < V; v++) printf("  %-11s %s\n", nomes[v], turno[v] ? "tarde" : "manhã");
    } else {
        printf("Não é bipartido\n");
    }
}

int main(void) {
    int pares[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {4, 5}};
    for (int k = 0; k < 5; k++) adj[pares[k][0]][pares[k][1]] = adj[pares[k][1]][pares[k][0]] = 1;

    testa();
    adj[0][2] = adj[2][0] = 1; // Calculo-Fisica: triângulo com Algoritmos
    printf("Com Calculo-Fisica:\n");
    testa();
    return 0;
}
