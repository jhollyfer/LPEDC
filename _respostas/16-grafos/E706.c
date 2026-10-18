// 0118 · Juntando tudo: a central de entregas
// Exercício E706 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *nomes[V] = {"Ana", "Bruno", "Carla", "Diego", "Elisa", "Fábio"};
int rival[V][V];

// tenta pintar com 0 e 1 por BFS; devolve false se dois rivais caem juntos
bool dividir(int time[]) {
    for (int v = 0; v < V; v++) time[v] = -1;
    for (int s = 0; s < V; s++) {
        if (time[s] != -1) continue; // laço externo: grupos soltos também
        int fila[V], inicio = 0, fim = 0;
        time[s] = 0;
        fila[fim++] = s;
        while (inicio < fim) {
            int u = fila[inicio++];
            for (int v = 0; v < V; v++) {
                if (!rival[u][v]) continue;
                if (time[v] == -1) {
                    time[v] = 1 - time[u]; // o rival vai para o outro time
                    fila[fim++] = v;
                } else if (time[v] == time[u]) {
                    printf("Impossível: %s e %s ficariam no mesmo time\n", nomes[u], nomes[v]);
                    return false;
                }
            }
        }
    }
    return true;
}

void mostrar(const int time[]) {
    for (int t = 0; t < 2; t++) {
        printf("Time %d:", t + 1);
        for (int v = 0; v < V; v++)
            if (time[v] == t) printf(" %s", nomes[v]);
        printf("\n");
    }
}

int main(void) {
    int pares[][2] = {{0, 1}, {0, 3}, {2, 1}, {2, 5}, {4, 3}};
    for (int k = 0; k < 5; k++) {
        rival[pares[k][0]][pares[k][1]] = 1;
        rival[pares[k][1]][pares[k][0]] = 1;
    }
    int time[V];
    if (dividir(time)) mostrar(time);

    rival[0][2] = rival[2][0] = 1; // Ana e Carla brigaram
    if (dividir(time)) mostrar(time);
    return 0;
}
