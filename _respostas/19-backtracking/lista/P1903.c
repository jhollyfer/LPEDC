// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1903 · ★☆☆ · Luzes que não ficam lado a lado

#include <stdio.h>

#define N 5

char luz[N + 1];
int total = 0;

void monta(int p) {
    if (p == N) {
        total++;
        printf("%s\n", luz);
        return;
    }
    luz[p] = '0';
    monta(p + 1);
    if (p == 0 || luz[p - 1] == '0') {
        luz[p] = '1';
        monta(p + 1);
    }
}

int main(void) {
    luz[N] = '\0';
    monta(0);
    printf("Total: %d configurações\n", total);
    return 0;
}
