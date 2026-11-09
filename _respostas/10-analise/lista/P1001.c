// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1001 · ★☆☆ · Quantas vezes dá para dividir

#include <stdio.h>

int passos_metade(int n) {
    int passos = 0;
    while (n > 1) {
        n = n / 2;
        passos++;
    }
    return passos;
}

int passos_terco(int n) {
    int passos = 0;
    while (n > 1) {
        n = n / 3;
        passos++;
    }
    return passos;
}

int main(void) {
    int testes[4] = {10, 100, 1000, 1000000};
    printf("%8s %4s %4s\n", "n", "/2", "/3");
    for (int i = 0; i < 4; i++) {
        printf("%8d %4d %4d\n", testes[i], passos_metade(testes[i]), passos_terco(testes[i]));
    }
    return 0;
}
