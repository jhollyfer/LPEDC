// 0152 · Kruskal: árvore geradora mínima
// Exercício E912 · ★★★

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define V 7
#define E 10

typedef struct {
    int a, b, subida; // desnível da rua, em metros
} Rua;

const char *lugares[V] = {"Casa", "Praça", "Igreja", "Feira", "Morro", "Parque", "Escola"};
int pai[V];
int arvore[V][V]; // as ruas da MST, com o desnível (0 = fora da árvore)
int anterior[V];
bool visto[V];

int acha(int x) {
    if (pai[x] != x) pai[x] = acha(pai[x]);
    return pai[x];
}

int compara(const void *p, const void *q) {
    const Rua *x = p, *y = q;
    return x->subida - y->subida;
}

// DFS na árvore: o caminho entre dois vértices de uma árvore é único
void dfs(int u) {
    visto[u] = true;
    for (int v = 0; v < V; v++)
        if (arvore[u][v] && !visto[v]) {
            anterior[v] = u;
            dfs(v);
        }
}

int main(void) {
    Rua ruas[E] = {{0, 4, 30}, {4, 6, 25}, {0, 1, 8}, {1, 3, 12}, {1, 2, 15},
                   {2, 6, 18}, {3, 5, 10}, {5, 6, 14}, {3, 2, 9}, {0, 2, 20}};
    qsort(ruas, E, sizeof(Rua), compara);
    for (int v = 0; v < V; v++) pai[v] = v;
    for (int k = 0, n = 0; k < E && n < V - 1; k++) {
        int ra = acha(ruas[k].a), rb = acha(ruas[k].b);
        if (ra == rb) continue;
        pai[rb] = ra;
        n++;
        arvore[ruas[k].a][ruas[k].b] = arvore[ruas[k].b][ruas[k].a] = ruas[k].subida;
    }

    int origem = 0, destino = 6;
    anterior[origem] = -1;
    dfs(origem);

    int caminho[V], n = 0, pior = 0;
    for (int v = destino; v != -1; v = anterior[v]) {
        caminho[n++] = v;
        if (anterior[v] != -1 && arvore[v][anterior[v]] > pior) pior = arvore[v][anterior[v]];
    }
    printf("Rota:");
    for (int i = n - 1; i >= 0; i--) printf(" %s%s", lugares[caminho[i]], i > 0 ? " ->" : "");
    printf("\nMaior subida: %d m\n", pior);
    return 0;
}
