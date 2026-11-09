// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2928 · ★★★ · Exato contra três aproximações

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 9
#define INF 1000000000

int d[N][N], dp[1 << N][N], pai[N], tam;

int custo(const int r[]) {
    int c = 0;
    for (int i = 0; i < N; i++) c += d[r[i]][r[(i + 1) % N]];
    return c;
}

int held_karp(void) {
    for (int s = 0; s < (1 << N); s++)
        for (int j = 0; j < N; j++) dp[s][j] = INF;
    dp[1][0] = 0;
    for (int s = 1; s < (1 << N); s += 2)
        for (int j = 0; j < N; j++) {
            if (!(s >> j & 1) || dp[s][j] == INF) continue;
            for (int k = 1; k < N; k++)
                if (!(s >> k & 1) && dp[s][j] + d[j][k] < dp[s | 1 << k][k])
                    dp[s | 1 << k][k] = dp[s][j] + d[j][k];
        }
    int melhor = INF;
    for (int j = 1; j < N; j++)
        if (dp[(1 << N) - 1][j] + d[j][0] < melhor) melhor = dp[(1 << N) - 1][j] + d[j][0];
    return melhor;
}

void vizinho(int r[]) {
    bool usado[N] = {true};
    r[0] = 0;
    for (int i = 1; i < N; i++) {
        int b = -1;
        for (int v = 1; v < N; v++)
            if (!usado[v] && (b == -1 || d[r[i - 1]][v] < d[r[i - 1]][b])) b = v;
        usado[b] = true;
        r[i] = b;
    }
}

void pre(int u, int r[]) {
    r[tam++] = u;
    for (int v = 1; v < N; v++)
        if (pai[v] == u) pre(v, r);
}

void arvore(int r[]) {
    int chave[N];
    bool dentro[N] = {false};
    for (int v = 0; v < N; v++) chave[v] = INF, pai[v] = -1;
    chave[0] = 0;
    for (int k = 0; k < N; k++) {
        int u = -1;
        for (int v = 0; v < N; v++)
            if (!dentro[v] && (u == -1 || chave[v] < chave[u])) u = v;
        dentro[u] = true;
        for (int v = 0; v < N; v++)
            if (!dentro[v] && d[u][v] < chave[v]) chave[v] = d[u][v], pai[v] = u;
    }
    tam = 0;
    pre(0, r);
}

void dois_opt(int r[]) {
    bool melhorou = true;
    while (melhorou) {
        melhorou = false;
        for (int i = 1; i < N - 1 && !melhorou; i++)
            for (int j = i + 1; j < N && !melhorou; j++) {
                int a = r[i - 1], b = r[i], c = r[j], e = r[(j + 1) % N];
                if (d[a][b] + d[c][e] > d[a][c] + d[b][e]) {
                    for (int x = i, y = j; x < y; x++, y--) {
                        int t = r[x];
                        r[x] = r[y];
                        r[y] = t;
                    }
                    melhorou = true;
                }
            }
    }
}

int main(void) {
    printf("dia  ótimo  vizinho     árvore      árvore+2opt\n");
    for (int dia = 1; dia <= 3; dia++) {
        unsigned semente = 11u * dia;
        int x[N], y[N];
        for (int i = 0; i < N; i++) {
            semente = semente * 1103515245u + 12345u;
            x[i] = (int)(semente >> 16) % 15;
            semente = semente * 1103515245u + 12345u;
            y[i] = (int)(semente >> 16) % 15;
        }
        for (int a = 0; a < N; a++)
            for (int b = 0; b < N; b++) d[a][b] = abs(x[a] - x[b]) + abs(y[a] - y[b]);
        int ot = held_karp(), r[N];
        vizinho(r);
        int nn = custo(r);
        arvore(r);
        int mst = custo(r);
        dois_opt(r);
        int opt2 = custo(r);
        printf("%3d  %5d  %3d (%.2f)  %3d (%.2f)  %3d (%.2f)\n", dia, ot, nn, (double)nn / ot, mst,
               (double)mst / ot, opt2, (double)opt2 / ot);
    }
    return 0;
}
