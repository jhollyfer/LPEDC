// 0118 · Juntando tudo: a central de entregas
// Exercício E703 · ★☆☆
//
// Até aqui os grafos vinham escritos no código. Escreva um programa que LÊ
// o grafo do teclado (não dirigido): primeiro o número de vértices n (até
// 20) e de arestas e; depois e linhas com "a b". Mostre os vizinhos e o grau
// de cada vértice. Ignore, com um aviso, arestas com vértice fora de 0..n-1
// ou laço (a == b), e confira o retorno do scanf.
//
//   Teste: printf '5 6\n0 1\n0 2\n1 2\n2 3\n3 4\n1 4\n' | ~/LPEDC/rodar ...
//   Saída esperada:
//   0: 1 2 (grau 2)
//   1: 0 2 4 (grau 3)
//   2: 0 1 3 (grau 3)
//   3: 2 4 (grau 2)
//   4: 1 3 (grau 2)
//
//   Teste com erro: printf '3 2\n0 1\n1 7\n'
//   Aresta inválida: 1 7
//   0: 1 (grau 1)
//   1: 0 (grau 1)
//   2: (grau 0)
//
// Dicas:
// 1. Declare int adj[20][20] = {0}; e use só as n primeiras linhas e colunas.
// 2. scanf("%d %d", &a, &b) != 2 quer dizer que a entrada acabou ou veio
//    lixo: pare com uma mensagem.
// 3. Resposta esperada: as saídas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
