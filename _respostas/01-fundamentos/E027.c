// 0005 · printf
// Exercício E027 · ★★☆

#include <stdio.h>

int main(void) {
    double gasolina = 6.29;
    double etanol = 4.19;
    double diesel = 6.09;
    double gnv = 4.99;

    // "Combustível" tem 11 letras e 12 bytes (o í ocupa 2): por isso %-15s
    printf("%-15s%s\n", "Combustível", "Preço/L");
    printf("======================\n");
    printf("%-14sR$ %.2f\n", "Gasolina", gasolina);
    printf("%-14sR$ %.2f\n", "Etanol", etanol);
    printf("%-14sR$ %.2f\n", "Diesel S10", diesel);
    printf("%-14sR$ %.2f\n", "GNV", gnv);
    return 0;
}
