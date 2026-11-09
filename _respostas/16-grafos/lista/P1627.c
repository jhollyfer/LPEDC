// Lista · Módulo 16 · Grafos
// Exercício P1627 · ★★★ · Quem alcança quem no centro histórico

#include <stdio.h>
#include <stdlib.h>

#define V 7

typedef struct No {
    int v;
    struct No *prox;
} No;

const char *nomes[V] = {"Teatro", "Praca", "Palacio", "Mercado", "Porto", "Alfandega", "Matriz"};
No *adj[V];
int alc[V][V];

void bfs(int s) {
    int fila[V], ini = 0, fim = 0;
    alc[s][s] = 1;
    fila[fim++] = s;
    while (ini < fim) {
        int u = fila[ini++];
        for (No *p = adj[u]; p; p = p->prox)
            if (!alc[s][p->v]) {
                alc[s][p->v] = 1; // s alcança p->v
                fila[fim++] = p->v;
            }
    }
}

int main(void) {
    int ruas[][2] = {{0, 1}, {1, 0}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 3}, {5, 6}};
    int total = 8;
    for (int k = total - 1; k >= 0; k--) {
        No *n = malloc(sizeof *n);
        if (n == NULL) return 1;
        n->v = ruas[k][1];
        n->prox = adj[ruas[k][0]];
        adj[ruas[k][0]] = n;
    }

    for (int s = 0; s < V; s++) bfs(s); // V buscas: O(V(V + E))

    printf("%-12s", "de \\ para");
    for (int v = 0; v < V; v++) printf(" %d", v);
    printf("\n");
    int pares = 0;
    for (int u = 0; u < V; u++) {
        printf("%d %-10s", u, nomes[u]);
        for (int v = 0; v < V; v++) {
            printf(" %d", alc[u][v]);
            if (u != v && alc[u][v]) pares++;
        }
        printf("\n");
    }

    int grupo[V], grupos = 0;
    for (int v = 0; v < V; v++) {
        grupo[v] = v;
        for (int u = 0; u < v; u++)
            if (alc[u][v] && alc[v][u]) {
                grupo[v] = u; // o menor índice do grupo
                break;
            }
    }
    for (int g = 0; g < V; g++) {
        if (grupo[g] != g) continue;
        grupos++;
        printf("Grupo:");
        for (int v = 0; v < V; v++)
            if (grupo[v] == g) printf(" %s", nomes[v]);
        printf("\n");
    }
    printf("Grupos de ida e volta: %d | pares com caminho: %d\n", grupos, pares);

    for (int u = 0; u < V; u++)
        while (adj[u]) {
            No *p = adj[u];
            adj[u] = p->prox;
            free(p);
        }
    return 0;
}
