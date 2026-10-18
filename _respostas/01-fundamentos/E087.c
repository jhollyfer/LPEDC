// 0015 · math.h
// Exercício E087 · ★★☆

#include <stdio.h>
#include <math.h>

#define COBRE_POR_LATA 25.0 // m²
#define PRECO_LATA 89.90

int main(void) {
    int paredes = 3, demaos = 2;
    double largura = 4.0, altura = 2.7;

    double area = paredes * largura * altura * demaos;
    double latas = area / COBRE_POR_LATA;
    double comprar = ceil(latas);

    printf("Área com 2 demãos: %.2f m²\n", area);
    printf("Latas: %.2f -> comprar %.0f\n", latas, comprar);
    printf("Total: R$ %.2f\n", comprar * PRECO_LATA);
    return 0;
}
