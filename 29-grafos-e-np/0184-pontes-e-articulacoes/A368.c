// A368 · Conferindo na força bruta: corta e conta

#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *bairros[V] = {"Centro", "Aleixo", "Adrianópolis", "Flores", "Cidade Nova", "Tarumã", "Ponta Negra"};
int fibra[V][V];
bool visto[V];
long passos = 0; // quantas casas da matriz foram olhadas

void dfs(int u, int fora) { // fora = vértice desligado (-1 se nenhum)
    visto[u] = true;
    for (int v = 0; v < V; v++) {
        passos++;
        if (fibra[u][v] && !visto[v] && v != fora) dfs(v, fora);
    }
}

int componentes(int fora) {
    for (int u = 0; u < V; u++) visto[u] = false;
    int c = 0;
    for (int u = 0; u < V; u++)
        if (u != fora && !visto[u]) c++, dfs(u, fora);
    return c;
}

int main(void) {
    int cabos[][2] = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}, {4, 5}, {5, 3}, {5, 6}};
    for (int k = 0; k < 8; k++) fibra[cabos[k][0]][cabos[k][1]] = fibra[cabos[k][1]][cabos[k][0]] = 1;

    int base = componentes(-1);
    printf("Componentes da rede inteira: %d\n", base);
    for (int k = 0; k < 8; k++) { // corta um cabo, conta, religa
        int a = cabos[k][0], b = cabos[k][1];
        fibra[a][b] = fibra[b][a] = 0;
        if (componentes(-1) > base) printf("Ponte: %s - %s\n", bairros[a], bairros[b]);
        fibra[a][b] = fibra[b][a] = 1;
    }
    printf("Articulações:");
    for (int u = 0; u < V; u++) // desliga um bairro, conta os que sobram
        if (componentes(u) > base) printf(" %s", bairros[u]);
    printf("\nCasas da matriz olhadas: %ld\n", passos);
    return 0;
}
// Saída:
// Componentes da rede inteira: 1
// Ponte: Aleixo - Flores
// Ponte: Tarumã - Ponta Negra
// Articulações: Aleixo Flores Tarumã
// Casas da matriz olhadas: 735
//
// O mesmo resultado do texto, com um custo bem diferente: uma DFS completa
// para cada cabo e outra para cada bairro, E + V + 1 = 16 buscas de até V²
// casas cada. O algoritmo do texto faz UMA busca (49 casas). Com mil
// bairros e cinco mil cabos, seriam 6 mil buscas contra uma.
