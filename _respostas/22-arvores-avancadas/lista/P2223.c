// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2223 · ★★★ · As estradas que a cheia fecha

#include <stdio.h>

#define N 6
#define E 7

int pai[N], posto[N];

int acha(int x) {
    if (pai[x] != x) {
        pai[x] = acha(pai[x]);
    }
    return pai[x];
}

int une(int a, int b) {
    int ra = acha(a), rb = acha(b);
    if (ra == rb) {
        return 0;
    }
    if (posto[ra] < posto[rb]) {
        int t = ra;
        ra = rb;
        rb = t;
    }
    pai[rb] = ra;
    if (posto[ra] == posto[rb]) {
        posto[ra]++;
    }
    return 1;
}

int main(void) {
    const int est[E][2] = {{0, 1}, {2, 3}, {1, 2}, {3, 4}, {4, 5}, {0, 5}, {2, 4}};
    for (int i = 0; i < N; i++) {
        pai[i] = i;
        posto[i] = 0;
    }
    int grupos[E], comp = N;
    for (int k = E - 1; k >= 0; k--) {
        grupos[k] = comp;
        comp -= une(est[k][0], est[k][1]);
    }
    for (int k = 0; k < E; k++) {
        printf("Fecha %d-%d: %d grupo(s)\n", est[k][0], est[k][1], grupos[k]);
    }
    return 0;
}
