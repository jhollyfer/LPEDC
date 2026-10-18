// A065 · Fibonacci sem recalcular: a recursão que carrega o par

#include <stdio.h>

long chamadas = 0;

// a e b são dois vizinhos da sequência; a cada chamada o par anda uma casa
long long fib_par(int n, long long a, long long b) {
    chamadas++;
    if (n == 0) {
        return a; // caso base: andou tudo, a é a resposta
    }
    return fib_par(n - 1, b, a + b); // UMA chamada só, não duas
}

long long fib(int n) {
    return fib_par(n, 0, 1); // começa no par (fib(0), fib(1))
}

int main(void) {
    for (int n = 10; n <= 30; n += 10) {
        chamadas = 0;
        long long resultado = fib(n);
        printf("fib(%d) = %lld, com %ld chamadas\n", n, resultado, chamadas);
    }

    chamadas = 0;
    long long grande = fib(90); // com duas chamadas por vez, não terminaria hoje
    printf("fib(90) = %lld, com %ld chamadas\n", grande, chamadas);
    return 0;
}
// Saída:
// fib(10) = 55, com 11 chamadas
// fib(20) = 6765, com 21 chamadas
// fib(30) = 832040, com 31 chamadas
// fib(90) = 2880067194370816120, com 91 chamadas
