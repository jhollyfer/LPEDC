// 0033 · Recursão na prática: Fibonacci, Hanói e Euclides
// Exercício E196 · ★★☆

#include <stdio.h>

long chamadas = 0;
int repetidas = 0;
int altura = 0;
int maior_altura = 0;

int fib(int n) {
    chamadas++;
    altura++;
    if (altura > maior_altura) {
        maior_altura = altura;
    }
    if (n == 2) {
        repetidas++;
    }
    if (n < 2) {
        altura--;
        return n;
    }
    int r = fib(n - 1) + fib(n - 2);
    altura--;
    return r;
}

int main(void) {
    int resultado = fib(6);
    printf("fib(6) = %d\n", resultado);
    printf("chamadas: %ld\n", chamadas);
    printf("fib(2) calculado %d vezes\n", repetidas);
    printf("maior altura: %d\n", maior_altura);
    return 0;
}
