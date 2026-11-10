// Lista · Módulo 16 · Grafos
// Exercício P1609 · ★☆☆ · DFS com relógio: os tempos d e f
//
// No parque, as trilhas são de sentido único (grafo DIRIGIDO):
//
//   Portao -> Lago, Portao -> Viveiro, Lago -> Mirante, Mirante -> Portao,
//   Viveiro -> Mirante, Viveiro -> Cascata, Quiosque -> Cascata,
//   Quiosque -> Viveiro
//
// Complete a DFS no estilo do Cormen. Um relógio global começa em 0 e avança
// a cada descoberta e a cada término: d[u] é o tempo em que u fica CINZA e
// f[u] o tempo em que fica PRETO. O laço do main tenta os vértices em ordem de
// índice e começa uma árvore nova em cada vértice ainda branco. Mostre também
// a ordem em que os vértices terminam.
//
//   Saída esperada:
//   Portao     1/10
//   Lago       2/ 5
//   Mirante    3/ 4
//   Viveiro    6/ 9
//   Cascata    7/ 8
//   Quiosque  11/12
//   Terminam: Mirante Lago Cascata Viveiro Portao Quiosque
//
// Dicas:
// 1. dfs_visita(u): d[u] = ++relogio; cor[u] = CINZA; para cada v com
//    adj[u][v] e cor[v] == BRANCO, dfs_visita(v); depois cor[u] = PRETO e
//    f[u] = ++relogio.
// 2. Com V vértices, o relógio termina em 2V: cada vértice gasta um tique ao
//    ser descoberto e outro ao terminar.
// 3. O Quiosque não é alcançado a partir do Portão: ele abre uma segunda
//    árvore e recebe d = 11.
// 4. Resposta esperada: Portao 1/10, Lago 2/5, Mirante 3/4, Viveiro 6/9,
//    Cascata 7/8, Quiosque 11/12.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 6

enum { BRANCO, CINZA, PRETO };

const char *nomes[V] = {"Portao", "Lago", "Mirante", "Viveiro", "Cascata", "Quiosque"};
int adj[V][V];
int cor[V], d[V], f[V];
int relogio = 0;

void dfs_visita(int u) {
    (void)u; // apague e escreva a função
}

int main(void) {
    int trilhas[][2] = {{0, 1}, {0, 3}, {1, 2}, {2, 0}, {3, 2}, {3, 4}, {5, 4}, {5, 3}};
    for (int k = 0; k < 8; k++) adj[trilhas[k][0]][trilhas[k][1]] = 1;

    for (int u = 0; u < V; u++) cor[u] = BRANCO;
    for (int u = 0; u < V; u++)
        if (cor[u] == BRANCO) dfs_visita(u);

    for (int u = 0; u < V; u++) printf("%-9s %2d/%2d\n", nomes[u], d[u], f[u]);
    return 0;
}
