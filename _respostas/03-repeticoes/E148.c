// 0025 · While
// Exercício E148 · ★★☆

#include <stdio.h>

int main(void) {
    double saldo = 1000.0;
    int meses = 0;

    while (saldo <= 1500.0) {
        saldo = saldo * 1.01;
        meses++;
    }
    printf("Passou de R$ 1500.00 em %d meses.\n", meses);
    printf("Saldo: R$ %.2f\n", saldo);
    return 0;
}
