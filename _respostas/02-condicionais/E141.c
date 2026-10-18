// 0024 · Juntando tudo: a conta de luz
// Exercício E141 · ★★☆

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
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        dias_do_mes = 31;
        break;
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
        dias_do_mes = 0; // mês inválido: nenhum dia serve
    }

    if (dia >= 1 && dia <= dias_do_mes) {
        printf("Data válida.\n");
    } else {
        printf("Data inválida.\n");
    }
    return 0;
}
