// 0184 · Pontes e articulações
// Exercício E1100 · ★☆☆
//
// O programa abaixo já faz a DFS com tin e low nas rodovias do E1099, mas
// faltam as três linhas que dão sentido ao low. Hoje ele não acha ponte
// nenhuma e mostra low igual a tin em todo mundo. Complete as linhas
// marcadas com FALTA.
//
//   Saída esperada:
//   Ponte: Manacapuru - Novo Airão
//   Ponte: Rio Preto da Eva - Itacoatiara
//   Ponte: Manaus - Rio Preto da Eva
//   Manaus: tin 1, low 1
//   Iranduba: tin 2, low 1
//   Manacapuru: tin 3, low 1
//   Novo Airão: tin 4, low 4
//   Rio Preto da Eva: tin 5, low 5
//   Itacoatiara: tin 6, low 6
//
// Dicas:
// 1. Aresta de volta (v já visitado e não é o pai): low[u] pode cair para
//    tin[v].
// 2. Depois de dfs(v, u): low[u] pode cair para low[v]. E a aresta é
//    ponte se low[v] > tin[u].
// 3. Resposta esperada: a saída acima. As pontes saem na ordem em que a
//    DFS VOLTA, não na ordem das rodovias: Itacoatiara termina antes de
//    Rio Preto da Eva.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *cidades[V] = {"Manaus", "Iranduba", "Manacapuru", "Novo Airão", "Rio Preto da Eva", "Itacoatiara"};
int estrada[V][V];
int tin[V], low[V], relogio = 0;

void dfs(int u, int pai) {
    tin[u] = low[u] = ++relogio;
    for (int v = 0; v < V; v++) {
        if (!estrada[u][v] || v == pai) continue;
        if (tin[v] != 0) {
            // FALTA: atualizar low[u] com a aresta de volta
            continue;
        }
        dfs(v, u);
        // FALTA: atualizar low[u] com o que o filho alcança
        // FALTA: testar se u - v é ponte e mostrar
    }
}

int main(void) {
    int rodovias[][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {0, 4}, {4, 5}};
    for (int k = 0; k < 6; k++) estrada[rodovias[k][0]][rodovias[k][1]] = estrada[rodovias[k][1]][rodovias[k][0]] = 1;

    dfs(0, -1);
    for (int u = 0; u < V; u++) printf("%s: tin %d, low %d\n", cidades[u], tin[u], low[u]);
    return 0;
}
