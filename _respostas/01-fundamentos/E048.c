// 0008 · Conversão e cast
// Exercício E048 · ★★★

#include <stdio.h>

int main(void) {
    char letra = 'g';
    double x = 3.7, y = 3.7;

    printf("Letra: %c (código %d)\n", letra, letra);
    printf("Maiúscula: %c (código %d)\n", letra - 'a' + 'A', letra - 'a' + 'A');
    printf("Posição no alfabeto: %d\n", letra - 'a' + 1);
    printf("Três adiante: %c\n", letra + 3);
    printf("Somando e cortando: %d; cortando e somando: %d\n",
           (int) (x + y), (int) x + (int) y);
    return 0;
}
