// 0110 · BFS: busca em largura
// Exercício E655 · ★☆☆
//
// O mapa abaixo liga seis bairros por linhas de ônibus diretas (grafo não
// dirigido). O programa já roda uma BFS a partir da Penha e mostra a ordem
// da visita com a distância de cada bairro. Estenda o programa: acrescente
// o vetor pai[] (quem descobriu cada bairro) e, depois da linha da ordem,
// mostre uma linha por bairro, em ordem de índice, dizendo quem o descobriu.
//
//   Saída esperada:
//   Penha(0) Lapa(1) Moema(1) Tatuape(1) Centro(2) Saude(2)
//   Centro: descoberto por Lapa
//   Lapa: descoberto por Penha
//   Moema: descoberto por Penha
//   Penha: origem
//   Saude: descoberto por Moema
//   Tatuape: descoberto por Penha
//
// Dicas:
// 1. int pai[V], todos começando com -1 (a origem continua com -1).
// 2. Anote pai[v] = u no mesmo lugar em que o código anota dist[v].
// 3. Repare na Saude: ela é vizinha de Moema e de Tatuape, mas quem a
//    descobre é quem sai primeiro da fila.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>

#define V 6

int main(void) {
    const char *nomes[V] = {"Centro", "Lapa", "Moema", "Penha", "Saude", "Tatuape"};
    int adj[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0},
    };
    int dist[V], fila[V], inicio = 0, fim = 0;
    for (int v = 0; v < V; v++) dist[v] = -1;

    dist[3] = 0;
    fila[fim++] = 3;
    while (inicio < fim) {
        int u = fila[inicio++];
        printf("%s(%d) ", nomes[u], dist[u]);
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                fila[fim++] = v;
            }
        }
    }
    printf("\n");
    return 0;
}
