// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2921 · ★★★ · A raiz que não é articulação
//
// Uma malha de ciclovias tem sete pontos (0 a 6) e os trechos:
//
//   0-1, 1-2, 2-0, 1-3, 3-4, 4-1, 4-5, 5-6
//
// Tirando o ponto 0, o resto continua ligado. Mas o programa abaixo, que
// roda a DFS a partir do 0, diz que ele é articulação.
//
//   Saída que aparece:
//   Articulações: 0 1 4 5
//
//   Saída esperada:
//   Articulações: 1 4 5
//
// O programa compila e roda sem erro; o problema é de lógica. Conserte-o.
//
// Dicas:
// 1. Na raiz, low[v] >= tin[raiz] é sempre verdade: nada tem tin menor.
// 2. A raiz é articulação só se tiver 2 ou mais filhos na árvore da DFS. Conte
//    os filhos (variável local) e aplique a regra comum só fora da raiz.
// 3. Resposta esperada: a saída esperada acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

#define V 7

int g[V][V], tin[V], low[V], relogio = 0;
bool corte[V];

void dfs(int u, int pai) {
    tin[u] = low[u] = ++relogio;
    for (int v = 0; v < V; v++) {
        if (!g[u][v] || v == pai) continue;
        if (tin[v]) {
            if (tin[v] < low[u]) low[u] = tin[v];
            continue;
        }
        dfs(v, u);
        if (low[v] < low[u]) low[u] = low[v];
        if (low[v] >= tin[u]) corte[u] = true;
    }
}

int main(void) {
    int e[][2] = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}, {4, 1}, {4, 5}, {5, 6}};
    for (int k = 0; k < 8; k++) g[e[k][0]][e[k][1]] = g[e[k][1]][e[k][0]] = 1;
    dfs(0, -1);
    printf("Articulações:");
    for (int u = 0; u < V; u++)
        if (corte[u]) printf(" %d", u);
    printf("\n");
    return 0;
}
