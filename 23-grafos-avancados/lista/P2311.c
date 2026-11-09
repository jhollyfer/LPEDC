// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2311 · ★★☆ · Kosaraju nas rotas de barco
//
// Oito portos do Amazonas têm barcos de mão única entre eles (seta a -> b:
// tem barco de a para b). Um grupo de portos é FORTEMENTE CONEXO quando
// dá para ir de qualquer um deles a qualquer outro, e voltar, só de barco.
// O algoritmo de Kosaraju acha esses grupos com duas DFS:
//
//   1. uma DFS no grafo original anota a ordem de TÉRMINO dos vértices;
//   2. uma DFS no grafo com as setas INVERTIDAS, começando pelos vértices
//      do último a terminar para o primeiro: cada DFS nova pinta um grupo.
//
// O programa já faz o passo 1 e monta a matriz inversa. Complete o passo
// 2: escreva dfs2(u, g) e o laço que a chama, e mostre os grupos (os
// portos de cada um em ordem de índice).
//
//   Saída esperada:
//   Término da 1ª DFS: Autazes Silves Itacoatiara Careiro Novo Airão Manacapuru Iranduba Manaus
//   Grupo 1: Manaus Iranduba Manacapuru
//   Grupo 2: Novo Airão Careiro
//   Grupo 3: Autazes Itacoatiara Silves
//
// Dicas:
// 1. dfs2(u, g) é a mesma DFS de componentes: grupo[u] = g e desce em todo
//    v com inversa[u][v] e grupo[v] == 0.
// 2. Percorra ordem[] de trás para a frente (i de V - 1 até 0). Quem ainda
//    está com grupo 0 começa um grupo novo: dfs2(u, ++g).
// 3. Resposta esperada: 3 grupos: Manaus, Iranduba e Manacapuru; Novo Airão
//    e Careiro; Autazes, Itacoatiara e Silves.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define V 8

const char *portos[V] = {"Manaus", "Iranduba", "Manacapuru", "Novo Airão",
                         "Careiro", "Autazes", "Itacoatiara", "Silves"};
int rota[V][V];    // rota[a][b] = 1: tem barco de a para b
int inversa[V][V]; // o grafo com as setas invertidas
bool visto[V];
int ordem[V], n_ordem = 0; // vértices em ordem de término da 1ª DFS
int grupo[V];

void dfs1(int u) {
    visto[u] = true;
    for (int v = 0; v < V; v++)
        if (rota[u][v] && !visto[v]) dfs1(v);
    ordem[n_ordem++] = u; // terminou
}

int main(void) {
    int barcos[][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 3}, {0, 5}, {5, 6}, {6, 7}, {7, 5}, {4, 6}};
    for (int k = 0; k < 11; k++) {
        rota[barcos[k][0]][barcos[k][1]] = 1;
        inversa[barcos[k][1]][barcos[k][0]] = 1;
    }

    for (int u = 0; u < V; u++)
        if (!visto[u]) dfs1(u);
    printf("Término da 1ª DFS:");
    for (int i = 0; i < V; i++) printf(" %s", portos[ordem[i]]);
    printf("\n");

    return 0;
}
