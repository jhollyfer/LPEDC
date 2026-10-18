// 0150 · Componentes e ciclos
// Exercício E895 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *ilhas[V] = {"Norte", "Sul", "Leste", "Oeste", "Coral", "Farol", "Gaivota"};
int ponte[V][V];
int grupo[V]; // 0 = ainda sem grupo

void marca(int u, int g) {
    grupo[u] = g;
    for (int v = 0; v < V; v++)
        if (ponte[u][v] && grupo[v] == 0) marca(v, g);
}

int main(void) {
    int pontes[][2] = {{0, 5}, {5, 4}, {1, 2}, {3, 1}};
    for (int k = 0; k < 4; k++) {
        ponte[pontes[k][0]][pontes[k][1]] = 1;
        ponte[pontes[k][1]][pontes[k][0]] = 1;
    }

    int grupos = 0;
    for (int u = 0; u < V; u++)
        if (grupo[u] == 0) marca(u, ++grupos);

    printf("Grupos de ilhas: %d\n", grupos);
    for (int g = 1; g <= grupos; g++) {
        printf("  grupo %d:", g);
        for (int v = 0; v < V; v++)
            if (grupo[v] == g) printf(" %s", ilhas[v]);
        printf("\n");
    }
    printf("Pontes novas para ligar tudo: %d\n", grupos - 1);
    return 0;
}
