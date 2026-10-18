// 0131 · Divisão e conquista
// Exercício E782 · ★☆☆

#include <stdio.h>

static int mult = 0;

// x elevado a n (n >= 0), cortando o expoente ao meio
double potencia_d(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    double metade = potencia_d(x, n / 2);
    if (n % 2 == 0) {
        mult += 1;
        return metade * metade;
    }
    mult += 2;
    return metade * metade * x;
}

int main(void) {
    double inicial = 1000.0; // R$ aplicados
    double taxa = 0.01;      // 1% ao mês
    int meses = 360;         // 30 anos

    double final = inicial * potencia_d(1.0 + taxa, meses);
    printf("Depois de %d meses: R$ %.2f\n", meses, final);
    printf("Multiplicações: %d\n", mult);
    return 0;
}
