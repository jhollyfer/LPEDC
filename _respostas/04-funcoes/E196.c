// 0033 · Recursão na prática: Fibonacci, Hanói e Euclides
// Exercício E196 · ★★☆
//
// Resposta: a) fib(6) = 8. b) 25 chamadas: Chamadas(4) = 1 + 5 + 3 = 9 e
// Chamadas(6) = 1 + 15 + 9 = 25. c) fib(2) é calculado 5 vezes (3 dentro de
// fib(5) e 2 dentro de fib(4)). d) 6 quadros de fib: fib(6) até fib(1).

#include <stdio.h>

long chamadas = 0;
long chamadas_fib2 = 0;

int fib(int n) {
    chamadas++;
    if (n == 2) {
        chamadas_fib2++;
    }
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main(void) {
    int resultado = fib(6);
    printf("fib(6) = %d, %ld chamadas, fib(2) calculado %ld vezes\n",
           resultado, chamadas, chamadas_fib2);
    return 0;
}
