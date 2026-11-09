// 0178 · Hash: divisão e multiplicação
// Exercício E1064 · ★☆☆

#include <math.h>
#include <stdio.h>

int mult(unsigned k, int m) {
    double A = (sqrt(5.0) - 1) / 2;
    double produto = k * A;
    double fracao = produto - floor(produto);
    return (int)(m * fracao);
}

int main(void) {
    for (unsigned k = 1; k <= 8; k++) {
        double produto = k * ((sqrt(5.0) - 1) / 2);
        printf("k = %u: k*A = %.4f | fração %.4f | balde %d\n", k, produto,
               produto - floor(produto), mult(k, 10));
    }
    return 0;
}
