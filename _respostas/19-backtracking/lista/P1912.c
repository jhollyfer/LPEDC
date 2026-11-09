// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1912 · ★★☆ · Quantos horários de prova?

#include <stdio.h>

#define N 6

const char *disc[N] = {"Cálculo", "Física", "Álgebra", "Química", "Programação", "Inglês"};
int viz[N][N];
int cor[N];

void liga(int a, int b) {
    viz[a][b] = viz[b][a] = 1;
}

int colore(int v, int k) {
    if (v == N) {
        return 1;
    }
    for (int c = 0; c < k; c++) {
        int ok = 1;
        for (int u = 0; u < v; u++) {
            if (viz[v][u] && cor[u] == c) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cor[v] = c;
            if (colore(v + 1, k)) {
                return 1;
            }
        }
    }
    return 0;
}

int main(void) {
    liga(0, 1);
    liga(0, 2);
    liga(0, 4);
    liga(1, 3);
    liga(1, 4);
    liga(2, 4);
    liga(3, 5);
    liga(4, 5);
    int k = 1;
    while (!colore(0, k)) {
        printf("%d horário(s): não dá\n", k);
        k++;
    }
    printf("%d horários: dá\n", k);
    for (int h = 0; h < k; h++) {
        printf("Horário %d:", h + 1);
        for (int v = 0; v < N; v++) {
            if (cor[v] == h) {
                printf(" %s", disc[v]);
            }
        }
        printf("\n");
    }
    return 0;
}
