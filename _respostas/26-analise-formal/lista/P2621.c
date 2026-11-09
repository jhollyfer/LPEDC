// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2621 · ★★★ · As fatias que deram zero

#include <stdio.h>

long passos = 0;

void confere(int n) {
    for (int i = 0; i < n; i++) {
        passos += 3;
        for (int j = i; j < n; j++) {
            passos++;
        }
    }
}

int main(void) {
    double c1 = 1e9, c2 = 0;
    for (long n = 10; n <= 2000; n++) {
        passos = 0;
        confere((int)n);
        double r = (double)passos / ((double)n * n);  // antes: divisão inteira
        if (r < c1) c1 = r;
        if (r > c2) c2 = r;
    }
    printf("c1 = %.4f, c2 = %.4f\n", c1, c2);
    return 0;
}
