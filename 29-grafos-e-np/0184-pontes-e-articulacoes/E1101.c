// 0184 · Pontes e articulações
// Exercício E1101 · ★★☆
//
// A operadora do texto quer saber o tamanho do estrago de cada ponte:
// cortando o cabo, quantos bairros ficam sem sinal? Mude a DFS do texto
// para que ela devolva o tamanho da subárvore (int dfs(int u, int pai)) e,
// em cada ponte u - v, mostre quantos bairros ficam do lado de v. No fim,
// mostre quantos bairros a DFS alcançou a partir do Centro.
//
//   Saída esperada:
//   Cortar Tarumã - Ponta Negra isola 1 bairro(s)
//   Cortar Aleixo - Flores isola 4 bairro(s)
//   Bairros alcançados: 7
//
// Dicas:
// 1. Cada chamada começa com tamanho = 1 (o próprio u) e soma o valor
//    devolvido por cada dfs(v, u) da árvore. Arestas de volta não somam.
// 2. Quando low[v] > tin[u], a subárvore de v é exatamente o pedaço que
//    perde a ligação: o tamanho dela é o número procurado.
// 3. Resposta esperada: a saída acima (Flores, Cidade Nova, Tarumã e Ponta
//    Negra ficam do outro lado do cabo Aleixo - Flores).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
