// Lista · Módulo 01 · Fundamentos de C
// Exercício P0109 · ★☆☆ · Quadro de partidas da rodoviária

#include <stdio.h>

int main(void) {
    int h1 = 9, m1 = 5;
    int h2 = 13, m2 = 40;
    int h3 = 22, m3 = 0;

    printf("%-12sHora   Preço\n", "Destino");
    printf("%-12s%02d:%02d %7.2f\n", "Manacapuru", h1, m1, 25.50);
    printf("%-12s%02d:%02d %7.2f\n", "Iranduba", h2, m2, 9.80);
    printf("%-12s%02d:%02d %7.2f\n", "Presidente", h3, m3, 112.00);
    return 0;
}
