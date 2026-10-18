// 0153 · Prim: a árvore que cresce
// Exercício E913 · ★☆☆
//
// Na orla, um gerador vai alimentar quatro quiosques: Coco, Pastel, Açaí e
// Milho. A matriz (já no main) tem os metros de cabo de cada trecho
// possível; 0 quer dizer "não dá para passar cabo". Escreva o Prim sem
// heap, em O(V²), a partir do Gerador: vetores chave[], pai[] e
// na_rede[]; a cada passo, entra o vértice fora da rede com a menor chave.
// Mostre cada cabo na ordem em que entra e o total.
//
//   Saída esperada:
//   Gerador - Coco: 12 m
//   Coco - Pastel: 9 m
//   Pastel - Açaí: 6 m
//   Açaí - Milho: 11 m
//   Total: 38 m
//
// Dicas:
// 1. Comece com chave = INFINITO em todos, chave[0] = 0 e pai = -1. É o
//    Dijkstra do assunto 0112, com outra regra de atualização.
// 2. Quando u entra, para cada v fora da rede com cabo[u][v] != 0: se
//    cabo[u][v] < chave[v], então chave[v] = cabo[u][v] e pai[v] = u.
//    Não some chave[u]: no Prim, a chave é só o cabo.
// 3. Resposta esperada: a saída acima. O Milho começa com 30 (pelo Coco),
//    cai para 15 (pelo Pastel) e termina em 11 (pelo Açaí).
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INFINITO INT_MAX

int main(void) {
    const char *nomes[V] = {"Gerador", "Coco", "Pastel", "Açaí", "Milho"};
    int cabo[V][V] = {
        {0, 12, 20, 25, 0},
        {12, 0, 9, 0, 30},
        {20, 9, 0, 6, 15},
        {25, 0, 6, 0, 11},
        {0, 30, 15, 11, 0},
    };
    (void)nomes; // apague estas duas linhas
    (void)cabo;

    return 0;
}
