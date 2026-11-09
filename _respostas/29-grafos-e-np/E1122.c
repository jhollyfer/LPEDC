// 0187 · Reduções
// Exercício E1122 · ★★★

#include <stdbool.h>
#include <stdio.h>

#define V 4
#define K 3
#define NVAR (V * K)
#define MAXC 64

const char *cores[K] = {"vermelho", "verde", "azul"};
int clausula[MAXC][3], nc; // literais +/-(1..NVAR); 0 sobra

int var(int v, int c) { // "o vértice v tem a cor c"
    return v * K + c + 1;
}

void adiciona(int a, int b, int c) {
    clausula[nc][0] = a, clausula[nc][1] = b, clausula[nc][2] = c;
    nc++;
}

// a redução: grafo -> fórmula, O(V + E) cláusulas
void monta(int arestas[][2], int e) {
    nc = 0;
    for (int v = 0; v < V; v++) {
        adiciona(var(v, 0), var(v, 1), var(v, 2)); // pelo menos uma cor
        for (int a = 0; a < K; a++)
            for (int b = a + 1; b < K; b++) adiciona(-var(v, a), -var(v, b), 0); // no máximo uma
    }
    for (int k = 0; k < e; k++)
        for (int c = 0; c < K; c++) adiciona(-var(arestas[k][0], c), -var(arestas[k][1], c), 0); // vizinhos diferentes
}

bool satisfaz(const bool x[]) {
    for (int i = 0; i < nc; i++) {
        bool algum = false;
        for (int j = 0; j < 3 && clausula[i][j] != 0; j++) {
            int l = clausula[i][j];
            if (l > 0 ? x[l] : !x[-l]) algum = true;
        }
        if (!algum) return false;
    }
    return true;
}

void resolve(const char *nome, int arestas[][2], int e) {
    monta(arestas, e);
    printf("%s: %d variáveis, %d cláusulas\n", nome, NVAR, nc);
    for (int m = 0; m < (1 << NVAR); m++) {
        bool x[NVAR + 1] = {false};
        for (int i = 1; i <= NVAR; i++) x[i] = (m >> (i - 1)) & 1;
        if (!satisfaz(x)) continue;
        for (int v = 0; v < V; v++)
            for (int c = 0; c < K; c++)
                if (x[var(v, c)]) printf("  vértice %d: %s\n", v, cores[c]);
        return;
    }
    printf("  sem 3-coloração\n");
}

int main(void) {
    int losango[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}};
    int completo[][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
    resolve("Losango", losango, 5);
    resolve("Completo K4", completo, 6);
    return 0;
}
