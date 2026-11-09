// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2303 · ★☆☆ · Referência circular na planilha

#include <stdbool.h>
#include <stdio.h>

#define V 7
enum { BRANCO, CINZA, PRETO };

const char *celulas[V] = {"A1", "A2", "B1", "B2", "C1", "C2", "D1"};
int usa[V][V]; // usa[a][b] = 1: a fórmula de a usa o valor de b
int cor[V];
int pai[V];
int ini, fim; // a seta fim -> ini chegou num cinza

bool visita(int u) {
    cor[u] = CINZA;
    for (int v = 0; v < V; v++) {
        if (!usa[u][v]) continue;
        if (cor[v] == CINZA) { // voltou para a pilha: ciclo
            ini = v;
            fim = u;
            return true;
        }
        if (cor[v] == BRANCO) {
            pai[v] = u;
            if (visita(v)) return true;
        }
    }
    cor[u] = PRETO;
    return false;
}

void confere(const char *rotulo) {
    for (int u = 0; u < V; u++) cor[u] = BRANCO;
    for (int u = 0; u < V; u++) {
        if (cor[u] == BRANCO && visita(u)) {
            int caminho[V], n = 0;
            for (int x = fim; x != ini; x = pai[x]) caminho[n++] = x;
            caminho[n++] = ini;
            printf("%s: referência circular", rotulo);
            for (int k = n - 1; k >= 0; k--) printf(" %s ->", celulas[caminho[k]]);
            printf(" %s\n", celulas[ini]);
            return;
        }
    }
    printf("%s: sem referência circular\n", rotulo);
}

int main(void) {
    int refs[][2] = {{0, 2}, {2, 4}, {4, 3}, {3, 6}, {6, 2}, {1, 5}};
    for (int k = 0; k < 6; k++) usa[refs[k][0]][refs[k][1]] = 1;
    confere("Planilha de maio");

    usa[6][2] = 0; // D1 deixou de usar B1
    confere("Planilha de junho");
    return 0;
}
