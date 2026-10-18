// 0151 · Ordenação topológica
// Exercício E906 · ★★★

#include <stdbool.h>
#include <stdio.h>

#define MAX 6

const char *tarefas[MAX] = {"café", "banho", "vestir", "escovar", "sair", "mensagens"};
int n;              // quantas tarefas valem agora
int antes[MAX][MAX];
int grau[MAX];
bool usada[MAX];
int ordem[MAX];
bool mostrar;

// backtracking: em cada posição, tenta toda tarefa livre e depois desfaz
int enumera(int pos) {
    if (pos == n) {
        if (mostrar) {
            for (int i = 0; i < n; i++) printf("%s%s", i > 0 ? ", " : "", tarefas[ordem[i]]);
            printf("\n");
        }
        return 1;
    }
    int total = 0;
    for (int u = 0; u < n; u++) {
        if (usada[u] || grau[u] != 0) continue;
        usada[u] = true; // escolhe u
        ordem[pos] = u;
        for (int v = 0; v < n; v++) grau[v] -= antes[u][v];
        total += enumera(pos + 1);
        for (int v = 0; v < n; v++) grau[v] += antes[u][v]; // desfaz
        usada[u] = false;
    }
    return total;
}

int conta(void) {
    for (int b = 0; b < n; b++) {
        grau[b] = 0;
        for (int a = 0; a < n; a++) grau[b] += antes[a][b];
    }
    return enumera(0);
}

int main(void) {
    int regras[][2] = {{1, 2}, {0, 3}, {2, 4}, {3, 4}};
    for (int k = 0; k < 4; k++) antes[regras[k][0]][regras[k][1]] = 1;

    n = 5;
    mostrar = true;
    printf("Total com 5 tarefas: %d\n", conta());

    n = 6;
    antes[5][4] = 1; // ler as mensagens antes de sair
    mostrar = false;
    printf("Total com 6 tarefas: %d\n", conta());
    return 0;
}
