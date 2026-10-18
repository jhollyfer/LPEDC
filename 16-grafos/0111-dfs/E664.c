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
// Dicas:
// 1. A anotação vai DEPOIS do laço dos vizinhos (pós-ordem, como no percurso
//    de árvore do assunto 0098).
// 2. Uma disciplina só termina depois de todas que dependem dela; por isso a
//    ordem de término é a ordem de estudo invertida.
// 3. Resposta esperada: a saída acima. Outras ordens também seriam válidas
//    (Lógica, C, Discreta...), mas esta é a que a DFS em ordem de índice dá.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
