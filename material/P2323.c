// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2323 · ★★★ · Kosaraju de mão trocada
//
// Ache o bug. Uma rede social quer achar as "bolhas": grupos em que todo
// mundo alcança todo mundo seguindo a relação "segue". Este Kosaraju
// compila e roda, mas junta a rede inteira numa bolha só, e @dani nem
// chega de volta em @ana:
//
//   Saída que aparece:
//   Bolha 1: @ana @beto @caio @dani @enzo @fe @gabi
//
// O erro está numa linha só. Conserte.
//
//   Saída esperada:
//   Bolha 1: @ana @beto @caio
//   Bolha 2: @dani @enzo
//   Bolha 3: @fe @gabi
//
// Dicas:
// 1. A 1ª DFS está certa: o último a terminar (@ana) fica num grupo de
//    onde se SAI para os outros. Uma DFS normal a partir dele alcança tudo.
// 2. A 2ª passada tem que andar no grafo INVERTIDO: de @ana, para trás, só
//    se alcança quem também chega em @ana.
// 3. Resposta esperada: em dfs2, troque segue[u][v] por inversa[u][v];
//    saem 3 bolhas: @ana @beto @caio, @dani @enzo e @fe @gabi.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *perfis[V] = {"@ana", "@beto", "@caio", "@dani", "@enzo", "@fe", "@gabi"};
int segue[V][V];   // segue[a][b] = 1: a segue b
int inversa[V][V];
bool visto[V];
int ordem[V], n_ordem = 0;
int grupo[V];

void dfs1(int u) {
    visto[u] = true;
    for (int v = 0; v < V; v++)
        if (segue[u][v] && !visto[v]) dfs1(v);
    ordem[n_ordem++] = u;
}

void dfs2(int u, int g) {
    grupo[u] = g;
    for (int v = 0; v < V; v++)
        if (segue[u][v] && grupo[v] == 0) dfs2(v, g);
}

int main(void) {
    int pares[][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 3}, {4, 5}, {5, 6}, {6, 5}, {1, 6}};
    for (int k = 0; k < 10; k++) {
        segue[pares[k][0]][pares[k][1]] = 1;
        inversa[pares[k][1]][pares[k][0]] = 1;
    }
    for (int u = 0; u < V; u++)
        if (!visto[u]) dfs1(u);

    int g = 0;
    for (int i = V - 1; i >= 0; i--)
        if (grupo[ordem[i]] == 0) dfs2(ordem[i], ++g);

    for (int k = 1; k <= g; k++) {
        printf("Bolha %d:", k);
        for (int u = 0; u < V; u++)
            if (grupo[u] == k) printf(" %s", perfis[u]);
        printf("\n");
    }
    return 0;
}
