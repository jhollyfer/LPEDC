// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2610 · ★☆☆ · Quanto pesa a matriz

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t ns[] = {10, 100, 1000};
    for (int k = 0; k < 3; k++) {
        size_t n = ns[k];
        size_t bytes = n * n * sizeof(double);
        double *m = malloc(bytes);
        if (m == NULL) {
            return 1;
        }
        for (size_t i = 0; i < n * n; i++) {
            m[i] = 0.0;
        }
        printf("n = %4zu: %8zu bytes (%.2f MB)\n", n, bytes, bytes / 1048576.0);
        free(m);
    }
    return 0;
}
