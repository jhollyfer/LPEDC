// Lista · Módulo 03 · Laços
// Exercício P0321 · ★★★ · O calendário de qualquer mês

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int mes, ano;

    do {
        printf("Mês e ano: ");
        if (scanf("%d %d", &mes, &ano) != 2) {
            return 1;
        }
    } while (mes < 1 || mes > 12);

    bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
    int dias;
    switch (mes) {
        case 4:
        case 6:
        case 9:
        case 11:
            dias = 30;
            break;
        case 2:
            dias = bissexto ? 29 : 28;
            break;
        default:
            dias = 31;
            break;
    }

    int a = (14 - mes) / 12;
    int y = ano - a;
    int m = mes + 12 * a - 2;
    int primeiro = (1 + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;

    printf("  D  S  T  Q  Q  S  S\n");
    for (int i = 0; i < primeiro; i++) {
        printf("   ");
    }
    int fins = 0;
    for (int dia = 1; dia <= dias; dia++) {
        printf("%3d", dia);
        int semana = (primeiro + dia - 1) % 7;
        if (semana == 0 || semana == 6) {
            fins++;
        }
        if ((primeiro + dia) % 7 == 0) {
            printf("\n");
        }
    }
    if ((primeiro + dias) % 7 != 0) {
        printf("\n");
    }
    printf("Fins de semana: %d dias\n", fins);
    return 0;
}
