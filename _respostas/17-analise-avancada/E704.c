// 0118 · Juntando tudo
// Exercício E704 · ★☆☆

#include <math.h>
#include <stdio.h>

// tempo previsto em n1, a partir de t0 medido em n0
double prever(double t0, double n0, double n1, int quadratico) {
    if (quadratico) {
        return t0 * (n1 / n0) * (n1 / n0);
    }
    return t0 * (n1 * log2(n1)) / (n0 * log2(n0));
}

int main(void) {
    printf("insertion, 20 mil -> 100 mil: %10.4f s\n", prever(0.8, 20000, 100000, 1));
    printf("insertion, 20 mil -> 1 milhão: %9.4f s\n", prever(0.8, 20000, 1000000, 1));
    printf("merge,     20 mil -> 100 mil: %10.4f s\n", prever(0.004, 20000, 100000, 0));
    printf("merge,     20 mil -> 1 milhão: %9.4f s\n", prever(0.004, 20000, 1000000, 0));
    return 0;
}
