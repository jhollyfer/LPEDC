// 0114 · Recorrências e árvore de recursão
// Exercício E684 · ★★★

#include <stdio.h>

long chamadas = 0;

long fib(int n) {
    chamadas++;
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

// C(n) = C(n-1) + C(n-2) + 1, C(0) = C(1) = 1, calculada com um laço
long conta_chamadas(int n) {
    long anterior = 1, atual = 1; // C(0) e C(1)
    for (int i = 2; i <= n; i++) {
        long proximo = atual + anterior + 1;
        anterior = atual;
        atual = proximo;
    }
    return atual;
}

// F(n) com um laço, sem recursão
long fib_laco(int n) {
    long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        long t = a + b;
        a = b;
        b = t;
    }
    return a;
}

int main(void) {
    printf(" n  contadas    C(n)  2F(n+1)-1\n");
    for (int n = 5; n <= 25; n += 5) {
        chamadas = 0;
        fib(n);
        printf("%2d %9ld %7ld %10ld\n", n, chamadas, conta_chamadas(n), 2 * fib_laco(n + 1) - 1);
    }
    long c40 = conta_chamadas(40);
    long c39 = conta_chamadas(39);
    printf("C(40) = %ld\n", c40);
    printf("C(40) / C(39) = %.4f\n", (double)c40 / c39);
    return 0;
}
