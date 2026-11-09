// 0188 · Aproximação
// Exercício E1125 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define V 7
#define E 8

const char nome[V] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

// a 2-aproximação depende da ordem em que as ruas são examinadas
int cobertura(int rua[E][2], bool em[]) {
    int tam = 0;
    for (int v = 0; v < V; v++) em[v] = false;
    for (int k = 0; k < E; k++) {
        int a = rua[k][0], b = rua[k][1];
        if (em[a] || em[b]) continue;
        em[a] = em[b] = true;
        tam += 2;
    }
    return tam;
}

int otimo(int rua[E][2]) {
    int melhor = V;
    for (int m = 0; m < (1 << V); m++) {
        bool ok = true;
        for (int k = 0; k < E && ok; k++)
            if (!(m >> rua[k][0] & 1) && !(m >> rua[k][1] & 1)) ok = false;
        int tam = 0;
        for (int v = 0; v < V; v++) tam += m >> v & 1;
        if (ok && tam < melhor) melhor = tam;
    }
    return melhor;
}

void mostra(const char *rotulo, int rua[E][2]) {
    bool em[V];
    int tam = cobertura(rua, em);
    printf("%s: %d câmeras em", rotulo, tam);
    for (int v = 0; v < V; v++)
        if (em[v]) printf(" %c", nome[v]);
    printf("\n");
}

int main(void) {
    int ordem1[E][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 5}, {2, 4}};
    int ordem2[E][2] = {{1, 5}, {2, 4}, {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    mostra("Ordem 1", ordem1);
    mostra("Ordem 2", ordem2);
    printf("Ótimo: %d câmeras\n", otimo(ordem1));
    return 0;
}
