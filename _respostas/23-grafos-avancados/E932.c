// 0156 · Juntando tudo: o assistente do calouro
// Exercício E932 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *disc[V] = {"Lógica", "Cálculo", "C", "Estruturas", "Arquivos", "Grafos", "Projeto"};
int antes[V][V];

// quantas disciplinas a DFS alcança a partir de u (sem contar u)
int alcance(int u, bool visto[]) {
    int total = 0;
    for (int v = 0; v < V; v++)
        if (antes[u][v] && !visto[v]) {
            visto[v] = true;
            total += 1 + alcance(v, visto);
        }
    return total;
}

int main(void) {
    int regras[][2] = {{0, 2}, {2, 3}, {2, 4}, {1, 5}, {3, 5}, {4, 6}, {5, 6}};
    for (int k = 0; k < 7; k++) antes[regras[k][0]][regras[k][1]] = 1;

    int melhor = 0, maior = -1;
    for (int u = 0; u < V; u++) {
        bool visto[V] = {false};
        visto[u] = true;
        int n = alcance(u, visto);
        printf("%s trava %d\n", disc[u], n);
        if (n > maior) {
            maior = n;
            melhor = u;
        }
    }
    printf("Não reprove em %s\n", disc[melhor]);
    return 0;
}
