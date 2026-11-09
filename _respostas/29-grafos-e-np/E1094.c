// 0183 · Hamiltoniano
// Exercício E1094 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define V 5

const char *pontos[V] = {"Mirante", "Cachoeira", "Gruta", "Lagoa", "Pedra"};
int trilha[V][V];
int rota[V];
bool usado[V];

bool caminho(int pos) {
    if (pos == V) return true; // não precisa voltar ao começo
    for (int v = 0; v < V; v++) {
        if (!trilha[rota[pos - 1]][v] || usado[v]) continue;
        rota[pos] = v;
        usado[v] = true;
        if (caminho(pos + 1)) return true;
        usado[v] = false;
    }
    return false;
}

int main(void) {
    int trechos[][2] = {{0, 1}, {1, 2}, {2, 0}, {0, 3}, {3, 4}, {4, 0}};
    for (int k = 0; k < 6; k++) trilha[trechos[k][0]][trechos[k][1]] = trilha[trechos[k][1]][trechos[k][0]] = 1;

    for (int ini = 0; ini < V; ini++) {
        for (int v = 0; v < V; v++) usado[v] = false;
        rota[0] = ini;
        usado[ini] = true;
        if (caminho(1)) {
            printf("Começando em %s:", pontos[ini]);
            for (int i = 0; i < V; i++) printf(" %s", pontos[rota[i]]);
            printf("\n");
            return 0;
        }
        printf("Começando em %s: não dá\n", pontos[ini]);
    }
    return 0;
}
