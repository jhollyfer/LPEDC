// 0111 · DFS: busca em profundidade
// Exercício E661 · ★☆☆
//
// O mapa de um shopping liga seis áreas por corredores (grafo não dirigido).
// O programa abaixo faz uma DFS a partir do Hall e imprime cada área com um
// recuo de 2 espaços por nível de profundidade.
//
// a) Sem rodar, preveja a saída, com os recuos.
// b) Faça à mão a ordem da BFS a partir do Hall (vizinhos em ordem de
//    índice) e compare.
//
// Dicas:
// 1. Desenhe o grafo. Hall (0) liga em Praça (2) e Banco (4); a DFS desce
//    pela Praça primeiro, porque 2 < 4.
// 2. O Banco é vizinho direto do Hall, mas a DFS chega nele por outro
//    caminho, bem mais fundo.
// 3. Resposta esperada:
//    a) Hall / Praça (2 espaços) / Cinema (4) / Loja (4) / Banco (6) /
//       Saída (8), uma por linha.
//    b) BFS: Hall, Praça, Banco, Cinema, Loja, Saída.
//
// Escreva sua resposta abaixo (como comentário):

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
