// 0033 · Recursão na prática: Fibonacci, Hanói e Euclides
// Exercício E195 · ★★☆
//
// O fib recursivo leva alguns segundos para fib(40) (mais de 300 milhões de
// chamadas); o laço responde na hora. Ele fica comentado no fim do main para
// a resposta rodar rápido.

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

int fib(int n) {
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main(void) {
    printf("fib(10) = %d\n", fib_rapido(10));
    printf("fib(40) = %d\n", fib_rapido(40));
    printf("fib(46) = %d\n", fib_rapido(46));
    printf("recursivo: fib(25) = %d\n", fib(25));
    // printf("recursivo: fib(40) = %d\n", fib(40)); // tire o comentário e sinta a espera
    return 0;
}
