// A366 · Quando a resposta é não: o custo explode

#include <stdbool.h>
#include <stdio.h>

#define MAXV 12

int n; // vértices em uso: n - 1 formam um grafo completo, o último é uma "folha"
int adj[MAXV][MAXV];
int rota[MAXV];
bool usado[MAXV];
long chamadas;

bool hamilton(int pos) {
    chamadas++;
    if (pos == n) return adj[rota[n - 1]][rota[0]];
    for (int v = 1; v < n; v++) {
        if (!adj[rota[pos - 1]][v] || usado[v]) continue;
        rota[pos] = v;
        usado[v] = true;
        if (hamilton(pos + 1)) return true;
        usado[v] = false;
    }
    return false;
}

int main(void) {
    printf("vértices  chamadas  fatorial (V-2)!\n");
    long fat = 1;
    for (n = 4; n <= 11; n++) {
        for (int a = 0; a < n; a++)
            for (int b = 0; b < n; b++) adj[a][b] = 0;
        for (int a = 0; a < n - 1; a++) // os n - 1 primeiros: todos ligados a todos
            for (int b = 0; b < n - 1; b++) adj[a][b] = a != b;
        adj[1][n - 1] = adj[n - 1][1] = 1; // a folha só se liga ao vértice 1

        for (int v = 0; v < n; v++) usado[v] = false;
        chamadas = 0;
        rota[0] = 0;
        usado[0] = true;
        bool achou = hamilton(1);
        fat *= n - 2 > 1 ? n - 2 : 1;
        printf("%8d  %8ld  %15ld  %s\n", n, chamadas, fat, achou ? "achou" : "não existe");
    }
    return 0;
}
// Saída:
// vértices  chamadas  fatorial (V-2)!
//        4         7                2  não existe
//        5        21                6  não existe
//        6        81               24  não existe
//        7       391              120  não existe
//        8      2283              720  não existe
//        9     15657             5040  não existe
//       10    123301            40320  não existe
//       11   1096011           362880  não existe
//
// A folha tem grau 1: nenhum ciclo pode entrar e sair dela, e a resposta é
// "não" para qualquer tamanho. Um teste de grau resolveria na hora, mas o
// backtracking puro não sabe disso e tenta as rotas dos n - 1 vértices do
// grafo completo. Cada vértice a mais multiplica as chamadas por quase n:
// é o crescimento fatorial. Com 20 vértices seriam mais de 10^16 chamadas.
