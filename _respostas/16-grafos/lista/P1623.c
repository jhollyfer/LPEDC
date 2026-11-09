// Lista · Módulo 16 · Grafos
// Exercício P1623 · ★★★ · Dijkstra com heap indexado e diminuir-chave

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define V 8

typedef struct Aresta {
    int v, km;
    struct Aresta *prox;
} Aresta;

const char *nomes[V] = {"Manaus", "Iranduba", "Manacapuru", "Novo Airao",
                        "Rio Preto da Eva", "Pres. Figueiredo", "Itacoatiara", "Careiro"};
Aresta *adj[V];

int dist[V], pi[V];
int h[V], pos[V], tam; // o heap guarda vértices; pos[v] diz onde v está
int extracoes, diminuicoes;

void liga(int a, int b, int km) {
    for (int k = 0; k < 2; k++) {
        Aresta *e = malloc(sizeof *e);
        if (e == NULL) exit(1);
        e->v = k ? a : b;
        e->km = km;
        e->prox = adj[k ? b : a];
        adj[k ? b : a] = e;
    }
}

void troca(int i, int j) {
    int t = h[i];
    h[i] = h[j];
    h[j] = t;
    pos[h[i]] = i; // sem isto, diminuir_chave perde o vértice de vista
    pos[h[j]] = j;
}

void sobe(int i) {
    while (i > 0 && dist[h[(i - 1) / 2]] > dist[h[i]]) {
        troca(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

void desce(int i) {
    for (;;) {
        int menor = i, e = 2 * i + 1, d = 2 * i + 2;
        if (e < tam && dist[h[e]] < dist[h[menor]]) menor = e;
        if (d < tam && dist[h[d]] < dist[h[menor]]) menor = d;
        if (menor == i) return;
        troca(i, menor);
        i = menor;
    }
}

int extrai_min(void) {
    int u = h[0];
    troca(0, tam - 1);
    tam--;
    pos[u] = -1; // saiu do heap: está fechado
    desce(0);
    extracoes++;
    return u;
}

void diminuir_chave(int v) {
    diminuicoes++;
    sobe(pos[v]); // dist[v] já foi diminuído por quem chamou
}

void dijkstra(int s) {
    for (int v = 0; v < V; v++) {
        dist[v] = INT_MAX;
        pi[v] = -1;
    }
    dist[s] = 0;
    tam = 0;
    for (int v = 0; v < V; v++) { // todos entram no heap
        h[tam] = v;
        pos[v] = tam;
        sobe(tam++);
    }
    while (tam > 0) {
        int u = extrai_min();
        if (dist[u] == INT_MAX) break; // o resto é inalcançável
        printf("sai %-16s %3d km\n", nomes[u], dist[u]);
        for (Aresta *e = adj[u]; e; e = e->prox)
            if (pos[e->v] != -1 && dist[u] + e->km < dist[e->v]) {
                dist[e->v] = dist[u] + e->km;
                pi[e->v] = u;
                diminuir_chave(e->v);
            }
    }
}

int main(void) {
    int estradas[][3] = {{0, 1, 27}, {1, 2, 60}, {0, 2, 98}, {2, 3, 115}, {1, 3, 180},
                         {0, 4, 80}, {4, 6, 170}, {0, 6, 270}, {0, 5, 107}, {5, 4, 60},
                         {0, 7, 100}, {7, 6, 190}};
    for (int k = 0; k < 12; k++) liga(estradas[k][0], estradas[k][1], estradas[k][2]);

    dijkstra(0);
    printf("Extrações: %d | diminuir-chave: %d\n", extracoes, diminuicoes);
    printf("Itacoatiara: %d km, chegando por %s\n", dist[6], nomes[pi[6]]);

    for (int u = 0; u < V; u++)
        while (adj[u]) {
            Aresta *e = adj[u];
            adj[u] = e->prox;
            free(e);
        }
    return 0;
}
