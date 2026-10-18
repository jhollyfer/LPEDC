// 0151 · Ordenação topológica
// Exercício E903 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define V 7

int antes[V][V]; // antes[a][b] = 1: o chamado a precisa ser resolvido antes do b

void conta_graus(int grau[]) {
    for (int b = 0; b < V; b++) grau[b] = 0;
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) grau[b] += antes[a][b];
}

void kahn_fila(void) {
    int grau[V], fila[V], inicio = 0, fim = 0;
    conta_graus(grau);
    for (int v = 0; v < V; v++)
        if (grau[v] == 0) fila[fim++] = v;
    printf("Fila:  ");
    while (inicio < fim) {
        int u = fila[inicio++];
        printf(" #%d", 101 + u);
        for (int v = 0; v < V; v++)
            if (antes[u][v] && --grau[v] == 0) fila[fim++] = v;
    }
    printf("\n");
}

void kahn_menor(void) {
    int grau[V];
    bool feito[V] = {false};
    conta_graus(grau);
    printf("Menor: ");
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V && u == -1; v++)
            if (!feito[v] && grau[v] == 0) u = v; // o menor número livre
        if (u == -1) break;
        feito[u] = true;
        printf(" #%d", 101 + u);
        for (int v = 0; v < V; v++)
            if (antes[u][v]) grau[v]--;
    }
    printf("\n");
}

int main(void) {
    int regras[][2] = {{4, 0}, {4, 1}, {5, 1}, {1, 2}, {6, 3}, {0, 3}};
    for (int k = 0; k < 6; k++) antes[regras[k][0]][regras[k][1]] = 1;
    kahn_fila();
    kahn_menor();
    return 0;
}
