// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2917 · ★★☆ · Contando as soluções de uma fórmula

#include <stdbool.h>
#include <stdio.h>

#define NV 5
#define NC 6

const int f[NC][3] = {{1, 2, 3}, {-1, -2, 4}, {2, -3, 5}, {-4, -5, 1}, {3, 4, -2}, {-1, -3, -5}};

bool satisfaz(const bool x[]) {
    for (int c = 0; c < NC; c++) {
        bool algum = false;
        for (int i = 0; i < 3; i++) {
            int l = f[c][i];
            if (l > 0 ? x[l] : !x[-l]) algum = true;
        }
        if (!algum) return false;
    }
    return true;
}

int main(void) {
    int total = 0;
    for (int m = 0; m < (1 << NV); m++) {
        bool x[NV + 1] = {false};
        for (int v = 1; v <= NV; v++) x[v] = (m >> (v - 1)) & 1;
        if (!satisfaz(x)) continue;
        total++;
        for (int v = 1; v <= NV; v++) printf("%d", x[v]);
        printf("\n");
    }
    printf("Total: %d de %d\n", total, 1 << NV);
    return 0;
}
