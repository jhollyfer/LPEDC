// Lista · Módulo 15 · Tabelas hash
// Exercício P1510 · ★☆☆ · O método da multiplicação

#include <stdio.h>

#define M 16

int h_mult(int k) {
    const double A = 0.6180339887; // (raiz de 5 - 1) / 2, a sugestão de Knuth
    double produto = k * A;
    double fracao = produto - (long)produto; // k · A mod 1
    return (int)(M * fracao);
}

int main(void) {
    int codigos[] = {100, 101, 102, 103, 200, 300, 1000, 1024};
    for (int i = 0; i < 8; i++) {
        printf("%4d: divisão %2d, multiplicação %2d\n", codigos[i], codigos[i] % M, h_mult(codigos[i]));
    }
    return 0;
}
