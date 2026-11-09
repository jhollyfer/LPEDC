// Lista · Módulo 01 · Fundamentos de C
// Exercício P0123 · ★★★ · Quantos dias faltam para a prova

#include <stdio.h>

int main(void) {
    int dia1 = 15, mes1 = 8, ano1 = 2026;
    int a1 = (14 - mes1) / 12;
    int y1 = ano1 - a1;
    int m1 = mes1 + 12 * a1 - 3;
    long n1 = dia1 + (153 * m1 + 2) / 5 + 365L * y1 + y1 / 4 - y1 / 100 + y1 / 400;

    int dia2 = 27, mes2 = 11, ano2 = 2026;
    int a2 = (14 - mes2) / 12;
    int y2 = ano2 - a2;
    int m2 = mes2 + 12 * a2 - 3;
    long n2 = dia2 + (153 * m2 + 2) / 5 + 365L * y2 + y2 / 4 - y2 / 100 + y2 / 400;

    long dias = n2 - n1;

    printf("De %02d/%02d/%d a %02d/%02d/%d: %ld dias\n", dia1, mes1, ano1, dia2, mes2, ano2, dias);
    printf("São %ld semanas e %ld dias\n", dias / 7, dias % 7);
    return 0;
}
