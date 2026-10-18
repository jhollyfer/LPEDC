// 0037 · Vetores
// Exercício E222 · ★★★

#include <stdio.h>
#include <stdbool.h>

#define N 50

int main(void) {
    bool primo[N + 1];

    for (int i = 0; i <= N; i++) {
        primo[i] = true;
    }
    primo[0] = false;
    primo[1] = false;

    for (int p = 2; p * p <= N; p++) {
        if (primo[p]) {
            for (int m = p * p; m <= N; m += p) {
                primo[m] = false;
            }
        }
    }

    int total = 0;
    for (int i = 2; i <= N; i++) {
        if (primo[i]) {
            printf(total == 0 ? "%d" : " %d", i);
            total++;
        }
    }
    printf("\n%d primos até %d\n", total, N);
    return 0;
}
