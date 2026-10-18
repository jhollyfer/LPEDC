// 0033 · Funções
// Exercício E194 · ★☆☆

#include <stdio.h>

int total_segundos(int h, int m, int s);

int main(void) {
    printf("Ana: %d s\n", total_segundos(1, 30, 15));
    printf("Bia: %d s\n", total_segundos(1, 0, 0));
    printf("Caio: %d s\n", total_segundos(1, 23, 19));
    return 0;
}

int total_segundos(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}
