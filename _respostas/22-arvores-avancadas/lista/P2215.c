// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2215 · ★★☆ · Amizades e perguntas no aplicativo

#include <stdio.h>

#define N 8
#define OPS 12

typedef struct {
    char tipo;
    int a, b;
} Op;

int pai[N], posto[N];

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
        int t = ra;
        ra = rb;
        rb = t;
    }
    pai[rb] = ra;
    if (posto[ra] == posto[rb]) {
        posto[ra]++;
    }
}

int main(void) {
    const Op op[OPS] = {{'U', 0, 1}, {'U', 2, 3}, {'P', 0, 3}, {'U', 1, 2}, {'P', 0, 3}, {'U', 4, 5},
                        {'P', 3, 5}, {'U', 6, 7}, {'U', 5, 6}, {'P', 4, 7}, {'U', 3, 4}, {'P', 0, 7}};
    for (int i = 0; i < N; i++) {
        pai[i] = i;
        posto[i] = 0;
    }
    for (int i = 0; i < OPS; i++) {
        if (op[i].tipo == 'U') {
            une(op[i].a, op[i].b);
        } else {
            printf("%d e %d: %s\n", op[i].a, op[i].b, acha(op[i].a) == acha(op[i].b) ? "sim" : "não");
        }
    }
    return 0;
}
