// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2327 · ★★★ · O Prim que virou Dijkstra
//
// Ache o bug. A operadora vai ligar cinco torres com o mínimo de cabo
// (km, mão dupla). O código abaixo parece um Prim, mas a rede sai cara e
// toda pendurada na Central:
//
//   Saída que aparece:
//   Central - Morro: 5 km
//   Central - Vila: 6 km
//   Vila - Usina: 3 km
//   Central - Sítio: 9 km
//   Total: 23 km
//
// Isso é a árvore de caminhos mínimos do Dijkstra, não a árvore geradora
// mínima. O erro está no bloco que atualiza a chave dos vizinhos (duas
// linhas). Conserte.
//
//   Saída esperada:
//   Central - Morro: 5 km
//   Morro - Vila: 2 km
//   Vila - Usina: 3 km
//   Usina - Sítio: 1 km
//   Total: 11 km
//
// Dicas:
// 1. No Dijkstra, a chave de v é a distância da ORIGEM até v. No Prim, é o
//    cabo mais barato que liga v a QUALQUER torre já na rede.
// 2. O Sítio tem o cabo Usina-Sítio de 1 km, mas o programa compara
//    chave[Usina] + 1 = 10 com 9 e fica com a ligação direta.
// 3. Resposta esperada: compare e guarde só km[u][v]; total 11 km.
//
// Escreva sua resposta abaixo (conserte o código):

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INF INT_MAX

const char *torres[V] = {"Central", "Morro", "Vila", "Usina", "Sítio"};
int km[V][V];

int main(void) {
    int cabos[][3] = {{0, 1, 5}, {1, 2, 2}, {0, 2, 6}, {2, 3, 3}, {1, 3, 7}, {3, 4, 1}, {0, 4, 9}};
    for (int k = 0; k < 7; k++) {
        km[cabos[k][0]][cabos[k][1]] = cabos[k][2];
        km[cabos[k][1]][cabos[k][0]] = cabos[k][2];
    }
    int chave[V], pai[V];
    bool dentro[V];
    for (int v = 0; v < V; v++) {
        chave[v] = INF;
        pai[v] = -1;
        dentro[v] = false;
    }
    chave[0] = 0;
    int total = 0;
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!dentro[v] && chave[v] != INF && (u == -1 || chave[v] < chave[u])) u = v;
        dentro[u] = true;
        if (pai[u] != -1) {
            printf("%s - %s: %d km\n", torres[pai[u]], torres[u], km[pai[u]][u]);
            total += km[pai[u]][u];
        }
        for (int v = 0; v < V; v++)
            if (km[u][v] && !dentro[v] && chave[u] + km[u][v] < chave[v]) {
                chave[v] = chave[u] + km[u][v];
                pai[v] = u;
            }
    }
    printf("Total: %d km\n", total);
    return 0;
}
