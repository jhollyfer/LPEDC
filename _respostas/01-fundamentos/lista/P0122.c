// Lista · Módulo 01 · Fundamentos de C
// Exercício P0122 · ★★★ · Em que dia da semana cai a prova

#include <stdio.h>

int main(void) {
    int dia1 = 27, mes1 = 11, ano1 = 2026;
    int a1 = (14 - mes1) / 12;
    int y1 = ano1 - a1;
    int m1 = mes1 + 12 * a1 - 2;
    int semana1 = (dia1 + y1 + y1 / 4 - y1 / 100 + y1 / 400 + 31 * m1 / 12) % 7;

    int dia2 = 25, mes2 = 12, ano2 = 2026;
    int a2 = (14 - mes2) / 12;
    int y2 = ano2 - a2;
    int m2 = mes2 + 12 * a2 - 2;
    int semana2 = (dia2 + y2 + y2 / 4 - y2 / 100 + y2 / 400 + 31 * m2 / 12) % 7;

    printf("%02d/%02d/%d -> dia %d da semana (0 = domingo)\n", dia1, mes1, ano1, semana1);
    printf("%02d/%02d/%d -> dia %d da semana (0 = domingo)\n", dia2, mes2, ano2, semana2);
    return 0;
}
