// A075 · Fibonacci: bonito e caro

#include <stdio.h>

long chamadas = 0; // conta quantas vezes fib foi chamada

int fib(int n) {
    chamadas++;
    if (n < 2) {
        return n; // fib(0) = 0 e fib(1) = 1
    }
    return fib(n - 1) + fib(n - 2); // duas chamadas por vez
}

int main(void) {
    for (int n = 5; n <= 30; n += 5) {
        chamadas = 0;
        int resultado = fib(n);
        printf("fib(%d) = %d, com %ld chamadas\n", n, resultado, chamadas);
    }
    return 0;
}
// Saída:
// fib(5) = 5, com 15 chamadas
// fib(10) = 55, com 177 chamadas
// fib(15) = 610, com 1973 chamadas
// fib(20) = 6765, com 21891 chamadas
// fib(25) = 75025, com 242785 chamadas
// fib(30) = 832040, com 2692537 chamadas
