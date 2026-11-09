// 0183 · Hamiltoniano
// Exercício E1097 · ★★★

#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *paradas[V] = {"Escola", "Ana", "Bia", "Caio", "Davi", "Elis", "Fabi"};
int rua[V][V];
int rota[V];
bool usada[V];

bool hamilton(int pos) {
    if (pos == V) return rua[rota[V - 1]][rota[0]];
    for (int v = 1; v < V; v++) {
        if (!rua[rota[pos - 1]][v] || usada[v]) continue;
        rota[pos] = v;
        usada[v] = true;
        if (hamilton(pos + 1)) return true;
        usada[v] = false; // desfaz a escolha antes de tentar a próxima
    }
    return false;
}

int main(void) {
    int ruas[][2] = {{0, 1}, {0, 2}, {0, 5}, {1, 3}, {1, 6}, {2, 3}, {2, 4}, {3, 4}, {4, 5}, {4, 6}};
    for (int k = 0; k < 10; k++) rua[ruas[k][0]][ruas[k][1]] = rua[ruas[k][1]][ruas[k][0]] = 1;

    rota[0] = 0;
    usada[0] = true;
    if (hamilton(1)) {
        printf("Rota da van:");
        for (int i = 0; i < V; i++) printf(" %s", paradas[rota[i]]);
        printf(" %s\n", paradas[rota[0]]);
    } else {
        printf("Não existe rota\n");
    }
    return 0;
}
