// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2906 · ★☆☆ · Verificador de cobertura com limite

#include <stdbool.h>
#include <stdio.h>

#define V 7
#define E 8

const int cabo[E][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {5, 6}};

bool confere(const int c[], int tam, int k) {
    if (tam > k) {
        printf("rejeitado: %d vértices, limite %d\n", tam, k);
        return false;
    }
    bool em[V] = {false};
    for (int i = 0; i < tam; i++) em[c[i]] = true;
    for (int e = 0; e < E; e++)
        if (!em[cabo[e][0]] && !em[cabo[e][1]]) {
            printf("rejeitado: cabo %d-%d descoberto\n", cabo[e][0], cabo[e][1]);
            return false;
        }
    printf("aceito\n");
    return true;
}

int main(void) {
    int c1[] = {0, 3, 4, 5}, c2[] = {1, 2, 4, 6}, c3[] = {0, 3, 4, 6}, c4[] = {1, 2, 5, 6};
    confere(c1, 4, 4);
    confere(c2, 4, 4);
    confere(c3, 4, 3);
    confere(c4, 4, 4);
    return 0;
}
