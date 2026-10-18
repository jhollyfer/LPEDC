// 0118 · Juntando tudo
// Exercício E703 · ★☆☆

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ordena.h"

#define MAX 8000

int original[MAX], v[MAX];

double cronometra(void (*ordena)(int[], int), int n) {
    memcpy(v, original, n * sizeof v[0]);
    clock_t ini = clock();
    ordena(v, n);
    return 1000.0 * (clock() - ini) / CLOCKS_PER_SEC;
}

int main(void) {
    unsigned s = 1;
    for (int i = 0; i < MAX; i++) {
        s = s * 1103515245u + 12345u;
        original[i] = (int)(s >> 8);
    }
    double ant_ins = 0, ant_mer = 0;
    printf("    n   insertion (ms)        merge (ms)\n");
    for (int n = 1000; n <= MAX; n *= 2) {
        double ti = cronometra(ord_insertion, n);
        double tm = cronometra(ord_merge, n);
        printf("%5d %9.2f", n, ti);
        if (ant_ins > 0) {
            printf("  x%.1f", ti / ant_ins);
        } else {
            printf("      ");
        }
        printf(" %10.3f", tm);
        if (ant_mer > 0) {
            printf("  x%.1f", tm / ant_mer);
        }
        printf("\n");
        ant_ins = ti;
        ant_mer = tm;
    }
    return 0;
}
