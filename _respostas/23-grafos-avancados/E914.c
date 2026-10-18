// 0153 · Prim: a árvore que cresce
// Exercício E914 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define V 6
#define CAP 40

typedef struct {
    int chave, v, de;
} Item;

Item heap[CAP];
int n = 0;

void troca(int i, int j) {
    Item t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}

void insere(Item x) {
    int i = n++;
    heap[i] = x;
    while (i > 0 && heap[(i - 1) / 2].chave > heap[i].chave) {
        troca(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

Item tira(void) {
    Item menor = heap[0];
    heap[0] = heap[--n];
    int i = 0;
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && heap[f + 1].chave < heap[f].chave) f++;
        if (heap[i].chave <= heap[f].chave) break;
        troca(i, f);
        i = f;
    }
    return menor;
}

int main(void) {
    const char *estacoes[V] = {"Rodoviária", "Praça", "Museu", "Orla", "Feira", "Estádio"};
    int dist[V][V] = {0};
    int trechos[][3] = {{0, 1, 5}, {0, 4, 3}, {1, 2, 4}, {1, 4, 6}, {2, 3, 2},
                        {4, 3, 7}, {3, 5, 8}, {2, 5, 9}, {4, 5, 10}};
    for (int k = 0; k < 9; k++) {
        dist[trechos[k][0]][trechos[k][1]] = trechos[k][2];
        dist[trechos[k][1]][trechos[k][0]] = trechos[k][2];
    }

    bool na_rede[V] = {false};
    int total = 0;
    insere((Item){0, 0, -1});
    while (n > 0) {
        Item it = tira();
        if (na_rede[it.v]) continue; // item velho
        na_rede[it.v] = true;
        total += it.chave;
        if (it.de >= 0) printf("%s - %s: %d\n", estacoes[it.de], estacoes[it.v], it.chave);
        for (int w = 0; w < V; w++)
            if (dist[it.v][w] && !na_rede[w]) insere((Item){dist[it.v][w], w, it.v});
    }
    printf("Ciclofaixa total: %d quarteirões\n", total);
    return 0;
}
