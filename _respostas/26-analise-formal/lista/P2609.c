// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2609 · ★☆☆ · Dobrou n, multiplicou por oito

#include <stdio.h>

long passos = 0;

void trios_de_cores(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                passos++;
            }
        }
    }
}

int main(void) {
    long anterior = 0;
    for (int n = 10; n <= 80; n *= 2) {
        passos = 0;
        trios_de_cores(n);
        if (anterior == 0) {
            printf("n = %2d: %6ld passos\n", n, passos);
        } else {
            printf("n = %2d: %6ld passos, razão %.1f\n", n, passos, (double)passos / anterior);
        }
        anterior = passos;
    }
    return 0;
}
