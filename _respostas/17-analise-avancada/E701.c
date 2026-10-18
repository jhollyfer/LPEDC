// 0117 · Limite inferior da ordenação
// Exercício E701 · ★★★

#include <stdio.h>

int comparacoes = 0;

int menor(int a, int b) {
    comparacoes++;
    return a < b;
}

void monta(int r[], int a, int b, int c) {
    r[0] = a;
    r[1] = b;
    r[2] = c;
}

void podio(int x, int y, int z, int r[]) {
    if (menor(x, y)) {
        if (menor(y, z)) {
            monta(r, x, y, z);
        } else if (menor(x, z)) {
            monta(r, x, z, y);            // bug 1: era z x y
        } else {
            monta(r, z, x, y);
        }
    } else {
        if (menor(x, z)) {                // bug 2: menor(y, x) já se sabia
            monta(r, y, x, z);
        } else if (menor(y, z)) {
            monta(r, y, z, x);
        } else {
            monta(r, z, y, x);
        }
    }
}

int main(void) {
    int ordens[6][3] = {{10, 20, 30}, {10, 30, 20}, {20, 10, 30}, {20, 30, 10}, {30, 10, 20}, {30, 20, 10}};
    int pior = 0;
    for (int k = 0; k < 6; k++) {
        int r[3];
        comparacoes = 0;
        podio(ordens[k][0], ordens[k][1], ordens[k][2], r);
        int certo = r[0] == 10 && r[1] == 20 && r[2] == 30;
        printf("%d %d %d -> %d %d %d (%d comparações) %s\n", ordens[k][0], ordens[k][1], ordens[k][2],
               r[0], r[1], r[2], comparacoes, certo ? "ok" : "ERRADO");
        if (comparacoes > pior) {
            pior = comparacoes;
        }
    }
    printf("pior caso: %d comparações\n", pior);
    return 0;
}
