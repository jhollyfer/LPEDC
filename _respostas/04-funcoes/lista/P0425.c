// Lista · Módulo 04 · Funções e modularização
// Exercício P0425 · ★★★ · O prazo de 10 dias úteis

#include <stdbool.h>
#include <stdio.h>

int dias_no_mes(int mes, int ano) {
    bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
    switch (mes) {
        case 2:
            return bissexto ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

int proximo_dia(int data) {
    int ano = data / 10000, mes = data / 100 % 100, dia = data % 100;
    dia++;
    if (dia > dias_no_mes(mes, ano)) {
        dia = 1;
        mes++;
        if (mes > 12) {
            mes = 1;
            ano++;
        }
    }
    return ano * 10000 + mes * 100 + dia;
}

int dia_semana(int data) {
    int ano = data / 10000, mes = data / 100 % 100, dia = data % 100;
    int a = (14 - mes) / 12;
    int y = ano - a;
    int m = mes + 12 * a - 2;
    return (dia + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;
}

bool feriado(int data) {
    switch (data % 10000) { // mmdd
        case 101: case 421: case 501: case 907: case 1012:
        case 1102: case 1115: case 1120: case 1225:
            return true;
        default:
            return false;
    }
}

void mostrar(int data) {
    printf("%02d/%02d/%d\n", data % 100, data / 100 % 100, data / 10000);
}

int main(void) {
    int data = 20261119;
    int uteis = 0, fins = 0, feriados = 0;

    printf("Protocolo: ");
    mostrar(data);
    while (uteis < 10) {
        data = proximo_dia(data);
        int semana = dia_semana(data);
        if (semana == 0 || semana == 6) {
            fins++;
        } else if (feriado(data)) {
            feriados++;
        } else {
            uteis++;
        }
    }
    printf("Prazo final: ");
    mostrar(data);
    printf("Pulados: %d dia(s) de fim de semana e %d feriado(s)\n", fins, feriados);
    return 0;
}
