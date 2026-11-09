// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2208 · ★☆☆ · A torre que o posto não deixa crescer

#include <stdio.h>

#define N 16

int acha(const int pai[], int x) {
    while (pai[x] != x) {
        x = pai[x];
    }
    return x;
}

void une_ingenuo(int pai[], int a, int b) {
    int ra = acha(pai, a), rb = acha(pai, b);
    if (ra != rb) {
        pai[ra] = rb;
    }
}

void une_posto(int pai[], int posto[], int a, int b) {
    int ra = acha(pai, a), rb = acha(pai, b);
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
}

int profundidade(const int pai[], int x) {
    int d = 0;
    while (pai[x] != x) {
        x = pai[x];
        d++;
    }
    return d;
}

int maxima(const int pai[]) {
    int m = 0;
    for (int i = 0; i < N; i++) {
        int d = profundidade(pai, i);
        if (d > m) {
            m = d;
        }
    }
    return m;
}

int main(void) {
    int pai[N];
    for (int i = 0; i < N; i++) {
        pai[i] = i;
    }
    for (int i = 0; i + 1 < N; i++) {
        une_ingenuo(pai, i, i + 1);
    }
    printf("Sem posto: profundidade máxima %d\n", maxima(pai));
    int pai2[N], posto[N];
    for (int i = 0; i < N; i++) {
        pai2[i] = i;
        posto[i] = 0;
    }
    for (int i = 0; i + 1 < N; i++) {
        une_posto(pai2, posto, i, i + 1);
    }
    printf("Com posto: profundidade máxima %d\n", maxima(pai2));
    return 0;
}
