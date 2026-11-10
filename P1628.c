// Lista · Módulo 16 · Grafos
// Exercício P1628 · ★★★ · A rede de fibra do campus é uma árvore?
//
// A rede de fibra de um campus liga seis prédios (não dirigido). Ela é uma
// ÁRVORE quando é conexa e não tem ciclo; aí tem exatamente V - 1 cabos. Mas
// a recíproca engana: ter V - 1 cabos não basta.
//
// Escreva void diagnostico(const char *titulo, int cabos[][2], int e), que
// monta a matriz, roda uma DFS por componente e mostra:
//
// - V, E e o número de componentes;
// - cada cabo que fecha ciclo (aresta de retorno, mostrada uma vez só);
// - se é árvore; se não for, quantos cabos sobram (E - (V - componentes)) e
// quantos faltam para ligar tudo (componentes - 1).
//
// Rode nas três redes do esqueleto.
//
//   Saída esperada:
//   Rede A:
//     V = 6, E = 5, componentes = 1
//     é árvore
//   Rede B:
//     ciclo fechado por ICE-Reitoria
//     V = 6, E = 5, componentes = 2
//     não é árvore: sobram 1 cabo(s) (E - (V - comp) = 1), faltam 1
//   Rede C:
//     ciclo fechado por Restaurante-Biblioteca
//     ciclo fechado por Hospital-Reitoria
//     V = 6, E = 7, componentes = 1
//     não é árvore: sobram 2 cabo(s) (E - (V - comp) = 2), faltam 0
//
// Dicas:
// 1. Uma DFS com pai[] e d[]: ao ver um vizinho v já visitado, com v !=
//    pai[u] e d[v] < d[u], a aresta u-v é de retorno. O teste d[v] < d[u]
//    evita mostrar o mesmo cabo duas vezes (quando a DFS o vê do outro lado).
// 2. Cada componente com k vértices tem uma árvore da DFS com k - 1 arestas.
//    Logo, as arestas de árvore somam V - componentes, e as de retorno são o
//    resto: E - (V - componentes).
// 3. A rede B é a pegadinha: tem 5 cabos (V - 1), mas um ciclo e dois
//    componentes.
// 4. Resposta esperada: A é árvore; B tem 2 componentes e o ciclo fechado por
//    ICE-Reitoria; C tem 2 cabos sobrando (Restaurante-Biblioteca e
//    Hospital-Reitoria, nessa ordem da DFS).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *nomes[V] = {"Reitoria", "Biblioteca", "ICE", "FT", "Restaurante", "Hospital"};

int main(void) {
    int a[][2] = {{0, 1}, {1, 2}, {1, 3}, {3, 4}, {3, 5}};
    int b[][2] = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}};
    int c[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}, {1, 4}};

    (void)a; // apague estas linhas quando chamar o diagnóstico
    (void)b;
    (void)c;
    return 0;
}
