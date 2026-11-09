// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2320 · ★★☆ · Quantos jeitos de descer a ladeira

#include <stdio.h>

#define V 7

const char *pontos[V] = {"Alto da Sé", "Amparo", "Misericórdia", "Bonsucesso", "Carmo", "Varadouro", "Praia"};
int desce[V][V];

int main(void) {
    int ladeiras[][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 5}, {4, 5}, {3, 6}, {5, 6}, {4, 6}, {1, 4}};
    for (int k = 0; k < 11; k++) desce[ladeiras[k][0]][ladeiras[k][1]] = 1;

    int grau[V] = {0}, ordem[V], ini = 0, fim = 0;
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) grau[b] += desce[a][b];
    for (int u = 0; u < V; u++)
        if (grau[u] == 0) ordem[fim++] = u;
    while (ini < fim) {
        int u = ordem[ini++];
        for (int v = 0; v < V; v++)
            if (desce[u][v] && --grau[v] == 0) ordem[fim++] = v;
    }

    // jeitos[v]: quantos caminhos diferentes saem do Alto e chegam em v
    long jeitos[V] = {0};
    jeitos[0] = 1;
    for (int i = 0; i < V; i++) {
        int u = ordem[i];
        for (int v = 0; v < V; v++)
            if (desce[u][v]) jeitos[v] += jeitos[u];
    }
    for (int i = 0; i < V; i++) printf("%s: %ld\n", pontos[ordem[i]], jeitos[ordem[i]]);
    return 0;
}
