// Lista · Módulo 02 · Decisões
// Exercício P0221 · ★★★ · Que dia do ano é a prova

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int dia = 27, mes = 11, ano = 2026;
    bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
    int total = dia;

    switch (mes - 1) { // soma os meses que já passaram, do último para janeiro
        case 11:
            total += 30; // novembro
            // fall through
        case 10:
            total += 31; // outubro
            // fall through
        case 9:
            total += 30; // setembro
            // fall through
        case 8:
            total += 31; // agosto
            // fall through
        case 7:
            total += 31; // julho
            // fall through
        case 6:
            total += 30; // junho
            // fall through
        case 5:
            total += 31; // maio
            // fall through
        case 4:
            total += 30; // abril
            // fall through
        case 3:
            total += 31; // março
            // fall through
        case 2:
            total += bissexto ? 29 : 28; // fevereiro
            // fall through
        case 1:
            total += 31; // janeiro
            break;
        default: // mês 1: nenhum mês antes
            break;
    }

    int dias_no_ano = bissexto ? 366 : 365;
    printf("%02d/%02d/%d é o dia %d do ano\n", dia, mes, ano, total);
    printf("Faltam %d dias para o ano acabar\n", dias_no_ano - total);
    return 0;
}
