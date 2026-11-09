// Lista · Módulo 01 · Fundamentos de C
// Exercício P0116 · ★★☆ · O centavo que sumiu

#include <math.h>
#include <stdio.h>

int main(void) {
    double preco = 4.35;
    int cortado = (int)(preco * 100);         // 434: o cast só corta
    int centavos = (int)round(preco * 100);   // 435: arredonda e depois converte

    printf("Preço: R$ %.2f\n", preco);
    printf("Centavos com (int): %d\n", cortado);
    printf("Centavos com round: %d\n", centavos);
    return 0;
}
