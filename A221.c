// A221 · Cabos do escritório: arestas de árvore e de retorno

#include <stdio.h>

#define V 6

const char *nomes[V] = {"Servidor", "Recepcao", "RH", "Financeiro", "Diretoria", "Copa"};
int adj[V][V];
int ordem[V]; // em que momento cada sala foi descoberta; 0 = ainda não
int relogio = 0;
int de_arvore = 0, de_retorno = 0;

void dfs(int u, int pai) {
    ordem[u] = ++relogio;
    for (int v = 0; v < V; v++) {
        if (!adj[u][v]) continue;
        if (ordem[v] == 0) { // sala nova: a DFS desce por este cabo
            printf("desce   %s -> %s\n", nomes[u], nomes[v]);
            de_arvore++;
            dfs(v, u);
        } else if (v != pai && ordem[v] < ordem[u]) {
            // v já está na pilha, acima de u: este cabo fecha um ciclo
            printf("retorno %s -> %s (ciclo)\n", nomes[u], nomes[v]);
            de_retorno++;
        }
        // v == pai: é o cabo por onde u chegou; não conta como ciclo
    }
}

int main(void) {
    int cabos[][2] = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 4}, {0, 4}, {4, 5}};
    int total = (int)(sizeof cabos / sizeof cabos[0]);
    for (int k = 0; k < total; k++) {
        adj[cabos[k][0]][cabos[k][1]] = 1;
        adj[cabos[k][1]][cabos[k][0]] = 1;
    }

    dfs(0, -1); // o Servidor não tem pai
    printf("Cabos: %d = %d de árvore + %d de retorno\n", total, de_arvore, de_retorno);
    printf("Para não ter ciclo nenhum, bastariam %d cabos (V - 1)\n", V - 1);
    return 0;
}
// Saída:
// desce   Servidor -> Recepcao
// desce   Recepcao -> RH
// retorno RH -> Servidor (ciclo)
// desce   RH -> Financeiro
// desce   Financeiro -> Diretoria
// retorno Diretoria -> Servidor (ciclo)
// desce   Diretoria -> Copa
// Cabos: 7 = 5 de árvore + 2 de retorno
// Para não ter ciclo nenhum, bastariam 5 cabos (V - 1)
