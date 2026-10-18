// 0112 · Dijkstra: caminho mínimo
// Exercício E668 · ★☆☆
//
// O programa calcula o menor tempo, em minutos, saindo da estação Sé até as
// outras estações do metrô. Os trilhos (mão dupla) são:
//
//   Sé-Luz 3, Sé-República 4, Luz-República 2, República-Paulista 6,
//   Sé-Paulista 11, Paulista-Pinheiros 7, República-Pinheiros 15
//
// Tudo está pronto, menos o RELAXAMENTO, no lugar marcado com "COMPLETE
// AQUI". Hoje o programa compila, mas diz que só a Sé é alcançável. Complete.
//
//   Saída esperada:
//   Sé: 0 min
//   Luz: 3 min
//   República: 4 min
//   Paulista: 10 min
//   Pinheiros: 17 min
//
// Dicas:
// 1. A pergunta é: existe trilho de u para v, v não está fixo, e
//    dist[u] + tempo[u][v] < dist[v]?
// 2. Se sim, dist[v] recebe a soma. (Aqui não precisa do anterior.)
// 3. Resposta esperada: a saída acima. Repare na Paulista: o trilho direto
//    da Sé leva 11, mas Sé -> República -> Paulista leva 10.
//
// Escreva sua resposta abaixo (complete o código):

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INFINITO INT_MAX

int tempo[V][V]; // minutos; 0 = sem trilho direto

int main(void) {
    const char *nomes[V] = {"Sé", "Luz", "República", "Paulista", "Pinheiros"};
    int trilhos[][3] = {{0, 1, 3}, {0, 2, 4}, {1, 2, 2}, {2, 3, 6}, {0, 3, 11}, {3, 4, 7}, {2, 4, 15}};
    for (int k = 0; k < 7; k++) {
        tempo[trilhos[k][0]][trilhos[k][1]] = trilhos[k][2];
        tempo[trilhos[k][1]][trilhos[k][0]] = trilhos[k][2];
    }

    int dist[V];
    bool fixo[V];
    for (int v = 0; v < V; v++) {
        dist[v] = INFINITO;
        fixo[v] = false;
    }
    dist[0] = 0;

    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!fixo[v] && dist[v] != INFINITO && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break;
        fixo[u] = true;
        for (int v = 0; v < V; v++) {
            // COMPLETE AQUI
        }
    }

    for (int v = 0; v < V; v++) {
        if (dist[v] == INFINITO) printf("%s: inalcançável\n", nomes[v]);
        else printf("%s: %d min\n", nomes[v], dist[v]);
    }
    return 0;
}
