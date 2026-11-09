// 0171 · Com sinal e sem sinal
// Exercício E1021 · ★☆☆

#include <stdio.h>

int main(void) {
    unsigned char contador = 250;
    printf("contador:");
    for (int i = 0; i < 10; i++) {
        contador++;
        printf(" %d", contador);
    }
    printf("\n");

    unsigned char vidas = 2;
    printf("vidas:");
    for (int i = 0; i < 3; i++) {
        vidas--;
        printf(" %d", vidas);
    }
    printf("\n");
    return 0;
}
