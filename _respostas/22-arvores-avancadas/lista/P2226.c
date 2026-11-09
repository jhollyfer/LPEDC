// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2226 · ★★★ · Quantos metros acima?

#include <stdio.h>

#define N 7

int pai[N];
long dif[N]; // altitude(x) - altitude(pai[x])

int acha(int x) {
    if (pai[x] != x) {
        int p = pai[x];
        int r = acha(p);
        dif[x] += dif[p];
        pai[x] = r;
    }
    return pai[x];
}

// b está d metros acima de a
int mede(int a, int b, long d) {
    int ra = acha(a), rb = acha(b);
    if (ra == rb) {
        return dif[b] - dif[a] == d;
    }
    pai[rb] = ra;
    dif[rb] = dif[a] + d - dif[b];
    return 1;
}

int main(void) {
    const long med[7][3] = {{0, 1, 5}, {1, 2, 3}, {3, 4, -2}, {2, 3, 4}, {0, 4, 10}, {5, 6, 7}, {0, 2, 9}};
    const int perg[4][2] = {{0, 3}, {4, 1}, {2, 5}, {6, 5}};
    for (int i = 0; i < N; i++) {
        pai[i] = i;
        dif[i] = 0;
    }
    for (int i = 0; i < 7; i++) {
        int ok = mede((int)med[i][0], (int)med[i][1], med[i][2]);
        printf("Medição %ld %ld %ld: %s\n", med[i][0], med[i][1], med[i][2], ok ? "aceita" : "rejeitada (contradiz)");
    }
    for (int i = 0; i < 4; i++) {
        int a = perg[i][0], b = perg[i][1];
        if (acha(a) != acha(b)) {
            printf("%d -> %d: desconhecida\n", a, b);
        } else {
            printf("%d -> %d: %ld m\n", a, b, dif[b] - dif[a]);
        }
    }
    return 0;
}
