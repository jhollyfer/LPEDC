// 0189 · Juntando tudo
// Exercício E1133 · ★★★

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 30
#define LIMITE_EXATO 12
#define INF 1000000000

int n, d[MAXN][MAXN];
int dp[1 << LIMITE_EXATO][LIMITE_EXATO];
int pai[MAXN], rota[MAXN], tam;

int held_karp(void) {
    for (int s = 0; s < (1 << n); s++)
        for (int j = 0; j < n; j++) dp[s][j] = INF;
    dp[1][0] = 0;
    for (int s = 1; s < (1 << n); s += 2)
        for (int j = 0; j < n; j++) {
            if (!(s >> j & 1) || dp[s][j] == INF) continue;
            for (int k = 1; k < n; k++)
                if (!(s >> k & 1) && dp[s][j] + d[j][k] < dp[s | 1 << k][k])
                    dp[s | 1 << k][k] = dp[s][j] + d[j][k];
        }
    int melhor = INF;
    for (int j = 1; j < n; j++)
        if (dp[(1 << n) - 1][j] + d[j][0] < melhor) melhor = dp[(1 << n) - 1][j] + d[j][0];
    return melhor;
}

void preordem(int u) {
    rota[tam++] = u;
    for (int v = 1; v < n; v++)
        if (pai[v] == u) preordem(v);
}

int custo(void) {
    int c = 0;
    for (int i = 0; i < n; i++) c += d[rota[i]][rota[(i + 1) % n]];
    return c;
}

int arvore(void) { // Prim; devolve o peso e deixa a rota em pré-ordem
    int chave[MAXN], peso = 0;
    bool dentro[MAXN] = {false};
    for (int v = 0; v < n; v++) chave[v] = INF, pai[v] = -1;
    chave[0] = 0;
    for (int k = 0; k < n; k++) {
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!dentro[v] && (u == -1 || chave[v] < chave[u])) u = v;
        dentro[u] = true;
        peso += chave[u];
        for (int v = 0; v < n; v++)
            if (!dentro[v] && d[u][v] < chave[v]) chave[v] = d[u][v], pai[v] = u;
    }
    tam = 0;
    preordem(0);
    return peso;
}

void dois_opt(void) {
    bool melhorou = true;
    while (melhorou) {
        melhorou = false;
        for (int i = 1; i < n - 1 && !melhorou; i++)
            for (int j = i + 1; j < n && !melhorou; j++) {
                int a = rota[i - 1], b = rota[i], c = rota[j], e = rota[(j + 1) % n];
                if (d[a][b] + d[c][e] > d[a][c] + d[b][e]) {
                    for (int x = i, y = j; x < y; x++, y--) {
                        int t = rota[x];
                        rota[x] = rota[y];
                        rota[y] = t;
                    }
                    melhorou = true;
                }
            }
    }
}

void planeja(const char *nome, const int px[], const int py[], int pontos) {
    n = pontos;
    for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++) d[a][b] = abs(px[a] - px[b]) + abs(py[a] - py[b]);
    if (n <= LIMITE_EXATO) {
        printf("%s (%d pontos): exato, %d quarteirões\n", nome, n, held_karp());
        return;
    }
    int peso = arvore();
    int antes = custo();
    dois_opt();
    printf("%s (%d pontos): aproximado, árvore %d, rota %d, com 2-opt %d\n", nome, n, peso, antes, custo());
}

int main(void) {
    int ax[8] = {0, 1, 4, 6, 7, 5, 2, 3}, ay[8] = {0, 3, 4, 3, 0, 1, 6, 1};
    planeja("Manhã", ax, ay, 8);

    int bx[MAXN], by[MAXN];
    unsigned semente = 7;
    for (int i = 0; i < MAXN; i++) {
        semente = semente * 1103515245u + 12345u;
        bx[i] = (int)(semente >> 16) % 25;
        semente = semente * 1103515245u + 12345u;
        by[i] = (int)(semente >> 16) % 25;
    }
    planeja("Tarde", bx, by, MAXN);
    return 0;
}
