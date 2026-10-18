// 0110 · BFS: busca em largura
// Exercício E660 · ★★★
//
// Resposta: o vértice só era marcado ao SAIR da fila. Dani é vizinha de Bia e
// de Cadu; quando Bia sai, Dani entra; quando Cadu sai, Dani ainda está na
// fila, sem marca, e entra de novo. A fila precisaria de 5 posições e tem 4:
// fila[4] escreve fora do vetor. Marcando ao ENTRAR, cada vértice entra uma
// vez só e V posições bastam.

#include <stdbool.h>
#include <stdio.h>

#define V 4

int main(void) {
    const char *nomes[V] = {"Ana", "Bia", "Cadu", "Dani"};
    int adj[V][V] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0},
    };
    bool visitado[V] = {false};
    int fila[V], inicio = 0, fim = 0;

    visitado[0] = true; // a origem é marcada antes de entrar
    fila[fim++] = 0;
    while (inicio < fim) {
        int u = fila[inicio++];
        printf("%s ", nomes[u]);
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && !visitado[v]) {
                visitado[v] = true; // marca ao ENTRAR na fila
                fila[fim++] = v;
            }
        }
    }
    printf("\n");
    return 0;
}
