// 0182 · Caminhos e ciclos
// Exercício E1089 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define MAXV 6

typedef struct {
    const char *nome;
    int v;
    int m[MAXV][MAXV]; // m[a][b] = quantas arestas ligam a e b
} Grafo;

bool visto[MAXV];

void dfs(const Grafo *g, int u) {
    visto[u] = true;
    for (int w = 0; w < g->v; w++)
        if (g->m[u][w] && !visto[w]) dfs(g, w);
}

int grau(const Grafo *g, int u) {
    int s = 0;
    for (int w = 0; w < g->v; w++) s += g->m[u][w];
    return s;
}

void analisa(const Grafo *g) {
    for (int u = 0; u < g->v; u++) visto[u] = false;
    int inicio = 0;
    while (inicio < g->v && grau(g, inicio) == 0) inicio++;
    dfs(g, inicio);
    for (int u = 0; u < g->v; u++)
        if (grau(g, u) > 0 && !visto[u]) {
            printf("%s: nenhum (desconexo)\n", g->nome);
            return;
        }
    int impar[MAXV], n = 0;
    for (int u = 0; u < g->v; u++)
        if (grau(g, u) % 2 != 0) impar[n++] = u;
    if (n == 0) printf("%s: circuito euleriano\n", g->nome);
    else if (n == 2) printf("%s: trajeto euleriano de %d a %d\n", g->nome, impar[0], impar[1]);
    else printf("%s: nenhum (%d vértices ímpares)\n", g->nome, n);
}

void liga(Grafo *g, int a, int b) {
    g->m[a][b]++;
    g->m[b][a]++;
}

int main(void) {
    Grafo bairro = {"bairro", 6, {{0}}}, casinha = {"casinha", 5, {{0}}};
    Grafo triangulos = {"triângulos", 6, {{0}}}, pontes = {"pontes", 4, {{0}}};
    int r1[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 5}, {2, 4}, {2, 5}, {3, 4}};
    for (int k = 0; k < 8; k++) liga(&bairro, r1[k][0], r1[k][1]);
    int r2[][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {0, 3}, {1, 2}, {2, 4}, {3, 4}};
    for (int k = 0; k < 8; k++) liga(&casinha, r2[k][0], r2[k][1]);
    int r3[][2] = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 3}};
    for (int k = 0; k < 6; k++) liga(&triangulos, r3[k][0], r3[k][1]);
    int r4[][2] = {{0, 1}, {0, 1}, {0, 2}, {0, 2}, {0, 3}, {1, 3}, {2, 3}};
    for (int k = 0; k < 7; k++) liga(&pontes, r4[k][0], r4[k][1]);

    analisa(&bairro);
    analisa(&casinha);
    analisa(&triangulos);
    analisa(&pontes);
    return 0;
}
