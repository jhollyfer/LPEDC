// Lista · Módulo 01 · Fundamentos de C
// Exercício P0129 · ★★★ · A data da Páscoa

#include <stdio.h>

int main(void) {
    int ano = 2026;
    int a = ano % 19, b = ano / 100, c = ano % 100;
    int d = b / 4, e = b % 4;
    int f = (b + 8) / 25;
    int g = (b - f + 1) / 3;
    int h = (19 * a + b - d - g + 15) % 30;
    int i = c / 4, k = c % 4;
    int l = (32 + 2 * e + 2 * i - h - k) % 7;
    int m = (a + 11 * h + 22 * l) / 451;
    int mes = (h + l - 7 * m + 114) / 31;
    int dia = (h + l - 7 * m + 114) % 31 + 1;
    printf("Páscoa de %d: %02d/%02d\n", ano, dia, mes);

    ano = 2027; // mesma receita, outro ano
    a = ano % 19; b = ano / 100; c = ano % 100;
    d = b / 4; e = b % 4;
    f = (b + 8) / 25;
    g = (b - f + 1) / 3;
    h = (19 * a + b - d - g + 15) % 30;
    i = c / 4; k = c % 4;
    l = (32 + 2 * e + 2 * i - h - k) % 7;
    m = (a + 11 * h + 22 * l) / 451;
    mes = (h + l - 7 * m + 114) / 31;
    dia = (h + l - 7 * m + 114) % 31 + 1;
    printf("Páscoa de %d: %02d/%02d\n", ano, dia, mes);
    return 0;
}
