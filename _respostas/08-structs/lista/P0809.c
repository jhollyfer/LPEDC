// Lista · Módulo 08 · Tipos compostos
// Exercício P0809 · ★☆☆ · O mais velho da família

#include <stdio.h>

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char nome[20];
    Data nascimento;
} Pessoa;

int compara_data(Data a, Data b) {
    if (a.ano != b.ano) {
        return a.ano - b.ano;
    }
    if (a.mes != b.mes) {
        return a.mes - b.mes;
    }
    return a.dia - b.dia;
}

int main(void) {
    Pessoa familia[5] = {{"Vó Nazaré", {12, 3, 1941}}, {"Tio Edu", {30, 11, 1968}},
                         {"Mãe", {5, 3, 1972}}, {"Lucas", {19, 7, 2001}},
                         {"Bia", {2, 1, 2009}}};
    int velho = 0, novo = 0;

    for (int i = 1; i < 5; i++) {
        if (compara_data(familia[i].nascimento, familia[velho].nascimento) < 0) {
            velho = i;
        }
        if (compara_data(familia[i].nascimento, familia[novo].nascimento) > 0) {
            novo = i;
        }
    }
    printf("Mais velho: %s (%d)\n", familia[velho].nome, familia[velho].nascimento.ano);
    printf("Mais novo: %s (%d)\n", familia[novo].nome, familia[novo].nascimento.ano);
    printf("Aniversário em março:");
    for (int i = 0; i < 5; i++) {
        if (familia[i].nascimento.mes == 3) {
            printf(" %s (dia %d)", familia[i].nome, familia[i].nascimento.dia);
        }
    }
    printf("\n");
    return 0;
}
