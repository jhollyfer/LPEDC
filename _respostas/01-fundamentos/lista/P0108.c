// Lista · Módulo 01 · Fundamentos de C
// Exercício P0108 · ★☆☆ · O Pix do país inteiro

#include <limits.h>
#include <stdio.h>

int main(void) {
    long long pessoas = 160000000LL;
    long long total = pessoas * 25; // a conta acontece em long long

    printf("Maior int: %d\n", INT_MAX);
    printf("Total do dia: R$ %lld\n", total);
    printf("O total é %lld vez(es) o INT_MAX\n", total / INT_MAX);
    return 0;
}
