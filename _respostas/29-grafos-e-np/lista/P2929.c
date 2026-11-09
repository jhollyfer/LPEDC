// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2929 · ★★★ · Cobertura exata por ramificação

#include <stdbool.h>
#include <stdio.h>

#define V 12
#define E 14

const int a[E][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {4, 5}, {5, 6}, {6, 4},
                     {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 7}, {0, 4}, {2, 7}};
bool em[V];
long chamadas = 0;

bool cobre(int k) {
    chamadas++;
    int e = 0;
    while (e < E && (em[a[e][0]] || em[a[e][1]])) e++;
    if (e == E) return true;
    if (k == 0) return false;
    for (int lado = 0; lado < 2; lado++) {
        int u = a[e][lado];
        em[u] = true;
        if (cobre(k - 1)) return true;
        em[u] = false;
    }
    return false;
}

int main(void) {
    int k = 0;
    while (!cobre(k)) k++;
    printf("Menor cobertura: %d vértices:", k);
    for (int v = 0; v < V; v++)
        if (em[v]) printf(" %d", v);
    printf("\nChamadas: %ld (força bruta: %d máscaras)\n", chamadas, 1 << V);
    return 0;
}
