// 0111 · DFS: busca em profundidade
// Exercício E663 · ★★☆
//
// Uma foto de satélite do litoral virou uma grade: # é terra e ~ é água.
// Terras vizinhas na horizontal ou na vertical (diagonal não conta) formam
// uma ilha. Quantas ilhas há e qual o tamanho da maior?
//
//   ##~~~#~
//   #~~~##~
//   ~~#~~~~
//   ~###~~#
//   ~~#~~##
//
// Use DFS recursiva: ao achar uma terra ainda não visitada, "pinte" a ilha
// inteira a partir dela, contando as casas.
//
//   Saída esperada:
//   Ilha 1: 3 casa(s)
//   Ilha 2: 3 casa(s)
//   Ilha 3: 5 casa(s)
//   Ilha 4: 3 casa(s)
//   Total: 4 ilhas, a maior tem 5 casas
//
// Dicas:
// 1. A grade é um grafo implícito: cada casa é um vértice e os vizinhos são
//    as 4 casas ao redor (como no A220, só que com DFS).
// 2. int pintar(int l, int c): se (l, c) está fora da grade, é água ou já
//    foi visitada, devolve 0; senão marca e devolve 1 + pintar das 4 vizinhas.
// 3. Dá para marcar trocando o '#' por outro caractere, sem vetor extra.
// 4. Resposta esperada: a saída acima (ilhas numeradas na ordem em que a
//    varredura linha por linha encontra cada uma).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define L 5
#define C 7

int main(void) {

    return 0;
}
