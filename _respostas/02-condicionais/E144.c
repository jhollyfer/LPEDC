// 0024 · Juntando tudo: a conta de luz
// Exercício E144 · ★★★

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int dia, mes, ano;
    printf("Data (dd/mm/aaaa): ");
    if (scanf("%d/%d/%d", &dia, &mes, &ano) != 3) {
        printf("Entrada inválida\n");
        return 1;
    }

    bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
    int dias_do_mes;
    switch (mes) {
    case 4:
    case 6:
    case 9:
    case 11:
        dias_do_mes = 30;
        break;
    case 2:
        dias_do_mes = bissexto ? 29 : 28;
        break;
    default:
        dias_do_mes = 31; // a data foi suposta válida
    }

    if (dia < dias_do_mes) {
        dia++;
    } else {
        dia = 1;
        if (mes == 12) {
            mes = 1;
            ano++;
        } else {
            mes++;
        }
    }
    printf("Dia seguinte: %02d/%02d/%d\n", dia, mes, ano);
    return 0;
}
