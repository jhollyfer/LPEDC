// 0183 · Hamiltoniano
// Exercício E1096 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define V 5

const char *times[V] = {"Bahia", "Ceará", "Fortaleza", "Remo", "Sport"};
int venceu[V][V]; // venceu[a][b] = 1: a ganhou de b (grafo dirigido)
int ordem[V];
bool usado[V];

bool fila(int pos) {
    if (pos == V) return true;
    for (int v = 0; v < V; v++) {
        if (!venceu[ordem[pos - 1]][v] || usado[v]) continue;
        ordem[pos] = v;
        usado[v] = true;
        if (fila(pos + 1)) return true;
        usado[v] = false;
    }
    return false;
}

int main(void) {
    int jogos[][2] = {{0, 1}, {2, 0}, {0, 4}, {3, 0}, {1, 2}, {1, 3}, {4, 1}, {2, 3}, {2, 4}, {4, 3}};
    for (int k = 0; k < 10; k++) venceu[jogos[k][0]][jogos[k][1]] = 1;

    for (int ini = 0; ini < V; ini++) {
        for (int v = 0; v < V; v++) usado[v] = false;
        ordem[0] = ini;
        usado[ini] = true;
        if (fila(1)) {
            for (int i = 0; i < V; i++) printf("%s%s", times[ordem[i]], i < V - 1 ? " > " : "\n");
            return 0;
        }
    }
    printf("Nenhuma fila\n");
    return 0;
}
