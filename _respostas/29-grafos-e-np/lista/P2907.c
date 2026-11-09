// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2907 · ★☆☆ · Clique ou independente?

#include <stdbool.h>
#include <stdio.h>

#define V 8

int amigo[V][V];
const char *nomes[3] = {"nenhum dos dois", "independente", "clique"};

int tipo(const int s[], int k) {
    int pares = 0, amigos = 0;
    for (int i = 0; i < k; i++)
        for (int j = i + 1; j < k; j++) pares++, amigos += amigo[s[i]][s[j]];
    if (amigos == pares) return 2;
    if (amigos == 0) return 1;
    return 0;
}

void testa(const int s[], int k) {
    printf("{");
    for (int i = 0; i < k; i++) printf("%s%d", i ? ", " : "", s[i]);
    printf("}: %s\n", nomes[tipo(s, k)]);
}

int main(void) {
    int a[][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {4, 6}};
    for (int e = 0; e < 11; e++) amigo[a[e][0]][a[e][1]] = amigo[a[e][1]][a[e][0]] = 1;
    int g1[] = {0, 1, 2, 3}, g2[] = {0, 4, 7}, g3[] = {4, 5, 6}, g4[] = {2, 5, 7}, g5[] = {3, 4, 5};
    testa(g1, 4);
    testa(g2, 3);
    testa(g3, 3);
    testa(g4, 3);
    testa(g5, 3);
    return 0;
}
