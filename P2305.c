// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2305 · ★☆☆ · Os relógios da DFS
//
// O programa abaixo monta, com a DFS, a ordem das etapas de publicar um
// sistema (seta a -> b: a etapa a vem antes de b):
//
//   lint -> testes, testes -> build, build -> deploy, banco -> deploy,
//   deploy -> aviso
//
// Hoje ele não mostra nada. Instrumente-o como no Cormen: um relógio global
// que avança 1 quando a DFS DESCOBRE um vértice (guarde em d[u]) e 1 quando
// ela TERMINA o vértice (guarde em f[u]). Mostre d e f de cada etapa e a
// ordem, com o f de cada uma entre parênteses: ela sai em ordem decrescente
// de término.
//
//   Saída esperada:
//   lint      d =  1  f = 10
//   testes    d =  2  f =  9
//   build     d =  3  f =  8
//   banco     d = 11  f = 12
//   deploy    d =  4  f =  7
//   aviso     d =  5  f =  6
//   Ordem: banco(12) lint(10) testes(9) build(8) deploy(7) aviso(6)
//
// Dicas:
// 1. d[u] = ++relogio logo ao entrar em dfs(u); f[u] = ++relogio logo
//    depois do laço dos vizinhos, antes de pôr u na ordem.
// 2. Use printf("%-9s d = %2d  f = %2d\n", ...) para cada etapa.
// 3. Resposta esperada: lint vai de 1 a 10; banco, que ninguém alcança,
//    só é descoberto no 11 e termina no 12, por isso abre a ordem.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 6

const char *etapas[V] = {"lint", "testes", "build", "banco", "deploy", "aviso"};
int antes[V][V];
int visto[V];
int ordem[V], topo = V; // a ordem é preenchida de trás para a frente

void dfs(int u) {
    visto[u] = 1;
    for (int v = 0; v < V; v++)
        if (antes[u][v] && !visto[v]) dfs(v);
    ordem[--topo] = u;
}

int main(void) {
    int regras[][2] = {{0, 1}, {1, 2}, {2, 4}, {3, 4}, {4, 5}};
    for (int k = 0; k < 5; k++) antes[regras[k][0]][regras[k][1]] = 1;

    for (int u = 0; u < V; u++)
        if (!visto[u]) dfs(u);
    return 0;
}
