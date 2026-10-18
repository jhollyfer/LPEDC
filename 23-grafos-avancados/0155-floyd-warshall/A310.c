// A310 · Fecho transitivo: de qual terminal dá para chegar em qual

#include <stdbool.h>
#include <stdio.h>

#define V 5

int main(void) {
    const char *terminais[V] = {"Norte", "Sul", "Leste", "Oeste", "Centro"};
    bool chega[V][V] = {{false}}; // linhas de ônibus de mão única
    int linhas[][2] = {{0, 4}, {4, 1}, {1, 4}, {2, 0}, {3, 3}};
    for (int k = 0; k < 5; k++) chega[linhas[k][0]][linhas[k][1]] = true;

    // Warshall: o Floyd-Warshall com || no lugar de min e && no lugar de +
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                chega[i][j] = chega[i][j] || (chega[i][k] && chega[k][j]);

    printf("%-8s", "de\\para");
    for (int j = 0; j < V; j++) printf(j < V - 1 ? "%-7s" : "%s\n", terminais[j]);
    for (int i = 0; i < V; i++) {
        int quantos = 0;
        printf("%-8s", terminais[i]);
        for (int j = 0; j < V; j++) {
            printf("%-7s", chega[i][j] ? "sim" : ".");
            quantos += chega[i][j] && i != j;
        }
        printf("(%d)\n", quantos);
    }
    return 0;
}
// Saída:
// de\para Norte  Sul    Leste  Oeste  Centro
// Norte   .      sim    .      .      sim    (2)
// Sul     .      sim    .      .      sim    (1)
// Leste   sim    sim    .      .      sim    (3)
// Oeste   .      .      .      sim    .      (0)
// Centro  .      sim    .      .      sim    (1)
//
// Repare na diagonal: Sul chega no próprio Sul (vai ao Centro e volta),
// Oeste tem uma linha circular que volta para ele, e Leste não volta nunca.
// O número entre parênteses conta os OUTROS terminais alcançáveis.
