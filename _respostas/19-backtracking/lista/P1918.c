// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1918 · ★★☆ · A ordem das quadrilhas

#include <stdbool.h>
#include <stdio.h>

#define N 5

char ordem[N + 1];
bool usado[N];
int total = 0;

bool pode(int p, int q) {
    char x = (char)('A' + q);
    if (x == 'B' && !usado[0]) {
        return false;
    }
    if (p > 0) {
        char ant = ordem[p - 1];
        if ((x == 'C' && ant == 'D') || (x == 'D' && ant == 'C')) {
            return false;
        }
    }
    return true;
}

void monta(int p) {
    if (p == N) {
        total++;
        if (total <= 5) {
            printf("%s\n", ordem);
        }
        return;
    }
    for (int q = 0; q < N; q++) {
        if (usado[q] || !pode(p, q)) {
            continue;
        }
        usado[q] = true;
        ordem[p] = (char)('A' + q);
        monta(p + 1);
        usado[q] = false;
    }
}

int main(void) {
    ordem[N] = '\0';
    monta(0);
    printf("Total: %d ordens\n", total);
    return 0;
}
