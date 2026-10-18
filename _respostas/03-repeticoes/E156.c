// 0026 · Do-while
// Exercício E156 · ★★★

#include <stdio.h>

int main(void) {
    int mes, dia, dias_no_mes;

    do {
        printf("Mês: ");
        if (scanf("%d", &mes) != 1) {
            return 1;
        }
    } while (mes < 1 || mes > 12);

    switch (mes) {
    case 2:
        dias_no_mes = 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        dias_no_mes = 30;
        break;
    default:
        dias_no_mes = 31;
    }

    do {
        printf("Dia (1 a %d): ", dias_no_mes);
        if (scanf("%d", &dia) != 1) {
            return 1;
        }
    } while (dia < 1 || dia > dias_no_mes);

    printf("Consulta em %02d/%02d/2026\n", dia, mes);
    return 0;
}
