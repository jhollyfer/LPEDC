// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2316 · ★★☆ · O Prim preguiçoso e as sobras do heap

#include <stdbool.h>
#include <stdio.h>

#define V 5
#define MAXH 32

typedef struct {
    int peso, de, para;
} Item;

const char *pracas[V] = {"Matriz", "Feira", "Porto", "Escola", "Ginásio"};
int metros[V][V];
Item heap[MAXH];
int n_heap = 0;

void troca(int i, int j) {
    Item t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}

void poe(Item x) {
    int i = n_heap++;
    heap[i] = x;
    while (i > 0 && heap[(i - 1) / 2].peso > heap[i].peso) {
        troca(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

Item tira(void) {
    Item menor = heap[0];
    heap[0] = heap[--n_heap];
    int i = 0;
    for (;;) {
        int e = 2 * i + 1, d = e + 1, m = i;
        if (e < n_heap && heap[e].peso < heap[m].peso) m = e;
        if (d < n_heap && heap[d].peso < heap[m].peso) m = d;
        if (m == i) break;
        troca(i, m);
        i = m;
    }
    return menor;
}

int main(void) {
    int cabos[][3] = {{0, 1, 4}, {0, 2, 1}, {1, 2, 2}, {1, 3, 5}, {2, 3, 8}, {3, 4, 3}, {2, 4, 9}};
    for (int k = 0; k < 7; k++) {
        metros[cabos[k][0]][cabos[k][1]] = cabos[k][2];
        metros[cabos[k][1]][cabos[k][0]] = cabos[k][2];
    }

    bool na_rede[V] = {false};
    int total = 0, entraram = 1;
    na_rede[0] = true;
    for (int v = 0; v < V; v++)
        if (metros[0][v]) poe((Item){metros[0][v], 0, v});

    while (n_heap > 0 && entraram < V) {
        Item x = tira();
        if (na_rede[x.para]) {
            printf("tira %s-%s (%d): descartada, %s já está na rede\n", pracas[x.de], pracas[x.para], x.peso, pracas[x.para]);
            continue;
        }
        printf("tira %s-%s (%d): entra %s\n", pracas[x.de], pracas[x.para], x.peso, pracas[x.para]);
        na_rede[x.para] = true;
        entraram++;
        total += x.peso;
        for (int v = 0; v < V; v++)
            if (metros[x.para][v] && !na_rede[v]) poe((Item){metros[x.para][v], x.para, v});
    }
    printf("Total: %d metros; sobraram %d itens no heap\n", total, n_heap);
    return 0;
}
