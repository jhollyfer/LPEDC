// Lista · Módulo 16 · Grafos
// Exercício P1622 · ★★★ · O cavalo do torneio de xadrez da escola

#include <stdio.h>

#define N 8

int main(void) {
    int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dl[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dist[N * N], pai[N * N], fila[N * N], ini = 0, fim = 0;
    for (int x = 0; x < N * N; x++) dist[x] = -1;
    int s = 0, t = 7 * N + 7; // a1 e h8
    dist[s] = 0;
    pai[s] = -1;
    fila[fim++] = s;
    while (ini < fim) {
        int u = fila[ini++], l = u / N, c = u % N;
        for (int k = 0; k < 8; k++) {
            int nl = l + dl[k], nc = c + dc[k];
            if (nl < 0 || nl >= N || nc < 0 || nc >= N) continue; // saiu do tabuleiro
            int v = nl * N + nc;
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            pai[v] = u;
            fila[fim++] = v;
        }
    }

    int maxd = 0, quantas = 0;
    for (int l = N - 1; l >= 0; l--) {
        printf("%d ", l + 1);
        for (int c = 0; c < N; c++) {
            int d = dist[l * N + c];
            printf(" %d", d);
            if (d > maxd) {
                maxd = d;
                quantas = 0;
            }
            if (d == maxd) quantas++;
        }
        printf("\n");
    }
    printf("   a b c d e f g h\n");
    printf("Distância máxima: %d lances (%d casa%s)\n", maxd, quantas, quantas > 1 ? "s" : "");

    int cam[N * N], n = 0;
    for (int x = t; x != -1; x = pai[x]) cam[n++] = x;
    printf("a1 até h8 em %d lances:", dist[t]);
    for (int i = n - 1; i >= 0; i--) printf(" %c%c", 'a' + cam[i] % N, '1' + cam[i] / N);
    printf("\n");
    return 0;
}
