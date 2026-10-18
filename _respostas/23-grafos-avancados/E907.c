// 0152 · Kruskal: árvore geradora mínima
// Exercício E907 · ★☆☆

#include <stdio.h>

#define V 5
#define E 7

int main(void) {
    const char *canteiros[V] = {"Alface", "Tomate", "Couve", "Cenoura", "Ervas"};
    int trechos[E][3] = {{0, 2, 2}, {1, 4, 3}, {0, 1, 4}, {2, 1, 5},
                         {3, 4, 6}, {2, 3, 8}, {0, 4, 9}}; // já em ordem de metros
    int grupo[V];
    for (int v = 0; v < V; v++) grupo[v] = v;

    int total = 0, usados = 0;
    for (int k = 0; k < E && usados < V - 1; k++) {
        int a = trechos[k][0], b = trechos[k][1];
        if (grupo[a] == grupo[b]) continue; // fecharia ciclo
        int velho = grupo[b];
        for (int v = 0; v < V; v++) // todo o grupo de b passa para o grupo de a
            if (grupo[v] == velho) grupo[v] = grupo[a];
        total += trechos[k][2];
        usados++;
        printf("%s-%s (%d m)\n", canteiros[a], canteiros[b], trechos[k][2]);
    }
    printf("Mangueira total: %d m\n", total);
    return 0;
}
