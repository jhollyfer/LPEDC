// 0011 · Juntando tudo
// Exercício E064 · ★★☆

#include <stdio.h>
#include <math.h>

int main(void) {
    double valor = 1299.00;
    double taxa = 0.0199;
    int n = 12;

    double parcela = valor * taxa / (1 - pow(1 + taxa, -n)); // 122.7577...
    parcela = round(parcela * 100) / 100;                     // 122.76

    double total = parcela * n;
    printf("%dx de R$ %.2f\n", n, parcela);
    printf("Total: R$ %.2f\n", total);
    printf("Juros: R$ %.2f\n", total - valor);
    return 0;
}
