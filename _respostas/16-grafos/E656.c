// 0110 · BFS: busca em largura
// Exercício E656 · ★☆☆

#include <stdio.h>

#define V 6

int main(void) {
    const char *nomes[V] = {"Vó", "Tia", "Pai", "Mãe", "Primo", "Eu"};
    int adj[V][V] = {0};
    int contatos[][2] = {{0, 1}, {0, 2}, {1, 4}, {2, 3}, {3, 5}, {4, 5}};
    for (int k = 0; k < 6; k++) {
        adj[contatos[k][0]][contatos[k][1]] = 1;
        adj[contatos[k][1]][contatos[k][0]] = 1;
    }

    int rodada[V], fila[V], inicio = 0, fim = 0, maior = 0;
    for (int v = 0; v < V; v++) rodada[v] = -1;
    rodada[0] = 0;
    fila[fim++] = 0;

    while (inicio < fim) {
        int u = fila[inicio++];
        printf("%s: rodada %d\n", nomes[u], rodada[u]);
        if (rodada[u] > maior) maior = rodada[u];
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && rodada[v] == -1) {
                rodada[v] = rodada[u] + 1;
                fila[fim++] = v;
            }
        }
    }
    printf("Rodadas até todos ouvirem: %d\n", maior);
    return 0;
}
