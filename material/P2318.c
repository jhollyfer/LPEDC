// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2318 · ★★☆ · Dijkstra e Bellman-Ford na mesma balança
//
// Seis cidades do Pará (siglas BEL, CAS, BRA, CAP, SAL, ABA) estão ligadas
// por estradas de mão única, todas com km positivos. O programa tem o
// Dijkstra em O(V²) e conta quantas arestas ele olha. Estenda: escreva
// bellman_ford(origem, dist), que varre a matriz inteira em cada rodada
// (u de 0 a V - 1, v de 0 a V - 1), para cedo quando nada muda e soma em
// olhadas_bf cada aresta que olha. Rode os dois a partir de CADA cidade,
// mostre a tabela do Dijkstra, confira se as duas tabelas são iguais e
// mostre as contagens.
//
//   Saída esperada:
//        BEL  CAS  BRA  CAP  SAL  ABA
//   BEL    0   70  190  160  220   60
//   CAS  370    0  120   90  150  430
//   BRA  270  340    0  430   50  330
//   CAP  280  350   30    0   60  340
//   SAL  220  290  410  380    0  280
//   ABA  420   50  170  140  200    0
//   As duas tabelas conferem
//   Arestas olhadas: Dijkstra 60, Bellman-Ford 170
//
// Dicas:
// 1. Uma rodada olha as 10 arestas. A parada antecipada conta a rodada que
//    não mudou nada também: ela é a prova de que acabou.
// 2. Sem peso negativo, os dois PRECISAM dar a mesma tabela. A diferença
//    está no trabalho: o Dijkstra olha cada aresta uma vez por origem.
// 3. Resposta esperada: as tabelas conferem; Dijkstra 60 arestas olhadas
//    (6 origens × 10), Bellman-Ford 170.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 6
#define INF INT_MAX

const char *siglas[V] = {"BEL", "CAS", "BRA", "CAP", "SAL", "ABA"}; // Belém, Castanhal, Bragança, Capanema, Salinas, Abaetetuba
int km[V][V]; // mão única; 0 = não tem estrada
int olhadas_dij = 0, olhadas_bf = 0;

void dijkstra(int origem, int dist[]) {
    bool feito[V] = {false};
    for (int v = 0; v < V; v++) dist[v] = INF;
    dist[origem] = 0;
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!feito[v] && dist[v] != INF && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break;
        feito[u] = true;
        for (int v = 0; v < V; v++) {
            if (!km[u][v]) continue;
            olhadas_dij++;
            if (dist[u] + km[u][v] < dist[v]) dist[v] = dist[u] + km[u][v];
        }
    }
}

int main(void) {
    int estradas[][3] = {{0, 1, 70}, {1, 3, 90}, {3, 2, 30}, {3, 4, 60}, {0, 5, 60},
                         {5, 1, 50}, {2, 4, 50}, {4, 0, 220}, {1, 2, 140}, {5, 3, 150}};
    for (int k = 0; k < 10; k++) km[estradas[k][0]][estradas[k][1]] = estradas[k][2];

    int a[V];
    dijkstra(0, a);
    printf("De BEL até SAL: %d km\n", a[4]);
    return 0;
}
