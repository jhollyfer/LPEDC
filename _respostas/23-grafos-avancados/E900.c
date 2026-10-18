// 0150 · Componentes e ciclos
// Exercício E900 · ★★★

#include <stdbool.h>
#include <stdio.h>

#define V 8

const char *nomes[V] = {"Ana", "Bia", "Caio", "Duda", "Enzo", "Flor", "Gui", "Hana"};
int conflito[V][V];
int turno[V]; // -1 = sem turno; 0 = A; 1 = B

// pinta u com t e os vizinhos com o turno oposto; false se der conflito
bool pinta(int u, int t) {
    turno[u] = t;
    for (int v = 0; v < V; v++) {
        if (!conflito[u][v]) continue;
        if (turno[v] == -1) {
            if (!pinta(v, 1 - t)) return false;
        } else if (turno[v] == t) {
            printf("Impossível: %s e %s cairiam no mesmo turno\n", nomes[u], nomes[v]);
            return false;
        }
    }
    return true;
}

void divide(void) {
    for (int u = 0; u < V; u++) turno[u] = -1;
    for (int u = 0; u < V; u++)
        if (turno[u] == -1 && !pinta(u, 0)) return; // cada componente começa no turno A
    for (int t = 0; t < 2; t++) {
        printf("Turno %c:", 'A' + t);
        for (int v = 0; v < V; v++)
            if (turno[v] == t) printf(" %s", nomes[v]);
        printf("\n");
    }
}

void liga(int a, int b) {
    conflito[a][b] = 1;
    conflito[b][a] = 1;
}

int main(void) {
    int pares[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {4, 5}, {6, 7}, {5, 6}};
    for (int k = 0; k < 7; k++) liga(pares[k][0], pares[k][1]);
    divide();

    liga(0, 2); // Ana e Caio brigaram também
    divide();
    return 0;
}
