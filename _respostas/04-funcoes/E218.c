// 0037 · Recursão
// Exercício E218 · ★☆☆

#include <stdio.h>

int potencia(int base, int expoente) {
    if (expoente == 0) {
        return 1;
    }
    return base * potencia(base, expoente - 1);
}

int main(void) {
    printf("2^10 = %d\n", potencia(2, 10));
    printf("3^4 = %d\n", potencia(3, 4));
    printf("7^0 = %d\n", potencia(7, 0));
    return 0;
}
