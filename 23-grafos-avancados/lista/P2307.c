// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2307 · ★☆☆ · As chaves do Prim
//
// Uma usina vai levar energia a quatro comunidades ribeirinhas. O Prim
// abaixo, em O(V²), já monta a rede a partir da Usina e mostra cada linha
// que entra. Instrumente-o: depois de cada vértice entrar e atualizar os
// vizinhos, mostre o vetor chave[] inteiro, com "-" para infinito e um "*"
// colado em quem já está na rede. Use "%3d" para cada número, com um
// espaço antes, e "   -" para infinito.
//
//   Saída esperada:
//   entra Usina
//     chave:   0*   6    3    -    9
//   entra Bom Jesus: Usina - Bom Jesus, 3 km
//     chave:   0*   4    3*   7    8
//   entra Boa Vista: Bom Jesus - Boa Vista, 4 km
//     chave:   0*   4*   3*   2    8
//   entra Santa Luzia: Boa Vista - Santa Luzia, 2 km
//     chave:   0*   4*   3*   2*   5
//   entra São José: Santa Luzia - São José, 5 km
//     chave:   0*   4*   3*   2*   5*
//   Total: 14 km
//
// Dicas:
// 1. Escreva mostra_chaves(chave, na_rede) e chame-a no fim de cada volta
//    do laço "passo".
// 2. Repare na Santa Luzia: a chave dela cai de 7 para 2 quando Boa Vista
//    entra. A chave é o cabo mais barato até a REDE, não até a Usina.
// 3. Resposta esperada: total de 14 km; a última linha de chaves é
//    0* 4* 3* 2* 5*.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INF INT_MAX

const char *lugares[V] = {"Usina", "Boa Vista", "Bom Jesus", "Santa Luzia", "São José"};
int km[V][V];

int main(void) {
    int linhas[][3] = {{0, 1, 6}, {0, 2, 3}, {1, 2, 4}, {1, 3, 2}, {2, 3, 7}, {2, 4, 8}, {3, 4, 5}, {0, 4, 9}};
    for (int k = 0; k < 8; k++) {
        km[linhas[k][0]][linhas[k][1]] = linhas[k][2];
        km[linhas[k][1]][linhas[k][0]] = linhas[k][2];
    }

    int chave[V], pai[V];
    bool na_rede[V];
    for (int v = 0; v < V; v++) {
        chave[v] = INF;
        pai[v] = -1;
        na_rede[v] = false;
    }
    chave[0] = 0;
    int total = 0;
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!na_rede[v] && chave[v] != INF && (u == -1 || chave[v] < chave[u])) u = v;
        na_rede[u] = true;
        if (pai[u] == -1) printf("entra %s\n", lugares[u]);
        else {
            printf("entra %s: %s - %s, %d km\n", lugares[u], lugares[pai[u]], lugares[u], km[pai[u]][u]);
            total += km[pai[u]][u];
        }
        for (int v = 0; v < V; v++)
            if (km[u][v] && !na_rede[v] && km[u][v] < chave[v]) {
                chave[v] = km[u][v];
                pai[v] = u;
            }
    }
    printf("Total: %d km\n", total);
    return 0;
}
