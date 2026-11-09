// Lista · Módulo 16 · Grafos
// Exercício P1627 · ★★★ · Quem alcança quem no centro histórico
//
// No centro histórico de Manaus, as ruas do esqueleto são de mão única
// (grafo DIRIGIDO). A prefeitura quer duas respostas:
//
// 1. O FECHO TRANSITIVO: alc[u][v] == 1 se dá para ir de u até v (u sempre
// alcança a si mesmo). Calcule rodando uma BFS a partir de CADA vértice:
// V buscas de O(V + E) cada, com lista de adjacência. Use a matriz só
// para guardar o resultado.
// 2. Os GRUPOS DE IDA E VOLTA: u e v estão no mesmo grupo quando alc[u][v] e
// alc[v][u]. Mostre cada grupo uma vez (rotule com o menor índice) e diga
// quantos pares (u, v), u != v, têm caminho de u para v.
//
//   Saída esperada:
//   de \ para    0 1 2 3 4 5 6
//   0 Teatro     1 1 1 1 1 1 1
//   1 Praca      1 1 1 1 1 1 1
//   2 Palacio    0 0 1 1 1 1 1
//   3 Mercado    0 0 0 1 1 1 1
//   4 Porto      0 0 0 1 1 1 1
//   5 Alfandega  0 0 0 1 1 1 1
//   6 Matriz     0 0 0 0 0 0 1
//   Grupo: Teatro Praca
//   Grupo: Palacio
//   Grupo: Mercado Porto Alfandega
//   Grupo: Matriz
//   Grupos de ida e volta: 4 | pares com caminho: 25
//
// Dicas:
// 1. Monte a lista de adjacência a partir de ruas[] com malloc e libere no
//    fim. A BFS a partir de s marca alc[s][v] = 1 para cada v descoberto.
// 2. Os grupos são as COMPONENTES FORTEMENTE CONEXAS. Aqui elas saem do fecho
//    em O(V²), sem algoritmo novo: grupo[v] = o menor u com alc[u][v] e
//    alc[v][u].
// 3. Um grupo com um vértice só é um ponto de onde se sai e não se volta.
// 4. Resposta esperada: 4 grupos ({Teatro, Praca}, {Palacio}, {Mercado, Porto,
//    Alfandega}, {Matriz}) e 25 pares com caminho.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define V 7

typedef struct No {
    int v;
    struct No *prox;
} No;

const char *nomes[V] = {"Teatro", "Praca", "Palacio", "Mercado", "Porto", "Alfandega", "Matriz"};

int main(void) {
    int ruas[][2] = {{0, 1}, {1, 0}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 3}, {5, 6}};
    int total = 8;

    (void)ruas; // apague estas linhas quando usar ruas e total
    (void)total;
    return 0;
}
