// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2919 · ★★☆ · Quão longe do ótimo fica a 2-aproximação?

#include <stdbool.h>
#include <stdio.h>

#define V 8

void compara(const char *nome, int ne, int a[][2]) {
    bool em[V] = {false};
    int aprox = 0;
    for (int k = 0; k < ne; k++)
        if (!em[a[k][0]] && !em[a[k][1]]) em[a[k][0]] = em[a[k][1]] = true, aprox += 2;
    int otimo = V;
    for (int m = 0; m < (1 << V); m++) {
        bool cobre = true;
        for (int k = 0; k < ne && cobre; k++)
            if (!(m >> a[k][0] & 1) && !(m >> a[k][1] & 1)) cobre = false;
        int tam = 0;
        for (int v = 0; v < V; v++) tam += m >> v & 1;
        if (cobre && tam < otimo) otimo = tam;
    }
    printf("%s: aprox %d, ótimo %d, razão %.2f\n", nome, aprox, otimo, (double)aprox / otimo);
}

int main(void) {
    int caminho[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
    int estrela[][2] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}};
    int misto[][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {4, 5}, {5, 6}, {6, 7}};
    compara("caminho", 7, caminho);
    compara("estrela", 7, estrela);
    compara("completo + caminho", 9, misto);
    return 0;
}
