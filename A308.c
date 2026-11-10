// A308 · A ordem da lista muda o número de rodadas

#include <stdbool.h>
#include <stdio.h>

#define V 6
#define E 7
#define INFINITO 1000000000

typedef struct {
    int de, para, custo;
} Aresta;

// roda o Bellman-Ford e conta rodadas e relaxamentos (vezes que uma dist caiu)
void bellman_ford(const Aresta a[], const char *nome) {
    int dist[V];
    for (int v = 0; v < V; v++) dist[v] = INFINITO;
    dist[0] = 0;
    int rodadas = 0, relaxou = 0;
    bool mudou = true;
    while (mudou && rodadas < V - 1) {
        mudou = false;
        rodadas++;
        for (int k = 0; k < E; k++)
            if (dist[a[k].de] != INFINITO && dist[a[k].de] + a[k].custo < dist[a[k].para]) {
                dist[a[k].para] = dist[a[k].de] + a[k].custo;
                relaxou++;
                mudou = true;
            }
    }
    printf("%s: %d rodadas, %d relaxamentos, dist final:", nome, rodadas, relaxou);
    for (int v = 0; v < V; v++) printf(" %d", dist[v]);
    printf("\n");
}

int main(void) {
    // paradas 0 a 5 de uma linha de ônibus; o -2 é o desconto da integração
    Aresta na_ordem[E] = {{0, 1, 4}, {0, 2, 9}, {1, 2, 3}, {2, 3, -2},
                          {3, 4, 5}, {1, 4, 12}, {4, 5, 1}};
    Aresta invertida[E];
    for (int k = 0; k < E; k++) invertida[k] = na_ordem[E - 1 - k];

    bellman_ford(na_ordem, "na ordem do caminho");
    bellman_ford(invertida, "ordem invertida    ");
    return 0;
}
// Saída:
// na ordem do caminho: 2 rodadas, 6 relaxamentos, dist final: 0 4 7 5 10 11
// ordem invertida    : 5 rodadas, 11 relaxamentos, dist final: 0 4 7 5 10 11
//
// A resposta é a mesma; o trabalho, não. Na ordem do caminho, cada aresta
// já encontra a dist de origem pronta, e a 2ª rodada só confirma. Invertida,
// cada rodada avança uma aresta do caminho, e a parada 5 só fica certa na
// 5ª rodada, a última permitida. O limite de V - 1 rodadas é o pior caso, e
// ele acontece.
