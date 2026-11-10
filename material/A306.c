// A306 · Prim e Dijkstra: a mesma função, uma linha diferente

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INFINITO INT_MAX

const char *salas[V] = {"Servidor", "Recepção", "Vendas", "Estoque", "Diretoria"};
int cabo[V][V]; // metros de cabo entre duas salas; 0 = sem passagem

// dijkstra = false: Prim (árvore de menor soma de cabo)
// dijkstra = true:  Dijkstra (cada sala o mais perto possível do servidor)
void arvore(bool dijkstra) {
    int chave[V], pai[V];
    bool pronto[V] = {false};
    for (int v = 0; v < V; v++) {
        chave[v] = INFINITO;
        pai[v] = -1;
    }
    chave[0] = 0;
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!pronto[v] && chave[v] != INFINITO && (u == -1 || chave[v] < chave[u])) u = v;
        if (u == -1) break;
        pronto[u] = true;
        for (int v = 0; v < V; v++) {
            if (!cabo[u][v] || pronto[v]) continue;
            int nova = dijkstra ? chave[u] + cabo[u][v] : cabo[u][v]; // A linha que muda
            if (nova < chave[v]) {
                chave[v] = nova;
                pai[v] = u;
            }
        }
    }
    int soma = 0;
    printf("%s:", dijkstra ? "Dijkstra" : "Prim");
    for (int v = 1; v < V; v++) {
        printf(" %s-%s", salas[pai[v]], salas[v]);
        soma += cabo[pai[v]][v];
    }
    printf("\n  cabo instalado: %d m\n", soma);
    printf("  distância de cada sala ao servidor pela árvore:");
    for (int v = 1; v < V; v++) {
        int d = 0;
        for (int w = v; pai[w] != -1; w = pai[w]) d += cabo[pai[w]][w];
        printf(" %d", d);
    }
    printf("\n");
}

int main(void) {
    int trechos[][3] = {{0, 1, 10}, {0, 2, 14}, {0, 3, 20}, {1, 2, 5},
                        {2, 3, 7}, {3, 4, 6}, {1, 4, 25}, {0, 4, 24}};
    for (int k = 0; k < 8; k++) {
        cabo[trechos[k][0]][trechos[k][1]] = trechos[k][2];
        cabo[trechos[k][1]][trechos[k][0]] = trechos[k][2];
    }
    arvore(false);
    arvore(true);
    return 0;
}
// Saída:
// Prim: Servidor-Recepção Recepção-Vendas Vendas-Estoque Estoque-Diretoria
//   cabo instalado: 28 m
//   distância de cada sala ao servidor pela árvore: 10 15 22 28
// Dijkstra: Servidor-Recepção Servidor-Vendas Servidor-Estoque Servidor-Diretoria
//   cabo instalado: 68 m
//   distância de cada sala ao servidor pela árvore: 10 14 20 24
//
// O Prim gasta 40 m a menos de cabo; o Dijkstra deixa cada sala com o
// caminho mais curto até o servidor (a Diretoria fica a 24 m, contra 28).
// Qual é "melhor" depende da pergunta: custo da obra ou atraso do sinal.
