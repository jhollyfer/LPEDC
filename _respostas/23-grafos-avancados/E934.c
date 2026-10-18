// 0156 · Juntando tudo: o assistente do calouro
// Exercício E934 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define V 8

const char *disc[V] = {"Algoritmos", "Cálculo I", "Inglês", "Física",
                       "Cálculo II", "Estruturas", "Redes", "TCC"};
int pre[V][V];

// monta os semestres cursando no máximo "limite" disciplinas em cada um
int planeja(int limite, bool mostrar) {
    int grau[V] = {0};
    bool feita[V] = {false};
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) grau[b] += pre[a][b];

    int feitas = 0, semestre = 0;
    while (feitas < V) {
        int escolhidas[V], n = 0;
        for (int v = 0; v < V && n < limite; v++) // as liberadas de menor índice
            if (!feita[v] && grau[v] == 0) escolhidas[n++] = v;
        if (n == 0) return -1; // ninguém liberado: ciclo
        semestre++;
        if (mostrar) printf("  %dº:", semestre);
        for (int i = 0; i < n; i++) {
            feita[escolhidas[i]] = true;
            if (mostrar) printf(" %s", disc[escolhidas[i]]);
        }
        if (mostrar) printf("\n");
        for (int i = 0; i < n; i++) // só depois do semestre as dependentes ficam livres
            for (int v = 0; v < V; v++) grau[v] -= pre[escolhidas[i]][v];
        feitas += n;
    }
    return semestre;
}

int main(void) {
    int regras[][2] = {{0, 5}, {1, 4}, {1, 3}, {5, 6}, {4, 7}, {6, 7}};
    for (int k = 0; k < 6; k++) pre[regras[k][0]][regras[k][1]] = 1;

    printf("Sem limite: %d semestres\n", planeja(V, false));
    printf("Com no máximo 2 por semestre:\n");
    int s = planeja(2, true);
    printf("  total: %d semestres\n", s);
    return 0;
}
