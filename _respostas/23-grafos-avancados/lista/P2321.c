// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2321 · ★★★ · A segunda melhor rede

#include <stdio.h>
#include <stdlib.h>

#define V 5
#define E 7

typedef struct {
    int a, b, custo;
} Aresta;

const char *aldeias[V] = {"Aldeia Nova", "Boa Esperança", "Cajual", "Daracuí", "Extrema"};
Aresta lista[E] = {{0, 1, 4}, {0, 2, 6}, {1, 2, 5}, {1, 3, 3}, {2, 3, 7}, {2, 4, 8}, {3, 4, 9}};
int pai[V];

int acha(int x) {
    while (pai[x] != x) x = pai[x];
    return x;
}

int compara(const void *p, const void *q) {
    return ((const Aresta *)p)->custo - ((const Aresta *)q)->custo;
}

// Kruskal que ignora a aresta "proibida"; marca em usada[] as escolhidas.
// Devolve o total, ou -1 se não deu para ligar todo mundo.
int kruskal(int proibida, int usada[]) {
    for (int v = 0; v < V; v++) pai[v] = v;
    int total = 0, aceitas = 0;
    for (int i = 0; i < E; i++) {
        usada[i] = 0;
        if (i == proibida) continue;
        int ra = acha(lista[i].a), rb = acha(lista[i].b);
        if (ra == rb || aceitas == V - 1) continue;
        pai[ra] = rb;
        usada[i] = 1;
        aceitas++;
        total += lista[i].custo;
    }
    return aceitas == V - 1 ? total : -1;
}

void nome(int i) {
    printf("%s-%s (%d)", aldeias[lista[i].a], aldeias[lista[i].b], lista[i].custo);
}

int main(void) {
    qsort(lista, E, sizeof(Aresta), compara);
    int agm[E];
    int melhor = kruskal(-1, agm);
    printf("Árvore mínima: %d\n", melhor);
    for (int i = 0; i < E; i++)
        if (agm[i]) {
            printf("  ");
            nome(i);
            printf("\n");
        }

    int segunda = -1, saiu = -1, entrou = -1;
    for (int i = 0; i < E; i++) {
        if (!agm[i]) continue;
        int outra[E];
        int t = kruskal(i, outra);
        printf("sem ");
        nome(i);
        printf(": %d\n", t);
        if (t != -1 && (segunda == -1 || t < segunda)) {
            segunda = t;
            saiu = i;
            for (int j = 0; j < E; j++)
                if (outra[j] && !agm[j]) entrou = j;
        }
    }
    printf("Segunda melhor: %d, trocando ", segunda);
    nome(saiu);
    printf(" por ");
    nome(entrou);
    printf("\n");
    return 0;
}
