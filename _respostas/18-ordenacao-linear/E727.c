// 0122 · Bucket sort
// Exercício E727 · ★☆☆

#include <stdio.h>

// balde de x para valores de 0 a max, com nb baldes de mesma largura;
// o próprio max vai para o último balde
int balde_de(double x, double max, int nb) {
    int b = (int) (x / max * nb);
    if (b >= nb) {
        b = nb - 1;
    }
    return b;
}

int main(void) {
    double precos[] = {12.50, 49.99, 50.00, 0.00, 10.00, 37.20, 9.99};
    for (int i = 0; i < 7; i++) {
        printf("R$ %5.2f -> balde %d\n", precos[i], balde_de(precos[i], 50.0, 5));
    }
    return 0;
}
