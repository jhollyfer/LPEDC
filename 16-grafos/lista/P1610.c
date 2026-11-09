// Lista · Módulo 16 · Grafos
// Exercício P1610 · ★☆☆ · Comunidades do rio: quantas lanchas faltam
//
// Nove comunidades ribeirinhas do Rio Negro (0 a 8) são ligadas por linhas
// de lancha de ida e volta:
//
//   0-1, 1-2, 0-2, 3-4, 5-6, 6-7, 5-7
//
// A comunidade 8 está isolada. Um grupo de comunidades que se alcançam, direta
// ou indiretamente, é um COMPONENTE CONEXO. Para ligar k componentes num só
// bastam k - 1 linhas novas (uma ligando cada grupo ao seguinte).
//
// Escreva do zero um programa que rotule os componentes com uma DFS (comp[v] =
// número do componente), mostre os membros de cada componente e quantas linhas
// novas são necessárias.
//
//   Saída esperada:
//   Componente 0: 0 1 2
//   Componente 1: 3 4
//   Componente 2: 5 6 7
//   Componente 3: 8
//   Componentes: 4
//   Linhas novas necessárias: 3
//
// Dicas:
// 1. Comece com comp[v] = -1. Para cada v ainda sem rótulo, chame
//    dfs(v, k) com o próximo número k e some 1 em k.
// 2. dfs(u, k): comp[u] = k; visite todo vizinho sem rótulo com o mesmo k.
// 3. Componente com um vértice só também conta: a comunidade 8 é um
//    componente.
// 4. Resposta esperada: 4 componentes, logo 3 linhas novas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 9

int adj[V][V];

int main(void) {
    int linhas[][2] = {{0, 1}, {1, 2}, {0, 2}, {3, 4}, {5, 6}, {6, 7}, {5, 7}};
    for (int k = 0; k < 7; k++) adj[linhas[k][0]][linhas[k][1]] = adj[linhas[k][1]][linhas[k][0]] = 1;

    return 0;
}
