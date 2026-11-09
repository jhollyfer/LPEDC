// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2207 · ★☆☆ · As redes da comunidade

#include <stdio.h>

#define N 10

int pai[N], posto[N];
int componentes = N;

int acha(int x) {
    if (pai[x] != x) {
        pai[x] = acha(pai[x]);
    }
    return pai[x];
}

void une(int a, int b) {
    int ra = acha(a), rb = acha(b);
    if (ra == rb) {
        return;
    }
    if (posto[ra] < posto[rb]) {
        pai[ra] = rb;
    } else if (posto[ra] > posto[rb]) {
        pai[rb] = ra;
    } else {
        pai[rb] = ra;
        posto[ra]++;
    }
    componentes--;
}

int main(void) {
    for (int i = 0; i < N; i++) {
        pai[i] = i;
        posto[i] = 0;
    }
    const int en[8][2] = {{0, 1}, {2, 3}, {1, 4}, {5, 6}, {3, 7}, {4, 8}, {6, 9}, {0, 8}};
    for (int i = 0; i < 8; i++) {
        une(en[i][0], en[i][1]);
    }
    printf("Redes: %d\n", componentes);
    for (int r = 0; r < N; r++) {
        if (acha(r) != r) {
            continue;
        }
        printf("  {");
        for (int x = 0; x < N; x++) {
            if (acha(x) == r) {
                printf(" %d", x);
            }
        }
        printf(" }\n");
    }
    return 0;
}
