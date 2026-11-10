// 0111 · DFS: busca em profundidade
// Exercício E661 · ★☆☆
//
// O mapa de um shopping liga seis áreas por corredores (grafo não dirigido).
// O programa abaixo faz uma DFS a partir do Hall e imprime cada área com um
// recuo de 2 espaços por nível de profundidade. Estenda o programa: na
// frente de cada nome, mostre o número da visita (1 para a primeira área
// visitada, 2 para a segunda...) e, no fim, mostre qual área ficou mais
// funda na árvore da DFS e em que nível.
//
//   Saída esperada:
//   1 Hall
//     2 Praça
//       3 Cinema
//       4 Loja
//         5 Banco
//           6 Saída
//   Mais fundo: Saída (nível 4)
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *nomes[V] = {"Hall", "Cinema", "Praça", "Loja", "Banco", "Saída"};
int adj[V][V] = {
    {0, 0, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 0},
    {1, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0},
    {1, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0},
};
bool visitado[V];

void dfs(int u, int nivel) {
    visitado[u] = true;
    printf("%*s%s\n", 2 * nivel, "", nomes[u]);
    for (int v = 0; v < V; v++)
        if (adj[u][v] && !visitado[v]) dfs(v, nivel + 1);
}

int main(void) {
    dfs(0, 0);
    return 0;
}
