// A374 · Caminho hamiltoniano usando quem só sabe achar ciclo

#include <stdbool.h>
#include <stdio.h>

#define MAXV 8

int n;
int adj[MAXV][MAXV];
int rota[MAXV];
bool usado[MAXV];

// a caixa-preta: acha ciclo hamiltoniano (backtracking do 0183)
bool ciclo(int pos) {
    if (pos == n) return adj[rota[n - 1]][rota[0]];
    for (int v = 1; v < n; v++) {
        if (!adj[rota[pos - 1]][v] || usado[v]) continue;
        rota[pos] = v;
        usado[v] = true;
        if (ciclo(pos + 1)) return true;
        usado[v] = false;
    }
    return false;
}

bool tem_ciclo(void) {
    for (int v = 0; v < n; v++) usado[v] = false;
    rota[0] = 0;
    usado[0] = true;
    return ciclo(1);
}

int main(void) {
    const char *pontos[MAXV] = {"Mirante", "Cachoeira", "Gruta", "Lagoa", "Pedra", "X"};
    n = 5; // a gravata do A365
    int trechos[][2] = {{0, 1}, {1, 2}, {2, 0}, {0, 3}, {3, 4}, {4, 0}};
    for (int k = 0; k < 6; k++) adj[trechos[k][0]][trechos[k][1]] = adj[trechos[k][1]][trechos[k][0]] = 1;
    printf("Ciclo hamiltoniano na gravata: %s\n", tem_ciclo() ? "sim" : "não");

    // a redução: um vértice novo X ligado a todos
    int x = n++;
    for (int v = 0; v < x; v++) adj[x][v] = adj[v][x] = 1;
    if (!tem_ciclo()) {
        printf("Sem caminho hamiltoniano\n");
        return 0;
    }
    int ix = 0; // onde o X caiu no ciclo
    while (rota[ix] != x) ix++;
    printf("Ciclo com o X:");
    for (int i = 0; i < n; i++) printf(" %s", pontos[rota[i]]);
    printf("\nCaminho (corta o X):");
    for (int i = 1; i < n; i++) printf(" %s", pontos[rota[(ix + i) % n]]);
    printf("\n");
    return 0;
}
// Saída:
// Ciclo hamiltoniano na gravata: não
// Ciclo com o X: Mirante Cachoeira Gruta X Lagoa Pedra
// Caminho (corta o X): Lagoa Pedra Mirante Cachoeira Gruta
//
// O grafo novo tem ciclo hamiltoniano exatamente quando o original tem
// caminho hamiltoniano: o X entra pela ponta final do caminho e sai pela
// inicial, porque está ligado a todos. A redução custa O(V): um vértice e
// V arestas. Ela mostra que CAMINHO <=p CICLO; como caminho hamiltoniano é
// NP-completo, ciclo hamiltoniano também é NP-difícil.
