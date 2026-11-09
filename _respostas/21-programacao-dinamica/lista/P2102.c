// Lista · Módulo 21 · Programação dinâmica
// Exercício P2102 · ★☆☆ · A escada com degraus quebrados

#include <stdbool.h>
#include <stdio.h>

#define N 12

int main(void) {
    bool quebrado[N + 1] = {false};
    quebrado[4] = quebrado[7] = true;
    long formas[N + 1];
    formas[0] = 1;
    for (int i = 1; i <= N; i++) {
        if (quebrado[i]) {
            formas[i] = 0;
            continue;
        }
        formas[i] = formas[i - 1];
        if (i >= 2) {
            formas[i] += formas[i - 2];
        }
    }
    for (int i = 0; i <= N; i++) {
        printf("degrau %2d: %ld\n", i, formas[i]);
    }
    printf("Jeitos de chegar ao topo: %ld\n", formas[N]);
    return 0;
}
