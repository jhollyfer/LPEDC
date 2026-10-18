// 0111 · DFS: busca em profundidade
// Exercício E661 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *nomes[V] = {"Hall", "Cinema", "Praça", "Loja", "Banco", "Saída"};
int adj[V][V] = {
    {0, 0, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 0},
    {1, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0},
    {1, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0},
};
bool visitado[V];
int contador = 0;                 // quantas áreas já foram visitadas
int nivel_max = -1, mais_fundo = -1;

void dfs(int u, int nivel) {
    visitado[u] = true;
    contador++;
    printf("%*s%d %s\n", 2 * nivel, "", contador, nomes[u]);
    if (nivel > nivel_max) {
        nivel_max = nivel;
        mais_fundo = u;
    }
    for (int v = 0; v < V; v++)
        if (adj[u][v] && !visitado[v]) dfs(v, nivel + 1);
}

int main(void) {
    dfs(0, 0);
    printf("Mais fundo: %s (nível %d)\n", nomes[mais_fundo], nivel_max);
    return 0;
}
