// 0109 · Grafos
// Exercício E650 · ★☆☆

#include <stdio.h>

#define V 4

int main(void) {
    const char *nomes[V] = {"Leo", "Mia", "Rui", "Sol"};
    int deve[V][V] = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 0},
    };
    int saida[V], entrada[V];

    for (int i = 0; i < V; i++) {
        saida[i] = 0;
        entrada[i] = 0;
        for (int j = 0; j < V; j++) {
            saida[i] += deve[i][j];   // linha: setas que saem de i
            entrada[i] += deve[j][i]; // coluna: setas que chegam em i
        }
        printf("%s deve para %d e recebe de %d\n", nomes[i], saida[i], entrada[i]);
    }

    printf("Sem dívidas:");
    for (int i = 0; i < V; i++)
        if (saida[i] == 0) printf(" %s", nomes[i]);
    printf("\nNinguém deve para:");
    for (int i = 0; i < V; i++)
        if (entrada[i] == 0) printf(" %s", nomes[i]);
    printf("\n");
    return 0;
}
