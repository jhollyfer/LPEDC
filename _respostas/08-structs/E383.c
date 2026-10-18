// 0064 · Struct
// Exercício E383 · ★★★

#include <stdbool.h>
#include <stdio.h>

struct data {
    int dia;
    int mes;
    int ano;
};

bool bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
}

int dias_no_mes(int mes, int ano) {
    const int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && bissexto(ano)) {
        return 29;
    }
    return dias[mes - 1];
}

struct data dia_seguinte(struct data d) {
    d.dia++; // d é uma cópia: mexer nela não muda a data de quem chamou
    if (d.dia > dias_no_mes(d.mes, d.ano)) {
        d.dia = 1;
        d.mes++;
        if (d.mes > 12) {
            d.mes = 1;
            d.ano++;
        }
    }
    return d;
}

int comparar(struct data a, struct data b) {
    if (a.ano != b.ano) return a.ano < b.ano ? -1 : 1;
    if (a.mes != b.mes) return a.mes < b.mes ? -1 : 1;
    if (a.dia != b.dia) return a.dia < b.dia ? -1 : 1;
    return 0;
}

void mostrar(struct data d) {
    printf("%02d/%02d/%d", d.dia, d.mes, d.ano);
}

void testar_seguinte(struct data d) {
    mostrar(d);
    printf(" -> ");
    mostrar(dia_seguinte(d));
    printf("\n");
}

int main(void) {
    testar_seguinte((struct data){28, 2, 2024});
    testar_seguinte((struct data){28, 2, 2025});
    testar_seguinte((struct data){31, 12, 2025});

    struct data a = {15, 3, 2025};
    struct data b = {2, 11, 2025};
    mostrar(a);
    int c = comparar(a, b);
    printf(" %s ", c < 0 ? "vem antes de" : c > 0 ? "vem depois de" : "é igual a");
    mostrar(b);
    printf("\n");
    return 0;
}
