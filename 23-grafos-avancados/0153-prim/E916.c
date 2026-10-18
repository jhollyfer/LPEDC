// 0153 · Prim: a árvore que cresce
// Exercício E916 · ★★☆
//
// A operadora de internet vai levar fibra da Central a sete pontos do
// bairro. O programa abaixo já roda o Prim e preenche pai[]. Estenda-o:
// escreva a função recursiva mostra(v, nivel), que imprime a árvore como
// um organograma: cada ponto com 2 espaços de recuo por nível e, entre
// parênteses, os km da fibra que o liga ao pai. Os filhos de um ponto
// aparecem em ordem de índice, logo abaixo dele.
//
//   Saída esperada:
//   Central
//     Padaria (2)
//       Escola (3)
//         Farmácia (2)
//           Clínica (3)
//             Posto (2)
//       Igreja (5)
//         Praça (1)
//   Total: 18 km
//
// Dicas:
// 1. Os filhos de v são os w com pai[w] == v. mostra(v, nivel) imprime v
//    e chama mostra(w, nivel + 1) para cada filho: é a pré-ordem do
//    assunto 0098, numa árvore com qualquer número de filhos.
// 2. printf("%*s", 2 * nivel, "") imprime 2 * nivel espaços. Os km do pai
//    até v estão em fibra[pai[v]][v].
// 3. Resposta esperada: a saída acima. O Posto entra pela Clínica (2 km),
//    não pela Escola (7) nem pela Central (9).
//
// Escreva sua resposta abaixo (escreva mostra e chame-a no main):

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 8
#define INFINITO INT_MAX

const char *pontos[V] = {"Central", "Padaria", "Escola", "Igreja", "Farmácia", "Praça", "Posto", "Clínica"};
int fibra[V][V];
int pai[V];

int main(void) {
    int trechos[][3] = {{0, 1, 2}, {0, 2, 4}, {1, 2, 3}, {1, 3, 5}, {2, 4, 2}, {3, 5, 1},
                        {4, 5, 6}, {2, 6, 7}, {4, 7, 3}, {6, 7, 2}, {0, 6, 9}};
    for (int k = 0; k < 11; k++) {
        fibra[trechos[k][0]][trechos[k][1]] = trechos[k][2];
        fibra[trechos[k][1]][trechos[k][0]] = trechos[k][2];
    }

    int chave[V], total = 0;
    bool na_rede[V] = {false};
    for (int v = 0; v < V; v++) {
        chave[v] = INFINITO;
        pai[v] = -1;
    }
    chave[0] = 0;
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!na_rede[v] && chave[v] != INFINITO && (u == -1 || chave[v] < chave[u])) u = v;
        if (u == -1) break;
        na_rede[u] = true;
        total += chave[u];
        for (int v = 0; v < V; v++)
            if (fibra[u][v] && !na_rede[v] && fibra[u][v] < chave[v]) {
                chave[v] = fibra[u][v];
                pai[v] = u;
            }
    }
    printf("Total: %d km\n", total);
    return 0;
}
