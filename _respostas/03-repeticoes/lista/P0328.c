// Lista · Módulo 03 · Laços
// Exercício P0328 · ★★★ · As datas palíndromas do século

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int total = 0;

    for (int ano = 2000; ano <= 2099; ano++) {
        int n = ano, inverso = 0;
        for (int k = 0; k < 4; k++) {
            inverso = inverso * 10 + n % 10;
            n /= 10;
        }
        int dia = inverso / 100;
        int mes = inverso % 100;

        bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
        int dias_no_mes;
        if (mes == 2) {
            dias_no_mes = bissexto ? 29 : 28;
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            dias_no_mes = 30;
        } else {
            dias_no_mes = 31;
        }

        if (mes >= 1 && mes <= 12 && dia >= 1 && dia <= dias_no_mes) {
            printf("%02d/%02d/%d\n", dia, mes, ano);
            total++;
        }
    }
    printf("Datas palíndromas no século: %d\n", total);
    return 0;
}
