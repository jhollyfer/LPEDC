// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2913 · ★★☆ · Todos os caminhos hamiltonianos de s a t

#include <stdbool.h>
#include <stdio.h>

#define V 6

int via[V][V], rota[V], total = 0;
bool usado[V];
long chamadas = 0;

void busca(int pos) {
    chamadas++;
    if (pos == V) {
        total++;
        printf("Caminho %d:", total);
        for (int i = 0; i < V; i++) printf(" %d", rota[i]);
        printf("\n");
        return;
    }
    for (int v = 1; v < V; v++) {
        if (usado[v] || !via[rota[pos - 1]][v]) continue;
        if (v == V - 1 && pos != V - 1) continue; // a obra 5 só no fim
        usado[v] = true;
        rota[pos] = v;
        busca(pos + 1);
        usado[v] = false;
    }
}

int main(void) {
    int a[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 5}};
    for (int k = 0; k < 9; k++) via[a[k][0]][a[k][1]] = via[a[k][1]][a[k][0]] = 1;
    rota[0] = 0;
    usado[0] = true;
    busca(1);
    printf("Total: %d caminhos, %ld chamadas\n", total, chamadas);
    return 0;
}
