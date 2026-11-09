// 0182 · Caminhos e ciclos
// Exercício E1089 · ★★☆
//
// O programa abaixo já monta quatro grafos (com arestas paralelas contadas
// na matriz): o bairro do texto, a casinha do A364, dois triângulos
// separados e as sete pontes de Königsberg (4 margens, 7 pontes). Escreva a
// função analisa, que mostra se o grafo tem circuito euleriano, trajeto
// euleriano aberto (dizendo entre quais vértices) ou nenhum dos dois, e por
// quê. Ela precisa conferir a conexidade antes dos graus.
//
//   Saída esperada:
//   bairro: circuito euleriano
//   casinha: trajeto euleriano de 0 a 1
//   triângulos: nenhum (desconexo)
//   pontes: nenhum (4 vértices ímpares)
//
// Dicas:
// 1. Conexidade: rode uma DFS a partir do primeiro vértice com grau > 0 e
//    confira se todo vértice com grau > 0 foi visitado.
// 2. Depois guarde os vértices de grau ímpar num vetor: 0 ímpares dá
//    circuito; 2 dá trajeto entre eles; outro número, nenhum.
// 3. Resposta esperada: a saída acima. Os triângulos têm todos os graus
//    iguais a 2 e mesmo assim não têm circuito.
//
// Escreva sua resposta abaixo (complete a função analisa):

#include <stdbool.h>
#include <stdio.h>

#define MAXV 6

typedef struct {
    const char *nome;
    int v;
    int m[MAXV][MAXV]; // m[a][b] = quantas arestas ligam a e b
} Grafo;

void analisa(const Grafo *g) {
    (void)g; // apague esta linha ao escrever a função
}

void liga(Grafo *g, int a, int b) {
    g->m[a][b]++;
    g->m[b][a]++;
}

int main(void) {
    Grafo bairro = {"bairro", 6, {{0}}}, casinha = {"casinha", 5, {{0}}};
    Grafo triangulos = {"triângulos", 6, {{0}}}, pontes = {"pontes", 4, {{0}}};
    int r1[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 5}, {2, 4}, {2, 5}, {3, 4}};
    for (int k = 0; k < 8; k++) liga(&bairro, r1[k][0], r1[k][1]);
    int r2[][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {0, 3}, {1, 2}, {2, 4}, {3, 4}};
    for (int k = 0; k < 8; k++) liga(&casinha, r2[k][0], r2[k][1]);
    int r3[][2] = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 3}};
    for (int k = 0; k < 6; k++) liga(&triangulos, r3[k][0], r3[k][1]);
    int r4[][2] = {{0, 1}, {0, 1}, {0, 2}, {0, 2}, {0, 3}, {1, 3}, {2, 3}};
    for (int k = 0; k < 7; k++) liga(&pontes, r4[k][0], r4[k][1]);

    analisa(&bairro);
    analisa(&casinha);
    analisa(&triangulos);
    analisa(&pontes);
    return 0;
}
