// Lista · Módulo 06 · Ponteiros
// Exercício P0602 · ★☆☆ · As leituras até o -1

#include <stdio.h>

int main(void) {
    int leituras[] = {312, 280, 455, 301, 298, -1};
    int *p = leituras;
    int soma = 0;

    while (*p != -1) {
        soma += *p;
        p++;
    }
    int n = (int) (p - leituras); // elementos entre o início e o -1

    printf("Leituras: %d\n", n);
    printf("Total: %d litros\n", soma);
    printf("Média: %.2f litros por dia\n", soma / (double) n);
    return 0;
}
