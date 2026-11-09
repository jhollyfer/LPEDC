// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2313 · ★★☆ · A trilha que vale mais pontos
//
// No jogo de plataforma, você sai do Início e chega ao Chefão passando por
// fases; cada passagem (só para a frente) dá pontos:
//
//   Início -> Floresta 5, Início -> Caverna 3, Floresta -> Rio 6,
//   Caverna -> Rio 9, Floresta -> Castelo 2, Rio -> Castelo 4,
//   Rio -> Chefão 7, Castelo -> Chefão 8
//
// Num grafo qualquer, o caminho MAIS LONGO é um problema difícil. Num DAG
// ele é fácil: a mesma ideia do caminho mínimo em DAG, relaxando na ordem
// topológica, mas guardando o MAIOR total. Escreva o programa do zero:
// ordem topológica pelo Kahn, o maior total até cada fase e a trilha
// campeã (refeita por pai[]).
//
//   Saída esperada:
//   Ordem: Início Floresta Caverna Rio Castelo Chefão
//   Início: 0 pontos
//   Floresta: 5 pontos
//   Caverna: 3 pontos
//   Rio: 12 pontos
//   Castelo: 16 pontos
//   Chefão: 24 pontos
//   Melhor trilha: Início -> Caverna -> Rio -> Castelo -> Chefão
//
// Dicas:
// 1. Comece melhor[] com INT_MIN (inalcançável) e melhor[Início] = 0.
//    Pule vértices ainda em INT_MIN para não somar com ele.
// 2. Na ordem topológica, quando você processa u, todos que chegam em u já
//    foram processados: melhor[u] já é definitivo.
// 3. Resposta esperada: 24 pontos, pela Caverna (3 + 9 + 4 + 8), contra 23
//    pela Floresta.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdio.h>

int main(void) {

    return 0;
}
