// Lista · Módulo 21 · Programação dinâmica
// Exercício P2130 · ★★★ · O caixeiro viajante do Amazonas

#include <stdio.h>

#define N 6
#define TODAS ((1 << (N - 1)) - 1)
#define INF 1000000

const char *cidade[N] = {"Manaus", "Itacoatiara", "Manacapuru", "Parintins", "Tefé", "Coari"};
const int dist[N][N] = {
    {0, 6, 3, 18, 30, 22},
    {6, 0, 8, 12, 34, 27},
    {3, 8, 0, 20, 27, 19},
    {18, 12, 20, 0, 45, 38},
    {30, 34, 27, 45, 0, 9},
    {22, 27, 19, 38, 9, 0},
};
int custo[TODAS + 1][N], pai[TODAS + 1][N];

int bruta_melhor = INF, perm[N], usado[N];

void bruta(int k, int atual, int soma) {
    if (k == N) {
        if (soma + dist[atual][0] < bruta_melhor) {
            bruta_melhor = soma + dist[atual][0];
        }
        return;
    }
    for (int v = 1; v < N; v++) {
        if (!usado[v]) {
            usado[v] = 1;
            bruta(k + 1, v, soma + dist[atual][v]);
            usado[v] = 0;
        }
    }
}

int main(void) {
    for (int S = 0; S <= TODAS; S++) {
        for (int v = 0; v < N; v++) {
            custo[S][v] = INF;
        }
    }
    for (int v = 1; v < N; v++) {
        custo[1 << (v - 1)][v] = dist[0][v];
        pai[1 << (v - 1)][v] = 0;
    }
    for (int S = 1; S <= TODAS; S++) {
        for (int v = 1; v < N; v++) {
            int bv = 1 << (v - 1);
            if (!(S & bv) || S == bv) {
                continue;
            }
            int R = S & ~bv;
            for (int u = 1; u < N; u++) {
                if ((R & (1 << (u - 1))) && custo[R][u] + dist[u][v] < custo[S][v]) {
                    custo[S][v] = custo[R][u] + dist[u][v];
                    pai[S][v] = u;
                }
            }
        }
    }
    int melhor = INF, ultimo = 0;
    for (int v = 1; v < N; v++) {
        if (custo[TODAS][v] + dist[v][0] < melhor) {
            melhor = custo[TODAS][v] + dist[v][0];
            ultimo = v;
        }
    }
    int rota[N], k = 0;
    for (int S = TODAS, v = ultimo; v != 0;) {
        rota[k++] = v;
        int u = pai[S][v];
        S &= ~(1 << (v - 1));
        v = u;
    }
    printf("Held-Karp: %d horas\n", melhor);
    printf("Rota: Manaus");
    for (int i = k - 1; i >= 0; i--) {
        printf(" > %s", cidade[rota[i]]);
    }
    printf(" > Manaus\n");
    bruta(1, 0, 0);
    printf("Força bruta: %d horas\n", bruta_melhor);
    return 0;
}
