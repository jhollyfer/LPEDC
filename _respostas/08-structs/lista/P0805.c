// Lista · Módulo 08 · Tipos compostos
// Exercício P0805 · ★☆☆ · Quantos dias tem o mês

#include <stdio.h>
#include <stdbool.h>

typedef enum { JAN = 1, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ } Mes;

bool bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
}

int dias_no_mes(Mes m, int ano) {
    switch (m) {
    case FEV:
        return bissexto(ano) ? 29 : 28;
    case ABR: case JUN: case SET: case NOV:
        return 30;
    default:
        return 31;
    }
}

int main(void) {
    const char *nomes[12] = {"jan", "fev", "mar", "abr", "mai", "jun",
                             "jul", "ago", "set", "out", "nov", "dez"};
    int anos[4] = {2024, 2026, 1900, 2000};

    for (int i = 0; i < 4; i++) {
        printf("%s/%d: %d dias\n", nomes[FEV - 1], anos[i], dias_no_mes(FEV, anos[i]));
    }
    int total = 0;
    for (Mes m = JAN; m <= DEZ; m++) {
        total += dias_no_mes(m, 2026);
    }
    printf("2026: %d dias\n", total);
    return 0;
}
