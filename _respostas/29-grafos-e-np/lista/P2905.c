// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2905 · ★☆☆ · Conferindo a rota do ônibus circular

#include <stdbool.h>
#include <stdio.h>

#define V 6

int rua[V][V];

bool valida(const int r[], int n) {
    if (n != V) {
        printf("falta ponto\n");
        return false;
    }
    bool visto[V] = {false};
    for (int i = 0; i < n; i++) {
        if (visto[r[i]]) {
            printf("repete o ponto %d\n", r[i]);
            return false;
        }
        visto[r[i]] = true;
    }
    for (int i = 0; i < n; i++) {
        int x = r[i], y = r[(i + 1) % n];
        if (!rua[x][y]) {
            printf("não há rua %d->%d\n", x, y);
            return false;
        }
    }
    printf("ok\n");
    return true;
}

int main(void) {
    int ruas[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}, {1, 4}, {3, 1}, {4, 2}, {2, 0}};
    for (int k = 0; k < 10; k++) rua[ruas[k][0]][ruas[k][1]] = 1;
    int a[] = {0, 1, 2, 3, 4, 5}, b[] = {0, 1, 4, 2, 3, 1}, c[] = {0, 1, 4, 5, 2, 3}, d[] = {0, 1, 4, 2, 3};
    printf("A: ");
    valida(a, 6);
    printf("B: ");
    valida(b, 6);
    printf("C: ");
    valida(c, 6);
    printf("D: ");
    valida(d, 5);
    return 0;
}
