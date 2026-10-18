// A056 · É primo? Para no primeiro divisor

#include <stdio.h>

int main(void) {
    int n = 91;
    int divisor;
    int testes = 0;

    for (divisor = 2; divisor < n; divisor++) {
        testes++;
        if (n % divisor == 0) {
            break; // achou um divisor: não precisa testar o resto
        }
    }

    // por que o laço parou? pela condição ou pelo break?
    if (divisor == n) {
        printf("%d é primo (%d testes)\n", n, testes);
    } else {
        printf("%d = %d x %d, não é primo (%d testes)\n", n, divisor, n / divisor, testes);
    }

    // continue: só os números de 1 a 15 que não são múltiplos de 3
    for (int i = 1; i <= 15; i++) {
        if (i % 3 == 0) {
            continue; // pula o printf, mas o i++ do for ainda roda
        }
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
// Saída:
// 91 = 7 x 13, não é primo (6 testes)
// 1 2 4 5 7 8 10 11 13 14 
