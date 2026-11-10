// 0034 · Módulos: .h, .c e compilação separada
// Exercício E202 · ★★☆

#include <stdio.h>

// "desconto.h"
double aplicar_desconto(double preco, double percentual);

int main(void) {
    printf("Tênis: R$ %.2f\n", aplicar_desconto(299.90, 20));
    return 0;
}

// "desconto.c"
double aplicar_desconto(double preco, double percentual) {
    return preco - preco * percentual / 100;
}
