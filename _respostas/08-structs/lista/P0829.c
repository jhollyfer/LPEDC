// Lista · Módulo 08 · Tipos compostos
// Exercício P0829 · ★★★ · A multa da biblioteca

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char titulo[32];
    char leitor[16];
    Data saida, devolucao;
} Emprestimo;

bool bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
}

int dias_no_mes(int mes, int ano) {
    switch (mes) {
    case 2:
        return bissexto(ano) ? 29 : 28;
    case 4: case 6: case 9: case 11:
        return 30;
    default:
        return 31;
    }
}

long dias_desde_inicio(Data d) {
    long total = 0;
    for (int a = 1; a < d.ano; a++) {
        total += bissexto(a) ? 366 : 365;
    }
    for (int m = 1; m < d.mes; m++) {
        total += dias_no_mes(m, d.ano);
    }
    return total + d.dia;
}

int main(void) {
    Emprestimo v[4] = {
        {"Dois Irmãos", "Clarice", {3, 11, 2026}, {12, 11, 2026}},
        {"Vidas Secas", "Otávio", {20, 12, 2025}, {10, 1, 2026}},
        {"Macunaíma", "Fabiana", {1, 3, 2026}, {2, 4, 2026}},
        {"O Cortiço", "Ramon", {20, 2, 2028}, {12, 3, 2028}},
    };
    double total = 0;

    for (int i = 0; i < 4; i++) {
        const Emprestimo *e = &v[i];
        long dias = dias_desde_inicio(e->devolucao) - dias_desde_inicio(e->saida);
        long atraso = dias > 14 ? dias - 14 : 0;
        double multa = atraso * 1.50;
        total += multa;
        printf("%s (%s): %ld dias, atraso %ld, multa R$ %.2f\n", e->titulo, e->leitor,
               dias, atraso, multa);
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}
