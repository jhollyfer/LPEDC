// Lista · Módulo 16 · Grafos
// Exercício P1612 · ★★☆ · Os links do site: os quatro tipos de aresta

#include <stdio.h>

#define V 7

enum { BRANCO, CINZA, PRETO };
enum { ARVORE, RETORNO, AVANCO, CRUZAMENTO };

const char *nomes[V] = {"Home", "Blog", "Loja", "Contato", "Post", "Carrinho", "Ajuda"};
const char *tipos[] = {"árvore", "retorno", "avanço", "cruzamento"};
int adj[V][V];
int cor[V], d[V], relogio = 0;
int conta[4];

void dfs(int u) {
    cor[u] = CINZA;
    d[u] = ++relogio;
    for (int v = 0; v < V; v++) {
        if (!adj[u][v]) continue;
        int t;
        if (cor[v] == BRANCO) t = ARVORE;
        else if (cor[v] == CINZA) t = RETORNO;
        else t = d[u] < d[v] ? AVANCO : CRUZAMENTO; // preto: quem foi descoberto antes?
        printf("%-8s -> %-8s %s\n", nomes[u], nomes[v], tipos[t]);
        conta[t]++;
        if (t == ARVORE) dfs(v);
    }
    cor[u] = PRETO;
    ++relogio; // o término também avança o relógio
}

int main(void) {
    int links[][2] = {{0, 1}, {0, 2}, {0, 4}, {1, 4}, {4, 0}, {4, 3},
                      {2, 3}, {2, 5}, {5, 2}, {6, 3}, {6, 0}};
    for (int k = 0; k < 11; k++) adj[links[k][0]][links[k][1]] = 1;

    for (int u = 0; u < V; u++)
        if (cor[u] == BRANCO) dfs(u);
    printf("árvore %d, retorno %d, avanço %d, cruzamento %d\n",
           conta[ARVORE], conta[RETORNO], conta[AVANCO], conta[CRUZAMENTO]);
    return 0;
}
