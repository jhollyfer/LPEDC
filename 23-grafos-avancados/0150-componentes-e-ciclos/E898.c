// 0150 · Componentes e ciclos
// Exercício E898 · ★★☆
//
// O programa abaixo já separa os pontos de três parques (cada parque é um
// componente do grafo de trilhas) e lista os pontos de cada um. Estenda o
// programa: para cada parque, mostre quantos pontos e quantas trilhas ele
// tem e se existe um circuito (dá para sair de um ponto e voltar a ele sem
// repetir trilha), sem escrever outra DFS.
//
//   Saída esperada:
//   Parque 1: Portaria Mirante Cachoeira | 3 pontos, 3 trilhas, tem circuito
//   Parque 2: Lago Bosque Pico Gruta | 4 pontos, 3 trilhas, sem circuito
//   Parque 3: Rio Ponte Ninho Toca | 4 pontos, 4 trilhas, tem circuito
//
// Dicas:
// 1. Um grafo conexo com k vértices e sem ciclo é uma árvore e tem
//    exatamente k - 1 arestas. Com mais arestas que isso, tem ciclo.
// 2. Para contar as trilhas de um parque, some os graus dos pontos dele
//    (a linha de cada um na matriz) e divida por 2: cada trilha aparece
//    nas duas pontas.
// 3. Resposta esperada: a saída acima. O parque 2 tem 4 pontos e 3
//    trilhas (4 - 1): é uma árvore, sem circuito.
//
// Escreva sua resposta abaixo (estenda o programa):

#include <stdio.h>

#define V 11

const char *pontos[V] = {"Portaria", "Mirante", "Cachoeira", "Lago", "Bosque", "Pico",
                         "Gruta", "Rio", "Ponte", "Ninho", "Toca"};
int trilha[V][V];
int grupo[V];

void marca(int u, int g) {
    grupo[u] = g;
    for (int v = 0; v < V; v++)
        if (trilha[u][v] && grupo[v] == 0) marca(v, g);
}

int main(void) {
    int trilhas[][2] = {{0, 1}, {1, 2}, {2, 0},          // parque 1
                        {3, 4}, {4, 5}, {4, 6},          // parque 2
                        {7, 8}, {8, 9}, {9, 7}, {7, 10}}; // parque 3
    int n_trilhas = 10;
    for (int k = 0; k < n_trilhas; k++) {
        trilha[trilhas[k][0]][trilhas[k][1]] = 1;
        trilha[trilhas[k][1]][trilhas[k][0]] = 1;
    }

    int grupos = 0;
    for (int u = 0; u < V; u++)
        if (grupo[u] == 0) marca(u, ++grupos);

    for (int g = 1; g <= grupos; g++) {
        printf("Parque %d:", g);
        for (int v = 0; v < V; v++)
            if (grupo[v] == g) printf(" %s", pontos[v]);
        printf("\n");
    }
    return 0;
}
