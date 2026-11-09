// Lista · Módulo 16 · Grafos
// Exercício P1629 · ★★★ · Três representações do mesmo bairro em grade

#include <stdio.h>
#include <stdlib.h>

#define N 30
#define V (N * N)
#define MAXE (2 * N * (N - 1))

typedef struct No {
    int v;
    struct No *prox;
} No;

int arestas[MAXE][2];
int matriz[V][V];
No *lista[V];
long consultas;

void insere(int u, int v) {
    No *n = malloc(sizeof *n);
    if (n == NULL) exit(1);
    n->v = v;
    n->prox = lista[u];
    lista[u] = n;
}

void bfs(int usa_matriz, int d[]) {
    int fila[V], ini = 0, fim = 0;
    for (int v = 0; v < V; v++) d[v] = -1;
    d[0] = 0;
    fila[fim++] = 0;
    while (ini < fim) {
        int u = fila[ini++];
        if (usa_matriz) {
            for (int v = 0; v < V; v++) {
                consultas++;
                if (matriz[u][v] && d[v] == -1) {
                    d[v] = d[u] + 1;
                    fila[fim++] = v;
                }
            }
        } else {
            for (No *p = lista[u]; p; p = p->prox) {
                consultas++;
                if (d[p->v] == -1) {
                    d[p->v] = d[u] + 1;
                    fila[fim++] = p->v;
                }
            }
        }
    }
}

int main(void) {
    int e = 0;
    for (int l = 0; l < N; l++)
        for (int c = 0; c < N; c++) {
            int u = l * N + c;
            if (c + 1 < N) { arestas[e][0] = u; arestas[e][1] = u + 1; e++; } // direita
            if (l + 1 < N) { arestas[e][0] = u; arestas[e][1] = u + N; e++; } // baixo
        }
    for (int k = 0; k < e; k++) { // arestas -> matriz e -> lista
        int u = arestas[k][0], v = arestas[k][1];
        matriz[u][v] = matriz[v][u] = 1;
        insere(u, v);
        insere(v, u);
    }
    printf("V = %d, E = %d\n", V, e);

    static int dm[V], dl[V];
    consultas = 0;
    bfs(1, dm);
    long cm = consultas;
    consultas = 0;
    bfs(0, dl);
    int iguais = 1, maxd = 0;
    for (int v = 0; v < V; v++) {
        if (dm[v] != dl[v]) iguais = 0;
        if (dm[v] > maxd) maxd = dm[v];
    }
    printf("BFS: d máximo %d | d igual nas duas: %s\n", maxd, iguais ? "sim" : "não");
    printf("Consultas: matriz %ld, lista %ld\n", cm, consultas);

    printf("Memória: arestas %zu bytes, lista %zu bytes, matriz %zu bytes\n",
           (size_t)e * 2 * sizeof(int), V * sizeof(No *) + (size_t)2 * e * sizeof(No),
           (size_t)V * V * sizeof(int));
    long long vg = 1000LL * 1000;
    printf("Grade 1000 x 1000: matriz de %lld bytes\n", vg * vg * (long long)sizeof(int));

    for (int u = 0; u < V; u++)
        while (lista[u]) {
            No *p = lista[u];
            lista[u] = p->prox;
            free(p);
        }
    return 0;
}
