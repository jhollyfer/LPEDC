// Lista · Módulo 16 · Grafos
// Exercício P1607 · ★☆☆ · BFS a partir da rodoviária: d e π
//
// Você chegou à rodoviária de Manaus, no bairro Flores, e quer saber quantas
// baldeações de ônibus separam Flores de cada bairro. As linhas diretas (mão
// dupla) estão na matriz do esqueleto.
//
// Complete void bfs(int s, int d[], int pi[]) no estilo do Cormen: d[v] é a
// distância (em arestas) de s até v, ou -1 se v não foi alcançado, e pi[v] é o
// predecessor de v na árvore da BFS, ou -1 (NIL). Examine os vizinhos em ordem
// de índice. O main já mostra a tabela. Acrescente na bfs um printf com a
// ordem em que os bairros SAEM da fila.
//
//   Saída esperada:
//   Saem da fila: Flores Parque Dez Aleixo Centro Cachoeirinha Coroado Educandos Japiim
//   bairro        d  pi
//   Flores        0  NIL
//   Parque Dez    1  Flores
//   Aleixo        1  Flores
//   Centro        2  Parque Dez
//   Educandos     3  Centro
//   Cachoeirinha  2  Parque Dez
//   Japiim        3  Cachoeirinha
//   Coroado       2  Aleixo
//
// Dicas:
// 1. Comece com d[v] = -1 e pi[v] = -1 para todo v; depois d[s] = 0 e s
//    entra na fila.
// 2. Ao tirar u da fila, para cada v com adj[u][v] e d[v] == -1: d[v] =
//    d[u] + 1, pi[v] = u, v entra na fila. Marcar na ENTRADA da fila evita que
//    um bairro entre duas vezes.
// 3. Cada vértice entra uma vez na fila: um vetor de V posições basta.
// 4. Resposta esperada: a saída acima. Os mais longe são Educandos e Japiim
//    (d = 3), e Educandos tem π = Centro.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 8

const char *nomes[V] = {"Flores", "Parque Dez", "Aleixo", "Centro",
                        "Educandos", "Cachoeirinha", "Japiim", "Coroado"};
int adj[V][V] = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 0, 0, 1, 0},
};

void bfs(int s, int d[], int pi[]) {
    (void)s; // apague e escreva a BFS
    for (int v = 0; v < V; v++) d[v] = pi[v] = -1;
}

int main(void) {
    int d[V], pi[V];
    bfs(0, d, pi);
    printf("%-13s d  pi\n", "bairro");
    for (int v = 0; v < V; v++)
        printf("%-13s %d  %s\n", nomes[v], d[v], pi[v] == -1 ? "NIL" : nomes[pi[v]]);
    return 0;
}
