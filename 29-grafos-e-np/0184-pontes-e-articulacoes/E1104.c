// 0184 · Pontes e articulações
// Exercício E1104 · ★★★
//
// A operadora passou um cabo reserva entre Tarumã e Ponta Negra, ao lado do
// antigo. Agora são dois cabos entre os mesmos bairros (arestas
// paralelas), e cortar um deles não isola ninguém. O programa abaixo guarda
// os cabos numa lista (a matriz 0/1 não consegue representar dois cabos
// iguais), mas continua dizendo que Tarumã - Ponta Negra é ponte:
//
//   Saída que aparece:
//   Ponte: Tarumã - Ponta Negra
//   Ponte: Aleixo - Flores
//
//   Saída esperada:
//   Ponte: Aleixo - Flores
//
// Conserte a DFS para que ela funcione com cabos paralelos.
//
// Dicas:
// 1. O teste v == pai pula TODOS os cabos que voltam ao pai, inclusive o
//    reserva, que é uma aresta de volta legítima.
// 2. Em vez do vértice pai, passe o ÍNDICE do cabo pelo qual a DFS chegou
//    (dfs(v, k)) e pule só esse cabo (k == cabo_pai). A raiz recebe -1.
// 3. Resposta esperada: a saída esperada acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define V 7
#define E 9

const char *bairros[V] = {"Centro", "Aleixo", "Adrianópolis", "Flores", "Cidade Nova", "Tarumã", "Ponta Negra"};
// lista de cabos: o último é o cabo reserva, paralelo a Tarumã - Ponta Negra
int cabo[E][2] = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}, {4, 5}, {5, 3}, {5, 6}, {5, 6}};
int tin[V], low[V], relogio = 0;

void dfs(int u, int pai) {
    tin[u] = low[u] = ++relogio;
    for (int k = 0; k < E; k++) {
        if (cabo[k][0] != u && cabo[k][1] != u) continue;
        int v = cabo[k][0] == u ? cabo[k][1] : cabo[k][0]; // a outra ponta
        if (v == pai) continue;
        if (tin[v] != 0) {
            if (tin[v] < low[u]) low[u] = tin[v];
            continue;
        }
        dfs(v, u);
        if (low[v] < low[u]) low[u] = low[v];
        if (low[v] > tin[u]) printf("Ponte: %s - %s\n", bairros[u], bairros[v]);
    }
}

int main(void) {
    dfs(0, -1);
    return 0;
}
