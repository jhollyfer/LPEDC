// Lista · Módulo 04 · Funções e modularização
// Exercício P0403 · ★☆☆ · As ordens de largada

#include <stdio.h>

long long fatorial(int n) {
    if (n == 0) {
        return 1; // caso base
    }
    return n * fatorial(n - 1); // caso recursivo
}

int main(void) {
    printf("5 carros: %lld maneiras\n", fatorial(5));
    printf("10 carros: %lld maneiras\n", fatorial(10));
    printf("15 carros: %lld maneiras\n", fatorial(15));
    return 0;
}
