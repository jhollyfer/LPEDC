// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1712 · ★★☆ · Três funções, três casos, três fórmulas fechadas

#include <stdio.h>

long custo;

void quatro(int n) {
    if (n == 1) {
        custo++;
        return;
    }
    for (int i = 0; i < n; i++) custo++; // trabalho da chamada
    for (int k = 0; k < 4; k++) quatro(n / 2);
}

void duas(int n) {
    if (n == 1) {
        custo++;
        return;
    }
    for (int i = 0; i < n; i++) custo++;
    for (int k = 0; k < 2; k++) duas(n / 2);
}

void uma(int n) {
    if (n == 1) {
        custo++;
        return;
    }
    for (int i = 0; i < n; i++) custo++;
    uma(n / 2);
}

int main(void) {
    printf("   n    quatro   2n²-n   duas  nlgn+n   uma  2n-1\n");
    for (int k = 0; k <= 10; k++) {
        long n = 1L << k;
        custo = 0;
        quatro((int)n);
        long c4 = custo;
        custo = 0;
        duas((int)n);
        long c2 = custo;
        custo = 0;
        uma((int)n);
        printf("%4ld %9ld %7ld %6ld %7ld %5ld %5ld\n", n, c4, 2 * n * n - n, c2, n * k + n, custo, 2 * n - 1);
    }
    return 0;
}
