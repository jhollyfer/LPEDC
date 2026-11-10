// Lista · Módulo 16 · Grafos
// Exercício P1613 · ★★☆ · Dois turnos de prova e a aresta que estraga
//
// A coordenação quer marcar as provas finais em DOIS turnos, manhã e tarde.
// Duas disciplinas com alunos em comum (uma aresta do grafo não dirigido) não
// podem cair no mesmo turno. Isso só é possível se o grafo for BIPARTIDO.
//
// Escreva bool bipartido(int adj[V][V], int turno[]), que colore o grafo com
// BFS (turno 0 = manhã, 1 = tarde), começando uma BFS nova em cada vértice
// ainda sem turno (o grafo pode ter vários componentes). Ao achar uma aresta
// com as duas pontas no mesmo turno, mostre essa aresta e devolva false.
//
// Teste no grafo do esqueleto e, depois, no mesmo grafo com a aresta extra
// Calculo-Fisica.
//
//   Saída esperada:
//   Bipartido:
//     Calculo     manhã
//     Algoritmos  tarde
//     Fisica      manhã
//     Discreta    tarde
//     Ingles      manhã
//     Estatistica tarde
//   Com Calculo-Fisica:
//   Conflito: Algoritmos-Fisica no mesmo turno
//   Não é bipartido
//
// Dicas:
// 1. Comece com turno[v] = -1. A raiz de cada BFS recebe 0; cada vizinho
//    novo recebe 1 - turno[u].
// 2. Se o vizinho já tem turno e é igual ao de u, a aresta fecha um ciclo de
//    tamanho ímpar: não existe divisão em dois turnos.
// 3. Os vértices sem nenhuma aresta (ou de outro componente) precisam da
//    BFS nova: sem ela ficam com -1.
// 4. Resposta esperada: o primeiro grafo é bipartido; o segundo não, e a
//    aresta que estraga aparece ao examinar Algoritmos-Fisica.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *nomes[V] = {"Calculo", "Algoritmos", "Fisica", "Discreta", "Ingles", "Estatistica"};
int adj[V][V];

int main(void) {
    int pares[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {4, 5}};
    for (int k = 0; k < 5; k++) adj[pares[k][0]][pares[k][1]] = adj[pares[k][1]][pares[k][0]] = 1;

    return 0;
}
