// A376 · Caixeiro viajante métrico: a árvore mínima vira rota

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 6

// pontos de uma cidade em quarteirões (x, y); distância = quarteirões andados
const char *pontos[N] = {"Loja", "Ana", "Bia", "Caio", "Davi", "Elis"};
const int px[N] = {0, 5, 2, 1, 7, 4};
const int py[N] = {0, 4, 4, 4, 2, 0};
int d[N][N];
int pai[N];           // pai na árvore geradora mínima
int rota[N], tam_rota = 0;

void preordem(int u) { // visita u e depois os filhos, em ordem de índice
    rota[tam_rota++] = u;
    for (int v = 0; v < N; v++)
        if (v != u && pai[v] == u) preordem(v);
}

int custo(const int r[]) {
    int c = 0;
    for (int i = 0; i < N; i++) c += d[r[i]][r[(i + 1) % N]];
    return c;
}

int melhor = 1 << 30, atual[N];
bool usado[N];

void forca_bruta(int pos, int acum) { // todas as rotas que começam na Loja
    if (acum >= melhor) return;
    if (pos == N) {
        if (acum + d[atual[N - 1]][0] < melhor) melhor = acum + d[atual[N - 1]][0];
        return;
    }
    for (int v = 1; v < N; v++) {
        if (usado[v]) continue;
        usado[v] = true;
        atual[pos] = v;
        forca_bruta(pos + 1, acum + d[atual[pos - 1]][v]);
        usado[v] = false;
    }
}

int main(void) {
    for (int a = 0; a < N; a++)
        for (int b = 0; b < N; b++) d[a][b] = abs(px[a] - px[b]) + abs(py[a] - py[b]);

    // Prim O(N²) a partir da Loja
    int chave[N];
    bool na_arvore[N] = {false};
    for (int v = 0; v < N; v++) chave[v] = 1 << 30, pai[v] = -1;
    chave[0] = 0;
    int peso_arvore = 0;
    for (int k = 0; k < N; k++) {
        int u = -1;
        for (int v = 0; v < N; v++)
            if (!na_arvore[v] && (u == -1 || chave[v] < chave[u])) u = v;
        na_arvore[u] = true;
        peso_arvore += chave[u];
        for (int v = 0; v < N; v++)
            if (!na_arvore[v] && d[u][v] < chave[v]) chave[v] = d[u][v], pai[v] = u;
    }

    preordem(0);
    printf("Árvore mínima: %d quarteirões\nRota aproximada:", peso_arvore);
    for (int i = 0; i < N; i++) printf(" %s", pontos[rota[i]]);
    printf(" %s = %d quarteirões\n", pontos[0], custo(rota));

    atual[0] = 0;
    usado[0] = true;
    forca_bruta(1, 0);
    printf("Ótimo (força bruta): %d quarteirões\n", melhor);
    printf("Garantia: rota <= 2 x árvore = %d\n", 2 * peso_arvore);
    return 0;
}
// Saída:
// Árvore mínima: 17 quarteirões
// Rota aproximada: Loja Elis Ana Bia Caio Davi Loja = 30 quarteirões
// Ótimo (força bruta): 22 quarteirões
// Garantia: rota <= 2 x árvore = 34
//
// A distância em quarteirões (|dx| + |dy|) respeita a desigualdade
// triangular, então a garantia vale: 30 <= 2 x 17 = 34 <= 2 x 22. A rota
// saiu 36% acima do ótimo, longe do dobro. Repare na volta Davi -> Loja:
// a pré-ordem termina longe de casa, e é aí que mora a perda. A árvore
// (17) é sempre menor que o ótimo (22), porque apagar uma aresta da rota
// ótima deixa uma árvore geradora.
