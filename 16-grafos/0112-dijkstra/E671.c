// 0112 · Dijkstra: caminho mínimo
// Exercício E671 · ★★★
//
// Este programa tem um erro de propósito. Ele calcula o voo mais barato
// saindo de São Paulo. Manaus e Belém têm voo entre si, mas nenhum voo liga
// as duas ao resto do mapa. Rode com o rodar: o UndefinedBehaviorSanitizer
// acusa "signed integer overflow" e aponta a linha da conta que estoura.
// Conserte sem trocar o valor de INFINITO e rode de novo até a saída bater
// com a esperada, sem nenhum aviso do sanitizer.
//
//   Saída esperada depois do conserto:
//   Rio: R$ 200
//   BH: R$ 250
//   Manaus: sem voo
//   Belém: sem voo
//
// Dicas:
// 1. Depois de fixar SP, Rio e BH, quem o laço escolhe como u? Qual é o
//    dist[u] dele?
// 2. INT_MAX + 300 não cabe num int. Em int com sinal isso é comportamento
//    indefinido; na prática vira um número negativo.
// 3. Resposta esperada: a escolha de u aceita vértices com dist == INFINITO;
//    ao escolher Manaus, a conta dist[u] + preco[u][v] faz INT_MAX + 300. O
//    conserto: só escolher u com dist[u] != INFINITO e sair do laço (break)
//    quando não houver nenhum. Consertado, mostra a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INFINITO INT_MAX

int main(void) {
    const char *nomes[V] = {"SP", "Rio", "BH", "Manaus", "Belém"};
    int preco[V][V] = {0};
    int voos[][3] = {{0, 1, 200}, {0, 2, 250}, {1, 2, 180}, {3, 4, 300}};
    for (int k = 0; k < 4; k++) {
        preco[voos[k][0]][voos[k][1]] = voos[k][2];
        preco[voos[k][1]][voos[k][0]] = voos[k][2];
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
            if (!fixo[v] && (u == -1 || dist[v] < dist[u])) u = v;
        fixo[u] = true;
        for (int v = 0; v < V; v++)
            if (preco[u][v] && !fixo[v] && dist[u] + preco[u][v] < dist[v])
                dist[v] = dist[u] + preco[u][v];
    }

    for (int v = 1; v < V; v++) {
        if (dist[v] == INFINITO) printf("%s: sem voo\n", nomes[v]);
        else printf("%s: R$ %d\n", nomes[v], dist[v]);
    }
    return 0;
}
