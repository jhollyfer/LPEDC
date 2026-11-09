// 0182 · Caminhos e ciclos
// Exercício E1090 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define V 5
#define MAX_RUAS 10

const char *pontos[V] = {"Depósito", "Mercado", "Praça", "Hospital", "Escola"};
int mao[V][V]; // mao[a][b] = 1: rua de mão única de a para b

bool balanceado(void) {
    bool ok = true;
    for (int u = 0; u < V; u++) {
        int entra = 0, sai = 0;
        for (int v = 0; v < V; v++) sai += mao[u][v], entra += mao[v][u];
        if (entra != sai) {
            printf("%s: entram %d, saem %d\n", pontos[u], entra, sai);
            ok = false;
        }
    }
    return ok;
}

void circuito(int inicio) {
    int pilha[MAX_RUAS + 1], topo = 0, ordem[MAX_RUAS + 1], n = 0;
    pilha[topo++] = inicio;
    while (topo > 0) {
        int u = pilha[topo - 1], v = 0;
        while (v < V && mao[u][v] == 0) v++;
        if (v < V) {
            mao[u][v] = 0; // só este sentido: a rua é de mão única
            pilha[topo++] = v;
        } else {
            ordem[n++] = u;
            topo--;
        }
    }
    printf("Circuito:");
    for (int i = n - 1; i >= 0; i--) printf(" %s", pontos[ordem[i]]);
    printf("\n");
}

int main(void) {
    int ruas[][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 2}};
    for (int k = 0; k < 6; k++) mao[ruas[k][0]][ruas[k][1]] = 1;

    printf("Antes da obra:\n");
    if (balanceado()) circuito(0);

    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++) mao[u][v] = 0;
    for (int k = 0; k < 6; k++) mao[ruas[k][0]][ruas[k][1]] = 1;
    mao[3][4] = 0, mao[4][3] = 1; // a obra inverte a rua Hospital -> Escola
    printf("Depois da obra:\n");
    if (balanceado()) circuito(0);
    else printf("Sem circuito\n");
    return 0;
}
