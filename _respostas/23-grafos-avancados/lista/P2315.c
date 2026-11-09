// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2315 · ★★☆ · O union-find que solta galhos

#include <stdio.h>
#include <stdlib.h>

#define V 6
#define E 9

typedef struct {
    int a, b, custo;
} Aresta;

const char *pontos[V] = {"Portão", "Lago", "Mirante", "Gruta", "Cachoeira", "Camping"};
int pai[V];

int acha(int x) {
    while (pai[x] != x) x = pai[x];
    return x;
}

int compara(const void *p, const void *q) {
    return ((const Aresta *)p)->custo - ((const Aresta *)q)->custo;
}

int main(void) {
    Aresta trilhas[E] = {{0, 1, 1}, {0, 2, 2}, {1, 2, 3}, {2, 3, 4}, {3, 4, 5},
                         {4, 5, 6}, {1, 5, 7}, {0, 3, 8}, {2, 5, 9}};
    qsort(trilhas, E, sizeof(Aresta), compara);
    for (int v = 0; v < V; v++) pai[v] = v;

    int total = 0, aceitas = 0;
    for (int i = 0; i < E && aceitas < V - 1; i++) {
        int ra = acha(trilhas[i].a), rb = acha(trilhas[i].b);
        if (ra == rb) continue;
        pai[ra] = rb; // o conserto: liga os REPRESENTANTES, não os vértices
        aceitas++;
        total += trilhas[i].custo;
        printf("%s-%s (%d)\n", pontos[trilhas[i].a], pontos[trilhas[i].b], trilhas[i].custo);
    }
    printf("Total: R$ %d mil\n", total);
    return 0;
}
