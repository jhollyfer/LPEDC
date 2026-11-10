// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2926 · ★★★ · De ciclo hamiltoniano para caixeiro viajante
//
// A redução que prova que o caixeiro viajante é NP-difícil: dado um grafo
// G com n vértices, monte a matriz de custos d[a][b] = 1 se a-b é aresta
// de G e 2 se não é. G tem ciclo hamiltoniano se e só se a volta mais
// barata custa exatamente n. Escreva a redução e resolva o caixeiro pelo
// Held-Karp, para dois grafos de 6 vértices:
//
//   G1: 0-1, 0-2, 0-4, 1-2, 1-3, 2-3, 3-4, 3-5, 4-5   (as agências do 0183)
//   G2: 0-1, 1-2, 2-0, 0-3, 3-4, 4-0, 0-5, 5-1        (gravata com um extra)
//
//   Saída esperada:
//   G1: volta mais barata = 6 -> tem ciclo hamiltoniano
//   G2: volta mais barata = 7 -> não tem
//
// Dicas:
// 1. Uma função void decide(const char *nome, int ne, int a[][2]) monta d e
//    chama o Held-Karp (dp[1 << 6][6], global).
// 2. Toda volta usa n trechos; cada trecho custa 1 ou 2. Custo n quer dizer
//    que todos os trechos são arestas de G.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
