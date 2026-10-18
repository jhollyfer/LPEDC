// 0150 · Componentes e ciclos
// Exercício E898 · ★★☆

#include <stdio.h>

#define V 11

const char *pontos[V] = {"Portaria", "Mirante", "Cachoeira", "Lago", "Bosque", "Pico",
                         "Gruta", "Rio", "Ponte", "Ninho", "Toca"};
int trilha[V][V];
int grupo[V];

void marca(int u, int g) {
    grupo[u] = g;
    for (int v = 0; v < V; v++)
        if (trilha[u][v] && grupo[v] == 0) marca(v, g);
}

int main(void) {
    int trilhas[][2] = {{0, 1}, {1, 2}, {2, 0},          // parque 1
                        {3, 4}, {4, 5}, {4, 6},          // parque 2
                        {7, 8}, {8, 9}, {9, 7}, {7, 10}}; // parque 3
    int n_trilhas = 10;
    for (int k = 0; k < n_trilhas; k++) {
        trilha[trilhas[k][0]][trilhas[k][1]] = 1;
        trilha[trilhas[k][1]][trilhas[k][0]] = 1;
    }

    int grupos = 0;
    for (int u = 0; u < V; u++)
        if (grupo[u] == 0) marca(u, ++grupos);

    for (int g = 1; g <= grupos; g++) {
        int n_pontos = 0, soma_graus = 0;
        printf("Parque %d:", g);
        for (int v = 0; v < V; v++) {
            if (grupo[v] != g) continue;
            printf(" %s", pontos[v]);
            n_pontos++;
            for (int w = 0; w < V; w++) soma_graus += trilha[v][w];
        }
        int n_arestas = soma_graus / 2; // cada trilha conta nas duas pontas
        printf(" | %d pontos, %d trilhas, %s\n", n_pontos, n_arestas,
               n_arestas == n_pontos - 1 ? "sem circuito" : "tem circuito");
    }
    return 0;
}
