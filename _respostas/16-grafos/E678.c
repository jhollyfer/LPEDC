// 0113 · Juntando tudo: a central de entregas
// Exercício E678 · ★★★

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define V 8
#define E 11
#define INFINITO INT_MAX

typedef struct No {
    int destino, km;
    struct No *prox;
} No;

typedef struct {
    int dist, v;
} Item;

// heap mínimo de Item, ordenado por dist
Item heap[2 * E + 1]; // cada aresta empurra no máximo 2 vezes, + a origem
int tam = 0;

void empurrar(int dist, int v) {
    int i = tam++;
    heap[i] = (Item){dist, v};
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) { // sobe
        Item t = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = t;
        i = (i - 1) / 2;
    }
}

Item tirar(void) {
    Item topo = heap[0];
    heap[0] = heap[--tam];
    int i = 0;
    for (;;) { // desce
        int menor = i, e = 2 * i + 1, d = 2 * i + 2;
        if (e < tam && heap[e].dist < heap[menor].dist) menor = e;
        if (d < tam && heap[d].dist < heap[menor].dist) menor = d;
        if (menor == i) break;
        Item t = heap[i];
        heap[i] = heap[menor];
        heap[menor] = t;
        i = menor;
    }
    return topo;
}

bool ligar(No *lista[], int a, int b, int km) {
    No *n1 = malloc(sizeof *n1);
    No *n2 = malloc(sizeof *n2);
    if (n1 == NULL || n2 == NULL) {
        free(n1);
        free(n2);
        return false;
    }
    *n1 = (No){b, km, lista[a]};
    lista[a] = n1;
    *n2 = (No){a, km, lista[b]};
    lista[b] = n2;
    return true;
}

int main(void) {
    const char *nomes[V] = {"Porto Alegre", "Canoas", "Novo Hamburgo", "Gramado",
                            "Caxias", "Bento", "Torres", "Pelotas"};
    int estradas[E][3] = {{0, 1, 15}, {1, 2, 25}, {2, 3, 60}, {0, 3, 115}, {2, 4, 90}, {3, 4, 45},
                          {4, 5, 40}, {0, 6, 200}, {4, 6, 210}, {0, 7, 260}, {1, 4, 120}};
    No *lista[V] = {NULL};
    bool ok = true;
    for (int k = 0; k < E && ok; k++) ok = ligar(lista, estradas[k][0], estradas[k][1], estradas[k][2]);

    int dist[V];
    for (int v = 0; v < V; v++) dist[v] = INFINITO;
    int retiradas = 0;
    if (ok) {
        dist[0] = 0;
        empurrar(0, 0);
        while (tam > 0) {
            Item it = tirar();
            retiradas++;
            if (it.dist > dist[it.v]) continue; // item velho: já achamos coisa melhor
            for (No *p = lista[it.v]; p != NULL; p = p->prox) {
                int nova = it.dist + p->km;
                if (nova < dist[p->destino]) {
                    dist[p->destino] = nova;
                    empurrar(nova, p->destino); // em vez de "diminuir a chave"
                }
            }
        }
        for (int v = 1; v < V; v++) printf("%-13s %3d km\n", nomes[v], dist[v]);
        printf("Itens tirados do heap: %d\n", retiradas);
    }

    for (int v = 0; v < V; v++) {
        No *p = lista[v];
        while (p != NULL) {
            No *prox = p->prox;
            free(p);
            p = prox;
        }
    }
    return ok ? 0 : 1;
}
