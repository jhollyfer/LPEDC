// 0111 · DFS: busca em profundidade
// Exercício E664 · ★★☆
//
// Você vai montar a ordem das disciplinas de um curso. Uma seta A -> B quer
// dizer "A é pré-requisito de B" (grafo dirigido, sem ciclo):
//
//   Lógica -> C, C -> Ponteiros, Ponteiros -> Estruturas,
//   Estruturas -> Grafos, Discreta -> Grafos, Lógica -> Discreta
//
// Índices: Lógica 0, C 1, Ponteiros 2, Estruturas 3, Grafos 4, Discreta 5.
//
// Escreva a ORDENAÇÃO TOPOLÓGICA com DFS: quando uma chamada dfs(u)
// TERMINA (depois de visitar todos os sucessores), anote u numa lista. A
// lista lida de trás para frente é uma ordem em que todo pré-requisito vem
// antes. Comece a DFS de cada vértice não visitado, em ordem de índice.
//
//   Saída esperada:
//   Ordem de término: Grafos Estruturas Ponteiros C Discreta Lógica
//   Ordem para cursar: Lógica Discreta C Ponteiros Estruturas Grafos
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
