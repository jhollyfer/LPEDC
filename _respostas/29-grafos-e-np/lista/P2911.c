// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2911 · ★★☆ · Circuito com ruas paralelas

#include <stdbool.h>
#include <stdio.h>

#define E 7

const int rua[E][2] = {{0, 1}, {1, 0}, {1, 2}, {2, 3}, {3, 1}, {2, 4}, {4, 2}};
bool usada[E];

int main(void) {
    int pilha_v[E + 1], pilha_r[E + 1], topo = 0;
    int circ_v[E + 1], circ_r[E + 1], n = 0;
    pilha_v[topo] = 0, pilha_r[topo] = -1, topo++;
    while (topo > 0) {
        int u = pilha_v[topo - 1], k = 0;
        while (k < E && (usada[k] || (rua[k][0] != u && rua[k][1] != u))) k++;
        if (k < E) {
            usada[k] = true;
            pilha_v[topo] = rua[k][0] + rua[k][1] - u, pilha_r[topo] = k, topo++;
        } else {
            topo--;
            circ_v[n] = pilha_v[topo], circ_r[n] = pilha_r[topo], n++;
        }
    }
    printf("Circuito:");
    for (int i = n - 1; i >= 0; i--) printf(" %d", circ_v[i]);
    printf("\nRuas:");
    for (int i = n - 2; i >= 0; i--) printf(" r%d", circ_r[i]);
    printf("\n");
    return 0;
}
