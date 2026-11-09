// 0166 · O, Ω e Θ de verdade
// Exercício E996 · ★★★

#include <stdio.h>

long passos = 0;

// confere cada par de clientes da fila uma vez, e cada cliente sozinho
void confere_pares(int n) {
    for (int i = 0; i < n; i++) {
        passos++;                        // o cliente sozinho
        for (int j = i + 1; j < n; j++) {
            passos++;                    // o par (i, j)
        }
    }
}

int main(void) {
    double c1 = 1e9, c2 = 0;
    for (int n = 10; n <= 2000; n++) {
        passos = 0;
        confere_pares(n);
        double r = (double)passos / ((double)n * n);
        if (r < c1) c1 = r;
        if (r > c2) c2 = r;
    }
    printf("de n = 10 a 2000: c1 = %.4f, c2 = %.4f\n", c1, c2);

    passos = 0;
    confere_pares(1000);
    printf("n = 1000: %ld passos, n(n+1)/2 = %ld\n", passos, 1000L * 1001 / 2);
    printf("f(n) = Θ(n²) com c1 = 0.5, c2 = 0.55 e n0 = 10\n");
    return 0;
}
