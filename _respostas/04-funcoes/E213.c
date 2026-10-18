// 0036 · Juntando tudo: o caixa da lanchonete
// Exercício E213 · ★★☆

#include <stdbool.h>
#include <stdio.h>

bool eh_bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
}

int dias_no_mes(int mes, int ano) {
    switch (mes) {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return eh_bissexto(ano) ? 29 : 28;
    default:
        return 31;
    }
}

int dia_do_ano(int dia, int mes, int ano) {
    int total = dia;
    for (int m = 1; m < mes; m++) {
        total += dias_no_mes(m, ano);
    }
    return total;
}

void mostrar(int dia, int mes, int ano) {
    printf("%02d/%02d/%d: ", dia, mes, ano);
    if (mes < 1 || mes > 12 || dia < 1 || dia > dias_no_mes(mes, ano)) {
        printf("data inválida\n");
        return;
    }
    printf("dia %d de %d\n", dia_do_ano(dia, mes, ano), eh_bissexto(ano) ? 366 : 365);
}

int main(void) {
    mostrar(18, 10, 2026);
    mostrar(1, 3, 2024);
    mostrar(31, 12, 2024);
    mostrar(29, 2, 2023);
    return 0;
}
