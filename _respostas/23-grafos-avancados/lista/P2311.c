// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2311 · ★★☆ · Kosaraju nas rotas de barco

#include <stdbool.h>
#include <stdio.h>

#define V 8

const char *portos[V] = {"Manaus", "Iranduba", "Manacapuru", "Novo Airão",
                         "Careiro", "Autazes", "Itacoatiara", "Silves"};
int rota[V][V];   // rota[a][b] = 1: tem barco de a para b
int inversa[V][V]; // o grafo com as setas invertidas
bool visto[V];
int ordem[V], n_ordem = 0; // vértices em ordem de término da 1ª DFS
int grupo[V];

void dfs1(int u) {
    visto[u] = true;
    for (int v = 0; v < V; v++)
        if (rota[u][v] && !visto[v]) dfs1(v);
    ordem[n_ordem++] = u; // terminou
}

// 2ª passada: DFS no grafo invertido, pintando com o número g
void dfs2(int u, int g) {
    grupo[u] = g;
    for (int v = 0; v < V; v++)
        if (inversa[u][v] && grupo[v] == 0) dfs2(v, g);
}

int main(void) {
    int barcos[][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 3}, {0, 5}, {5, 6}, {6, 7}, {7, 5}, {4, 6}};
    for (int k = 0; k < 11; k++) {
        rota[barcos[k][0]][barcos[k][1]] = 1;
        inversa[barcos[k][1]][barcos[k][0]] = 1;
    }

    for (int u = 0; u < V; u++)
        if (!visto[u]) dfs1(u);
    printf("Término da 1ª DFS:");
    for (int i = 0; i < V; i++) printf(" %s", portos[ordem[i]]);
    printf("\n");

    int g = 0;
    for (int i = V - 1; i >= 0; i--) { // do último a terminar para o primeiro
        int u = ordem[i];
        if (grupo[u] == 0) dfs2(u, ++g);
    }
    for (int k = 1; k <= g; k++) {
        printf("Grupo %d:", k);
        for (int u = 0; u < V; u++)
            if (grupo[u] == k) printf(" %s", portos[u]);
        printf("\n");
    }
    return 0;
}
