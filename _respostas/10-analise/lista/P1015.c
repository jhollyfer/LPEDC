// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1015 · ★★☆ · O TAD Data e a contagem para a prova

#include <stdio.h>
#include <stdlib.h>

// ---- data.h ---------------------------------------------------------------
typedef struct data Data;

Data *data_cria(int dia, int mes, int ano); // NULL se a data não existe
Data *data_seguinte(const Data *d);
int data_compara(const Data *a, const Data *b);
int data_dias_entre(const Data *a, const Data *b); // a <= b
void data_imprime(const Data *d);
void data_libera(Data *d);

// ---- data.c ---------------------------------------------------------------
// Invariante: (dia, mes, ano) é uma data que existe.
struct data {
    int dia, mes, ano;
};

static int bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
}

static int dias_no_mes(int mes, int ano) {
    int dias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && bissexto(ano)) {
        return 29;
    }
    return dias[mes - 1];
}

Data *data_cria(int dia, int mes, int ano) {
    if (mes < 1 || mes > 12 || dia < 1 || dia > dias_no_mes(mes, ano)) {
        return NULL;
    }
    Data *d = malloc(sizeof *d);
    if (d != NULL) {
        d->dia = dia;
        d->mes = mes;
        d->ano = ano;
    }
    return d;
}

Data *data_seguinte(const Data *d) {
    int dia = d->dia + 1, mes = d->mes, ano = d->ano;
    if (dia > dias_no_mes(mes, ano)) {
        dia = 1;
        mes++;
        if (mes > 12) {
            mes = 1;
            ano++;
        }
    }
    return data_cria(dia, mes, ano);
}

int data_compara(const Data *a, const Data *b) {
    if (a->ano != b->ano) {
        return a->ano - b->ano;
    }
    if (a->mes != b->mes) {
        return a->mes - b->mes;
    }
    return a->dia - b->dia;
}

int data_dias_entre(const Data *a, const Data *b) {
    int dias = 0;
    Data *atual = data_cria(a->dia, a->mes, a->ano);
    while (atual != NULL && data_compara(atual, b) < 0) {
        Data *prox = data_seguinte(atual);
        data_libera(atual);
        atual = prox;
        dias++;
    }
    data_libera(atual);
    return dias;
}

void data_imprime(const Data *d) {
    printf("%02d/%02d/%04d", d->dia, d->mes, d->ano);
}

void data_libera(Data *d) {
    free(d);
}

// ---- cliente --------------------------------------------------------------
void mostra_seguinte(int dia, int mes, int ano) {
    Data *d = data_cria(dia, mes, ano);
    if (d == NULL) {
        return;
    }
    Data *s = data_seguinte(d);
    if (s != NULL) {
        printf("Depois de ");
        data_imprime(d);
        printf(" vem ");
        data_imprime(s);
        printf("\n");
    }
    data_libera(s);
    data_libera(d);
}

int main(void) {
    mostra_seguinte(28, 2, 2024);
    mostra_seguinte(28, 2, 2025);
    mostra_seguinte(31, 12, 2026);

    Data *invalida = data_cria(30, 2, 2025);
    if (invalida == NULL) {
        printf("30/02/2025: data inválida\n");
    }
    data_libera(invalida);

    Data *inscricao = data_cria(9, 11, 2026);
    Data *prova = data_cria(27, 11, 2026);
    if (inscricao != NULL && prova != NULL) {
        printf("De ");
        data_imprime(inscricao);
        printf(" até ");
        data_imprime(prova);
        printf(": %d dias\n", data_dias_entre(inscricao, prova));
    }
    data_libera(inscricao);
    data_libera(prova);
    return 0;
}
