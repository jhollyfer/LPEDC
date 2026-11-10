// 0033 · Recursão na prática: Fibonacci, Hanói e Euclides
// Exercício E195 · ★★☆

#include <stdio.h>

int fib_rapido(int n) {
    if (n == 0) {
        return 0;
    }
    int anterior = 0;
    int atual = 1;
    for (int i = 2; i <= n; i++) {
        int proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }
    return atual;
}

int main(void) {
    printf("fib(10) = %d\n", fib_rapido(10));
    printf("fib(40) = %d\n", fib_rapido(40));
    printf("fib(46) = %d\n", fib_rapido(46));
    return 0;
}
