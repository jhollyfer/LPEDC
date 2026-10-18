// 0071 · Eficiência: contar passos
// Exercício E426 · ★★★

#include <stdio.h>

long chamadas = 0;
long somas = 0;

long fib_rec(int n) {
    chamadas++;
    if (n < 2) {
        return n;
    }
    return fib_rec(n - 1) + fib_rec(n - 2);
}

long fib_it(int n) {
    if (n < 2) {
        return n;
    }
    long anterior = 0, atual = 1;
    for (int i = 2; i <= n; i++) {
        long proximo = anterior + atual;
        somas++;
        anterior = atual;
        atual = proximo;
    }
    return atual;
}

int main(void) {
    int valores[3] = {10, 20, 30};

    printf("%2s %7s %9s %6s\n", "n", "fib", "chamadas", "somas");
    for (int k = 0; k < 3; k++) {
        int n = valores[k];
        chamadas = 0;
        somas = 0;
        long a = fib_rec(n);
        long b = fib_it(n);
        if (a != b) {
            printf("as duas versões discordam!\n");
        }
        printf("%2d %7ld %9ld %6ld\n", n, a, chamadas, somas);
    }

    printf("\n");
    chamadas = 0;
    fib_rec(19);
    long anterior = chamadas;
    for (int n = 20; n <= 25; n++) {
        chamadas = 0;
        fib_rec(n);
        printf("n = %d: %6ld chamadas, razão %.3f\n", n, chamadas,
               (double)chamadas / anterior);
        anterior = chamadas;
    }
    return 0;
}
