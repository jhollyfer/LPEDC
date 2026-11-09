// 0186 · P e NP
// Exercício E1112 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *pessoas[V] = {"Ana", "Bia", "Cadu", "Dani", "Edu", "Fê"};
int amigos[V][V];

// o certificado é a lista do grupo; conferir custa O(k²)
bool eh_clique(const int grupo[], int k) {
    for (int i = 0; i < k; i++)
        for (int j = i + 1; j < k; j++)
            if (!amigos[grupo[i]][grupo[j]]) {
                printf("  %s e %s não são amigos\n", pessoas[grupo[i]], pessoas[grupo[j]]);
                return false;
            }
    return true;
}

void testa(const int grupo[], int k) {
    printf("Grupo:");
    for (int i = 0; i < k; i++) printf(" %s", pessoas[grupo[i]]);
    printf("\n");
    printf("  %s\n", eh_clique(grupo, k) ? "é clique" : "não é clique");
}

int main(void) {
    int pares[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {0, 3}, {3, 4}, {4, 5}, {2, 4}};
    for (int k = 0; k < 9; k++) amigos[pares[k][0]][pares[k][1]] = amigos[pares[k][1]][pares[k][0]] = 1;

    int g1[] = {0, 1, 2, 3};
    int g2[] = {1, 2, 3, 4};
    int g3[] = {2, 3, 4};
    testa(g1, 4);
    testa(g2, 4);
    testa(g3, 3);
    return 0;
}
